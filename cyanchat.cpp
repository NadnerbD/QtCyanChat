#include "pmwidget.h"
#include "cyanchat.h"
#include "options.h"
#include "ui_cyanchat.h"

#ifdef Q_WS_WIN
QString CyanChat::verString = "qt_cc " + QString(CC_VERSION) + " (NadCC) Windows build";
#endif
#ifdef Q_WS_X11
QString CyanChat::verString = "qt_cc " + QString(CC_VERSION) + " (NadCC) Linux build";
#endif
#ifdef Q_WS_MACX
QString CyanChat::verString = "qt_cc " + QString(CC_VERSION) + " (NadCC) Mac OSX build";
#endif


CyanChat::CyanChat(QWidget *parent) : QMainWindow(parent), reconnecting(false), settings("cyan.com", "CyanChat"), ui(new Ui::CyanChat), optionsDialog(NULL), userIPTable("UserIPTable.log") {
    ui->setupUi(this);
    // remove the dummy pm tab
    ui->tabWidget->removeTab(1);
    // connect all the ui stuffs
    connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(loginSlot()));
    connect(ui->nameBox, SIGNAL(returnPressed()), this, SLOT(loginSlot()));
    connect(ui->chatBox, SIGNAL(returnPressed()), this, SLOT(chatSlot()));
    connect(ui->userList, SIGNAL(activated(QModelIndex)), this, SLOT(openPmSlot()));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));
    connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(netConnect()));
    connect(ui->actionDisconnect, SIGNAL(triggered()), this, SLOT(netDisconnect()));
    connect(ui->actionOptionsDialog, SIGNAL(triggered()), this, SLOT(showOptions()));
    connect(ui->actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(ui->splitter, SIGNAL(splitterMoved(int,int)), this, SLOT(saveSplitterState(int,int)));
    // create keyboard shortcuts
    QShortcut* shortcut = new QShortcut(QKeySequence("Ctrl+N"), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(renameSlot()));
    shortcut = new QShortcut(QKeySequence("Ctrl+Tab"), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(nextTabSlot()));
    shortcut = new QShortcut(QKeySequence("Ctrl+W"), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(closeCurrentTab()));
    // init vars
    name_reg = false;
    // at some point, we'll read a config file here
    readSettings();
    // set up the tray icon
    QAction* restoreAction = new QAction("&Restore", this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showWindowSlot()));
    QAction* minimizeAction = new QAction("Mi&nimize", this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hideWindowSlot()));
    QAction* quitAction = new QAction("&Quit", this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    QMenu* trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/cyanchat32.png"));
    trayIcon->setContextMenu(trayIconMenu);
    if(alwaysShowTray)
        trayIcon->show();
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    connect(this, SIGNAL(hideWindowSignal()), this, SLOT(hideWindowSlot()), Qt::QueuedConnection);
    // create the userlist actions
    QAction* PMAction = new QAction("&PM", this);
    connect(PMAction, SIGNAL(triggered()), this, SLOT(openPmSlot()));
    PMAction->setShortcut(QKeySequence("Ctrl+P"));
    QAction* ignoreAction = new QAction("&Ignore", this);
    connect(ignoreAction, SIGNAL(triggered()), this, SLOT(ignoreSlot()));
    ignoreAction->setShortcut(QKeySequence("Ctrl+I"));
    QAction* showAddressAction = new QAction("Show &Address", this);
    connect(showAddressAction, SIGNAL(triggered()), this, SLOT(showAddressSlot()));
    showAddressAction->setShortcut(QKeySequence("Ctrl+A"));
    QAction* requestVersionAction = new QAction("Request &Version", this);
    connect(requestVersionAction, SIGNAL(triggered()), this, SLOT(requestVersionSlot()));
    requestVersionAction->setShortcut(QKeySequence("Ctrl+V"));
    QAction* showNames = new QAction("&Show Names", this);
    connect(showNames, SIGNAL(triggered()), this, SLOT(showNamesSlot()));
    showNames->setShortcut(QKeySequence("Ctrl+S"));
    QAction* setOrigName = new QAction("Set &Original Name", this);
    connect(setOrigName, SIGNAL(triggered()), this, SLOT(setOrigNameSlot()));
    setOrigName->setShortcut(QKeySequence("Ctrl+O"));
    ui->userList->addAction(PMAction);
    ui->userList->addAction(ignoreAction);
    ui->userList->addAction(showAddressAction);
    ui->userList->addAction(requestVersionAction);
    ui->userList->addAction(showNames);
    ui->userList->addAction(setOrigName);
    // set up the userlist context menu, the purpose of this is to
    // prevent the menu from showing when no item is selected
    ui->userList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->userList, SIGNAL(customContextMenuRequested(QPoint)), SLOT(showUserListContextMenu(QPoint)));
    // prepare the connection
    sock = new QTcpSocket(this);
    connect(sock, SIGNAL(readyRead()), this, SLOT(recvData()));
    connect(sock, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(sockError()));
    connect(sock, SIGNAL(connected()), this, SLOT(onConnect()));
    // start the ping timer
    QTimer* pingTimer = new QTimer(this);
    connect(pingTimer, SIGNAL(timeout()), this, SLOT(pingSlot()));
    pingTimer->start(30000);
    int len = qApp->argc();
    char** args = qApp->argv();
    for(int i = 0; i < len; i++) {
        if((args[i] == QString("-h"))&&(i + 1 < len)) {
            host = args[i + 1];
        }
        if((args[i] == QString("-p"))&&(i + 1 < len)) {
            port = QString(args[i + 1]).toInt();
        }
        if((args[i] == QString("-n"))&&(i + 1 < len)) {
            ui->nameBox->setText(QString(args[i + 1]));
            reconnecting = true; // using this option forces set name on connect
        }
        if(args[i] == QString("-b")) {
            highlightLocalName = true;
        }
    }
    // start the connection
    netConnect();
}

// hack class to allow me to change the tab color without subclassing the tab widget. :P
class UsableTabWidget : QTabWidget {
    Q_OBJECT
public:
    QTabBar* tabBar() {
	return QTabWidget::tabBar();
    }
};

CyanChat::~CyanChat() {
    delete ui;
}

void CyanChat::applyFontSize() {
    // apply fontSize setting (only done at startup, pending issue with resetting fontsize)
    QFont theFont = font();
    if(!fontSize) {
        fontSize = theFont.pointSize();
    }else{
        theFont.setPointSize(fontSize);
        qApp->setFont(theFont);
    }
}

void CyanChat::readSettings() {
    // General CyanChat settings
    host = settings.value("Host", "cho.cyan.com").toString();
    port = settings.value("Port", 1812).toInt();
    defaultName = settings.value("Nick").toString();
    // fill in box
    ui->nameBox->setText(defaultName);
    settings.beginGroup("QtCyanChat");
    // QtCC Specific settings
    setNameOnConnect = settings.value("SetNameOnConnect", false).toBool();
    connectOnStartup = settings.value("ConnectOnStartup", true).toBool();
    highlightLocalName = settings.value("HighlightLocalName", false).toBool();
    alwaysShowTray = settings.value("AlwaysShowTray", true).toBool();
    minimizeToTray = settings.value("MinimizeToTray", true).toBool();
    reformatActions = settings.value("ReformatActions", false).toBool();
    autoCreatePMTabs = settings.value("AutoCreatePMTabs", true).toBool();
    displayTimestamps = settings.value("DisplayTimestamps", false).toBool();
    timestampFormat = settings.value("TimestampFormat", "[hh:mm]").toString();
    writeHTMLLog = settings.value("WriteHTMLLog", false).toBool();
    writePlainLog = settings.value("WritePlainLog", false).toBool();
    logClientAnnounce = settings.value("LogClientAnnounce", false).toBool();
    logTimestamps = settings.value("LogTimestamps", true).toBool();
    plainLog = settings.value("PlainLog", "CCChatLog.log").toString();
    HTMLLog = settings.value("HTMLLog", "CCChatLog.html").toString();
    fontSize = settings.value("FontSize", 0).toInt();
    showOrigNames = settings.value("ShowOrigNames", false).toBool();
    if(settings.contains("SplitterState")) {
        ui->splitter->restoreState(settings.value("SplitterState").toByteArray());
    }else{
        QList<int> sizes;
        sizes.append(500);
        sizes.append(150);
        ui->splitter->setSizes(sizes);
    }
    if(settings.contains("Geometry")) {
        restoreGeometry(settings.value("Geometry").toByteArray());
    }
    settings.endGroup();
    applyFontSize();
}

void CyanChat::writeSettings() {
    // write the settings data
    settings.setValue("Host", host);
    settings.setValue("Port", port);
    settings.setValue("Nick", defaultName);
    settings.beginGroup("QtCyanChat");
    settings.setValue("SetNameOnConnect", setNameOnConnect);
    settings.setValue("ConnectOnStartup", connectOnStartup);
    settings.setValue("HighlightLocalName", highlightLocalName);
    settings.setValue("AlwaysShowTray", alwaysShowTray);
    settings.setValue("MinimizeToTray", minimizeToTray);
    settings.setValue("ReformatActions", reformatActions);
    settings.setValue("AutoCreatePMTabs", autoCreatePMTabs);
    settings.setValue("DisplayTimestamps", displayTimestamps);
    settings.setValue("TimestampFormat", timestampFormat);
    settings.setValue("WriteHTMLLog", writeHTMLLog);
    settings.setValue("WritePlainLog", writePlainLog);
    settings.setValue("LogClientAnnounce", logClientAnnounce);
    settings.setValue("LogTimestamps", logTimestamps);
    settings.setValue("PlainLog", plainLog);
    settings.setValue("HTMLLog", HTMLLog);
    settings.setValue("FontSize", fontSize);
    settings.setValue("ShowOrigNames", showOrigNames);
    // QtCC Specific settings
    settings.endGroup();
}

void CyanChat::saveSplitterState(int, int) {
    settings.setValue("QtCyanChat/SplitterState", ui->splitter->saveState());
}

void CyanChat::moveEvent(QMoveEvent*) {
    settings.setValue("QtCyanChat/Geometry", saveGeometry());
}

void CyanChat::resizeEvent(QResizeEvent*) {
    settings.setValue("QtCyanChat/Geometry", saveGeometry());
}

void CyanChat::netConnect() {
    if(sock->isOpen())
	netDisconnect();
    addChatLine(ui->mainText, User("3ChatClient"), Msg(verString, 1));
    addChatLine(ui->mainText, User("3ChatClient"), Msg("connecting to: " + host + ":" + QString::number(port), 1));
    sock->connectToHost(host, port, QIODevice::ReadWrite);
}

void CyanChat::onConnect() {
    sock->write("40|1\n");
    if(setNameOnConnect || reconnecting) {
        name(ui->nameBox->text());
    }
}

void CyanChat::netDisconnect() {
    if(sock->isOpen())
	sock->close();
    name_reg = false;
    ui->loginButton->setText("Login");
    ui->nameBox->setEnabled(true);
}

void CyanChat::showOptions() {
    if(!optionsDialog) {
	optionsDialog = new Options(this);
	connect(optionsDialog, SIGNAL(finished(int)), this, SLOT(optionsFinished(int)));
	optionsDialog->show();
    }
}

void CyanChat::showUserListContextMenu(QPoint point) {
    QListWidgetItem* item = ui->userList->itemAt(point);
    if(!item)
        return;
    // generate the context menu, using the same actions that the userList has
    QMenu* menu = new QMenu(this);
    menu->addActions(ui->userList->actions());
    menu->popup(ui->userList->mapToGlobal(point));
}

void CyanChat::optionsFinished(int) {
    optionsDialog = NULL;
}

void CyanChat::iconActivated(QSystemTrayIcon::ActivationReason reason) {
    if(reason == QSystemTrayIcon::DoubleClick) {
	if(isMinimized()) {
	    showWindowSlot();
	}else{
	    emit hideWindowSignal();
	}
    }
}

void CyanChat::changeEvent(QEvent* event) {
    if(event->type() == QEvent::WindowStateChange) {
	if(isMinimized()) {
	    emit hideWindowSignal();
	}
    }else if(event->type() == QEvent::ActivationChange){
	if(isActiveWindow()) {
	    trayIcon->setIcon(QIcon(":/cyanchat32.png"));
	}
    }
    QMainWindow::changeEvent(event);
}

void CyanChat::nextTabSlot() {
    ui->tabWidget->setCurrentIndex((ui->tabWidget->currentIndex() + 1) % ui->tabWidget->count());
}

void CyanChat::closeCurrentTab() {
    int index = ui->tabWidget->currentIndex();
    if(index != 0)
	ui->tabWidget->removeTab(index);
}

void CyanChat::showAddressSlot() {
    // this is such a hack. -_-
    QList<QListWidgetItem*> list = ui->userList->selectedItems();
    if(!list.isEmpty()) {
	User user = User(list.first()->toolTip());
	addChatLine(ui->mainText, User("3ChatClient"), Msg("[" + user.name + "] is from address " + user.addr, 1));
    }
}

void CyanChat::requestVersionSlot() {
    // this is such a hack. -_-
    QList<QListWidgetItem*> list = ui->userList->selectedItems();
    if(!list.isEmpty())
	pm(User(list.first()->toolTip()), "!version");
}

void CyanChat::showNamesSlot() {
    // this is such a hack. -_-
    QList<QListWidgetItem*> list = ui->userList->selectedItems();
    if(!list.isEmpty()) {
	User user = User(list.first()->toolTip());
	QStringList namesList = userIPTable.getAllNames(user.addr);
	addChatLine(ui->mainText, User("3ChatClient"), Msg("[" + user.name + "] from address " + user.addr + " has used the names: " + namesList.join(", "), 1));
    }
}

void CyanChat::setOrigNameSlot() {
    // this is such a hack. -_-
    QList<QListWidgetItem*> list = ui->userList->selectedItems();
    if(!list.isEmpty()) {
	User user = User(list.first()->toolTip());
        userIPTable.setRealName(user.addr, user.name);
        refreshUserListSlot();
    }
}

void CyanChat::refreshUserListSlot() {
    ui->userList->clear();
    ui->userList->setSortingEnabled(false);
    foreach(User user, userList) {
        if(!user.isIgnored(ignoreList)) {
            QListWidgetItem *item = new QListWidgetItem(ui->userList);
            QString realName = userIPTable.getRealName(user.addr, user.name);
            if(realName != user.name && showOrigNames)
                item->setText(user.name + ", (" + realName + ")");
            else
                item->setText(user.name);
            item->setForeground(QBrush(user.color()));
            item->setToolTip(user.toString());
        }
    }
}

void CyanChat::showWindowSlot() {
    show();
    showNormal();
    activateWindow();
    if(!alwaysShowTray)
	trayIcon->hide();
}

void CyanChat::hideWindowSlot() {
    showMinimized();
    if(minimizeToTray) {
	hide();
	trayIcon->show();
    }
}

void CyanChat::setTrayVis(bool vis) {
    if(vis)
	trayIcon->show();
    else
	trayIcon->hide();
}

void CyanChat::pingSlot() {
    if(name_reg)
	sendLine("20||^1ping");
}

void CyanChat::tabChanged(int num) {
    ui->chatBox->setDisabled(num != 0);
    if(num == 0)
	ui->chatBox->setFocus();
    else
	((PMWidget*)ui->tabWidget->currentWidget())->pmBox->setFocus();
    ((UsableTabWidget*)ui->tabWidget)->tabBar()->setTabTextColor(num, palette().color(QPalette::ButtonText));
}

void CyanChat::sendLine(QString line) {
    line += "\n";
    sock->write(line.toUtf8());
}

void CyanChat::name(QString name) {
    name = name.split("\n")[0];
    if(name.count() > 0 && sock->isOpen()) {
	sendLine("10|" + name);
	lastAttemptedName = name;
    }
}

void CyanChat::ignore(User user) {
    ignoreList.append(user);
    if(name_reg)
	sendLine("70|" + user.fullName());
    addChatLine(ui->mainText, User("3ChatClient"), Msg("You are now ignoring [" + user.name + "] and all their aliases from address " + user.addr, 1));

}

void CyanChat::pm(User target, QString msg) {
    if(name_reg)
        sendLine("20|" + target.fullName() + "|^1" + msg);
}

void CyanChat::chat(QString msg) {
    if(name_reg)
	sendLine("30|^1" + msg);
}

void CyanChat::loginSlot() {
    if(name_reg) {
	sendLine("15");
	name_reg = false;
	ui->loginButton->setText("Login");
	ui->nameBox->setEnabled(true);
    }else{
	name(ui->nameBox->text());
    }
}

void CyanChat::renameSlot() {
    name(ui->chatBox->text());
    ui->chatBox->clear();
}

void CyanChat::ignoreSlot() {
    // this is such a hack. -_-
    QList<QListWidgetItem*> list = ui->userList->selectedItems();
    if(!list.isEmpty())
	ignore(User(list.first()->toolTip()));
}

void CyanChat::chatSlot() {
    QStringList lines = ui->chatBox->text().split("\n");
    foreach(QString line, lines) {
        QStringList args = line.split(" ");
        if(args.count() > 1 && args[0] == "/nick") {
            args.pop_front();
            name(args.join(" "));
        }else if(name_reg) {
            if(args.count() > 1 && args[0] == "/me") {
                args.pop_front();
                chat("*" + args.join(" ") + "*");
            }else{
                chat(args.join(" "));
            }
        }else{
            name(args.join(" "));
        }
        ui->chatBox->clear();
    }
}

void CyanChat::sockError() {
    addChatLine(ui->mainText, User("3ChatClient"), Msg("Connection error", 1));
    netDisconnect();
    reconnecting = true;
    QTimer::singleShot(5000, this, SLOT(netConnect()));
}

void CyanChat::openPmSlot() {
    // this is such a hack. -_-
    QList<QListWidgetItem*> list = ui->userList->selectedItems();
    if(!list.isEmpty()) {
	new PMWidget(User(list.first()->toolTip()), this, ui->tabWidget);
	ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
    }
}

void CyanChat::closeTabSlot(QWidget* tab) {
    int tabIndex = ui->tabWidget->indexOf(tab);
    ui->tabWidget->removeTab(tabIndex);
}

void CyanChat::recvData() {
    while(sock->canReadLine()) {
	QString line = QString::fromUtf8(sock->readLine());
	QStringList args = line.split("|");
	int command = args[0].toInt();
	args.pop_front();
	Msg message;
	User sender;
	bool foundTab;
	switch(command) {
	    case(40):
		addChatLine(ui->mainText, User("2ChatServer"), Msg(args.join("|").mid(1), 1));
		break;
	    case(21):
		sender.fromString(args[0]);
		if(sender.isIgnored(ignoreList))
		    break;
		args.pop_front();
		message.fromString(args.join("|"));
		if(message.text.mid(0, 8) == "!version") {
		    pm(sender, verString);
		    addChatLine(ui->mainText, User("3ChatClient"), Msg("[" + sender.name + "] Requested version info", 1));
		    break;
		}
		foundTab = false;
		for(int i = 1; i < ui->tabWidget->count(); i++) {
		    PMWidget* tab = (PMWidget*)ui->tabWidget->widget(i);
		    if(tab->target.fullName() == sender.fullName()) {
			tab->pmRecv(sender, message);
			foundTab = true;
			break;
		    }
		}
		if(!foundTab) {
		    if(autoCreatePMTabs) {
			PMWidget* tab = new PMWidget(sender, this, ui->tabWidget);
			ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
			tab->pmRecv(sender, message);
		    }else{
			addChatLine(ui->mainText, sender, message);
		    }
		}
		break;
	    case(31):
		sender.fromString(args[0]);
		if(sender.isIgnored(ignoreList))
		    break;
		args.pop_front();
		message.fromString(args.join("|"));
		addChatLine(ui->mainText, sender, message);
		break;
	    case(35):
                userList.clear();
                while(args.count() > 0) {
                    userList.append(User(args.takeFirst()));
                }
                refreshUserListSlot();
		break;
	    case(11):
		name_reg = true;
                reconnecting = false;
		currentName = lastAttemptedName;
		ui->nameBox->setText(lastAttemptedName);
		ui->nameBox->setDisabled(true);
		ui->loginButton->setText("Logout");
		ui->chatBox->setFocus();
		break;
	    case(10):
		addChatLine(ui->mainText, User("3ChatClient"), Msg("Server rejected name", 1));
                if(reconnecting) {
                    QTimer::singleShot(5000, this, SLOT(loginSlot()));
                }
		break;
	    case(70): // mutual ignore
		sender.fromString(args[0]);
		ignoreList.append(sender);
		break;
	    default:
		addChatLine(ui->mainText, User("2ChatServer"), Msg(line, 1));
	}
    }
}

void CyanChat::insertTextDetectLinks(QTextCursor cursor, QTextCharFormat format, QString text) {
    QStringList words = text.split(" ");
    // Qt's DesktopServices will find a valid handler for any scheme registered with the OS
    // thus, anything of the form <scheme>://<characters> will be marked as a url
    // valid scheme characters and reserved body characters listed in RFC 1738
    // space is not neccesary in the second character class because of the split
    QRegExp rx("[0-9a-zA-Z+-.]+://[^\"<>[\\]^`{}|]+$");
    for(int i = 0; i < words.count(); i++) {
        // if the match starts at 0, then the whole character block is a url
        if(rx.indexIn(words[i]) == 0) {
            cursor.insertHtml("<a href=\"" + words[i] + "\">" + words[i] + "</a>");
	}else{
	    cursor.insertText(words[i], format);
	}
	if(words.count() - 1 != i)
	    cursor.insertText(" ", format);
    }
}

void CyanChat::addChatLine(QTextBrowser* textBrowser, const User& user, const Msg& message) {
    if(logClientAnnounce || !user.addr.isEmpty()) {
        writeHTMLLogLine(user, message);
        writePlainLogLine(user, message);
    }
    QTextCursor cursor = textBrowser->textCursor();
    int tabIndex = ui->tabWidget->indexOf(textBrowser->parentWidget());
    if(tabIndex == -1) tabIndex = 0;
    if(ui->tabWidget->currentIndex() != tabIndex)
	((UsableTabWidget*)ui->tabWidget)->tabBar()->setTabTextColor(tabIndex, QColor(Qt::red));
    if(!isActiveWindow())
	trayIcon->setIcon(QIcon(":/cyanchat32_notify.png"));
    cursor.setPosition(0);
    QTextCharFormat format;
    if(displayTimestamps) {
        QDateTime now = QDateTime::currentDateTime();
        format.setForeground(QBrush(msgColors[0]));
        cursor.insertText(now.toString(timestampFormat + " "), format);
    }
    format.setForeground(QBrush(User::levelColors[2]));
    if(message.flag == kMsgTypeJoin)
	cursor.insertText("\\\\\\\\\\", format);
    else if(message.flag == kMsgTypeLeave)
	cursor.insertText("/////", format);
    else if(message.flag == kMsgTypePM) {
	format.setForeground(QBrush(QColor(255, 0, 255)));
	cursor.insertText("Private message from ", format);
    }
    format.setForeground(QBrush(user.color()));
    if(user.name == currentName && highlightLocalName)
	format.setFontWeight(QFont::Bold);
    if(reformatActions && message.text.startsWith("*") && message.text.endsWith("*")) {
	format.setForeground(QBrush(msgColors[1]));
	cursor.insertText("*" + user.name + " " + message.text.mid(1), format);
    }else{
	cursor.insertText("[" + user.name + "] ", format);
	format.setFontWeight(QFont::Normal);
	if(message.text.startsWith("*") && message.text.endsWith("*"))
	    format.setForeground(QBrush(msgColors[1]));
	else
	    format.setForeground(QBrush(msgColors[0]));
	insertTextDetectLinks(cursor, format, message.text);
    }
    format.setForeground(QBrush(User::levelColors[2]));
    if(message.flag == kMsgTypeJoin)
	cursor.insertText("/////", format);
    else if(message.flag == kMsgTypeLeave)
	cursor.insertText("\\\\\\\\\\", format);
    cursor.insertText("\n");
}

void CyanChat::writePlainLogLine(const User& user, const Msg& message) {
    if(writePlainLog) {
        if(!plainLogFile.isOpen()) {
            // initialize the log file, if neccessary
            plainLogFile.setFileName(plainLog);
            plainLogFile.open(QIODevice::ReadWrite);
            plainLogFile.seek(plainLogFile.size());
        }
        if(logTimestamps) {
            QDateTime now = QDateTime::currentDateTime();
            plainLogFile.write(now.toString(timestampFormat + " ").toUtf8().data());
        }
        if(message.flag == kMsgTypeJoin)
            plainLogFile.write("\\\\\\\\\\");
        else if(message.flag == kMsgTypeLeave)
            plainLogFile.write("/////");
        else if(message.flag == kMsgTypePM)
            plainLogFile.write("Private message from ");
        plainLogFile.write(QString("[" + user.name + "] " + message.text).toUtf8().data());
        if(message.flag == kMsgTypeJoin)
            plainLogFile.write("/////");
        if(message.flag == kMsgTypeLeave)
            plainLogFile.write("\\\\\\\\\\");
        plainLogFile.write("\n");
        plainLogFile.flush();
    }
}

void CyanChat::writeHTMLLogLine(const User& user, const Msg& message) {
    static const char* htmlClassNames[] = {
        "normal",
        "cyane",
        "server",
        "client",
        "guest",
        "msg",
        "action"
    };
    if(writeHTMLLog) {
        if(!HTMLLogFile.isOpen()) {
            // initialize the log file, if neccessary
            HTMLLogFile.setFileName(HTMLLog);
            HTMLLogFile.open(QIODevice::ReadWrite);
            int size = HTMLLogFile.size();
            if(!size) {
                QFile headerFile(":/HtmlHeader.html");
                headerFile.open(QIODevice::ReadOnly);
                HTMLLogFile.write(headerFile.readAll());
                headerFile.close();
                HTMLLogFile.flush();
            }else{
                HTMLLogFile.seek(size);
            }
        }
        if(logTimestamps) {
            QDateTime now = QDateTime::currentDateTime();
            HTMLLogFile.write(QString("<a class='msg'>" + now.toString(timestampFormat) + "</a> ").toUtf8().data());
        }
        if(message.flag == kMsgTypeJoin)
            HTMLLogFile.write("<a class='server'>\\\\\\\\\\</a>");
        else if(message.flag == kMsgTypeLeave)
            HTMLLogFile.write("<a class='server'>/////</a>");
        else if(message.flag == kMsgTypePM)
            HTMLLogFile.write("<a class='pretext'>Private message from</a> ");
        HTMLLogFile.write(QString("<a class=" + QString(htmlClassNames[user.level]) + ">[" + Qt::escape(user.name) + "]</a> ").toUtf8().data());
        int msgClass = 5;
        if(message.text.startsWith("*") && message.text.endsWith("*"))
            msgClass = 6;
        HTMLLogFile.write(QString("<a class=" + QString(htmlClassNames[msgClass]) + ">").toUtf8().data());
        QStringList words = message.text.split(" ");
        for(int i = 0; i < words.count(); i++) {
            if(words[i].startsWith("http://")) {
                HTMLLogFile.write(QString("<a href='" + words[i] + "'>" + Qt::escape(words[i]) + "</a>").toUtf8().data());
            }else{
                HTMLLogFile.write(Qt::escape(words[i]).toUtf8().data());
            }
            if(words.count() - 1 != i)
                HTMLLogFile.write(" ");
        }
        HTMLLogFile.write("</a>");
        if(message.flag == kMsgTypeJoin)
            HTMLLogFile.write("<a class='server'>/////</a>");
        if(message.flag == kMsgTypeLeave)
            HTMLLogFile.write("<a class='server'>\\\\\\\\\\</a>");
        HTMLLogFile.write("<br />\n");
        HTMLLogFile.flush();
    }
}

QColor CyanChat::msgColors[2] = {
    QColor(0xaa, 0xaa, 0xaa),
    QColor(255, 255, 0)
};

CyanChat::Msg::Msg(QString str) {
    fromString(str);
}

CyanChat::Msg::Msg(QString str, int type) {
    text = str;
    text.remove('\r');
    text.remove('\n');
    flag = type;
}

void CyanChat::Msg::fromString(QString str) {
    text = str.mid(2);
    text.remove('\r');
    text.remove('\n');
    flag = str.mid(1, 1).toInt();
}
