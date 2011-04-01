#ifndef CYANCHAT_H
#define CYANCHAT_H

#define CC_VERSION "v1.9.5"

#include <QtGui/QMainWindow>
#include <QSystemTrayIcon>
#include <QTextBrowser>
#include <QModelIndex>
#include <QTcpSocket>
#include <QShortcut>
#include <QSettings>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QFile>

#include "useriptable.h"

namespace Ui {
    class CyanChat;
}

class Options;

class CyanChat : public QMainWindow {
    Q_OBJECT

public:
    CyanChat(QWidget *parent = 0);
    ~CyanChat();

    class User {
    public:
        static QColor levelColors[5];
	QString name;
	QString addr;
	int level;

	User() {}
	User(QString str);
	void fromString(QString str);
	QString toString();
	QString fullName();
	QColor color() const;
	bool isIgnored(QList<User>& ignoreList);
    };

    class Msg {
    public:
	QString text;
	int flag;

	Msg() {}
	Msg(QString str);
	Msg(QString str, int type);
	void fromString(QString str);
    };

    enum {
        kMsgTypePM, kMsgTypeChat, kMsgTypeJoin, kMsgTypeLeave
    };

    void insertTextDetectLinks(QTextCursor cursor, QTextCharFormat format, QString text);
    void addChatLine(QTextBrowser* textBrowser, const User& user, const Msg& message);
    void writePlainLogLine(const User& user, const Msg& message);
    void writeHTMLLogLine(const User& user, const Msg& message);

    // core network output functions
    void name(QString name);
    void ignore(User user);
    void chat(QString msg);
    void pm(User target, QString msg);

    static QString verString;
    static QColor msgColors[2];

    QString currentName;
    // if this is set, it has the effect of setNameOnConnect, without saving as an option
    bool reconnecting;

    // options
    QSettings settings;
    void writeSettings();
    void readSettings();
    void applyFontSize();

    bool minimizeToTray;
    bool alwaysShowTray;
    bool highlightLocalName;
    bool reformatActions;
    bool displayTimestamps;
    QString timestampFormat;
    QString host;
    int port;
    QString defaultName;
    bool connectOnStartup;
    bool setNameOnConnect;
    bool autoCreatePMTabs;
    QString setNameString;
    QString switchTabString;
    QString closeTabString;
    bool writePlainLog;
    bool writeHTMLLog;
    QString plainLog;
    QString HTMLLog;
    bool logClientAnnounce;
    bool logTimestamps;
    int fontSize;
    bool showOrigNames;

public slots:
    void onConnect();
    void loginSlot();
    void renameSlot();
    void ignoreSlot();
    void chatSlot();
    void openPmSlot();
    void showAddressSlot();
    void requestVersionSlot();
    void closeTabSlot(QWidget* tab);
    void closeCurrentTab();
    void tabChanged(int num);
    void recvData();
    void sockError();
    void pingSlot();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void hideWindowSlot();
    void showWindowSlot();
    void nextTabSlot();
    void netConnect();
    void netDisconnect();
    void showOptions();
    void optionsFinished(int value);
    void setTrayVis(bool vis);
    void saveSplitterState(int, int);
    void showUserListContextMenu(QPoint);
    void showNamesSlot();
    void setOrigNameSlot();
    void refreshUserListSlot();

signals:
    void hideWindowSignal();

private:
    Ui::CyanChat *ui;
    QTcpSocket* sock;
    Options* optionsDialog;
    bool name_reg;
    QList<User> userList;
    QList<User> ignoreList;
    QString startName;
    QString lastAttemptedName;
    QSystemTrayIcon* trayIcon;
    QFile HTMLLogFile;
    QFile plainLogFile;
    UserIPTable userIPTable;

    void sendLine(QString line);
    void changeEvent(QEvent* event);

protected:
    void resizeEvent(QResizeEvent*);
    void moveEvent(QMoveEvent*);
};

#endif // CYANCHAT_H
