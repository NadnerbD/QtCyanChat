/********************************************************************************
** Form generated from reading UI file 'cyanchat.ui'
**
** Created: Sun Mar 28 22:58:31 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYANCHAT_H
#define UI_CYANCHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CyanChat
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionOptionsDialog;
    QAction *actionQuit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *controlBar;
    QLineEdit *nameBox;
    QPushButton *loginButton;
    QPushButton *ignoreButton;
    QSpacerItem *horizontalSpacer;
    QLineEdit *chatBox;
    QTabWidget *tabWidget;
    QWidget *mainChat;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QTextBrowser *mainText;
    QListWidget *userList;
    QWidget *pmChat;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *pmTopBar;
    QLabel *pmTitle;
    QToolButton *closeButton;
    QTextBrowser *pmText;
    QLineEdit *pmBox;
    QMenuBar *menubar;
    QMenu *menuChat;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CyanChat)
    {
        if (CyanChat->objectName().isEmpty())
            CyanChat->setObjectName(QString::fromUtf8("CyanChat"));
        CyanChat->resize(747, 481);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/cyanchat32.png"), QSize(), QIcon::Normal, QIcon::Off);
        CyanChat->setWindowIcon(icon);
        CyanChat->setStyleSheet(QString::fromUtf8("QLineEdit, QTextBrowser, QListView { background: black; color: white; }\n"
"QLineEdit:disabled { background: gray; color: black; }"));
        actionConnect = new QAction(CyanChat);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        actionDisconnect = new QAction(CyanChat);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        actionOptionsDialog = new QAction(CyanChat);
        actionOptionsDialog->setObjectName(QString::fromUtf8("actionOptionsDialog"));
        actionQuit = new QAction(CyanChat);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(CyanChat);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        controlBar = new QHBoxLayout();
        controlBar->setObjectName(QString::fromUtf8("controlBar"));
        nameBox = new QLineEdit(centralwidget);
        nameBox->setObjectName(QString::fromUtf8("nameBox"));
        nameBox->setMaximumSize(QSize(247, 16777215));

        controlBar->addWidget(nameBox);

        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        controlBar->addWidget(loginButton);

        ignoreButton = new QPushButton(centralwidget);
        ignoreButton->setObjectName(QString::fromUtf8("ignoreButton"));

        controlBar->addWidget(ignoreButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        controlBar->addItem(horizontalSpacer);


        verticalLayout->addLayout(controlBar);

        chatBox = new QLineEdit(centralwidget);
        chatBox->setObjectName(QString::fromUtf8("chatBox"));

        verticalLayout->addWidget(chatBox);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setTabPosition(QTabWidget::South);
        mainChat = new QWidget();
        mainChat->setObjectName(QString::fromUtf8("mainChat"));
        horizontalLayout = new QHBoxLayout(mainChat);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(mainChat);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        mainText = new QTextBrowser(splitter);
        mainText->setObjectName(QString::fromUtf8("mainText"));
        mainText->setAcceptDrops(false);
        mainText->setStyleSheet(QString::fromUtf8(""));
        mainText->setOpenExternalLinks(true);
        mainText->setOpenLinks(true);
        splitter->addWidget(mainText);
        userList = new QListWidget(splitter);
        userList->setObjectName(QString::fromUtf8("userList"));
        userList->setMaximumSize(QSize(16777215, 16777215));
        userList->setBaseSize(QSize(150, 0));
        splitter->addWidget(userList);

        horizontalLayout->addWidget(splitter);

        tabWidget->addTab(mainChat, QString());
        pmChat = new QWidget();
        pmChat->setObjectName(QString::fromUtf8("pmChat"));
        verticalLayout_2 = new QVBoxLayout(pmChat);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pmTopBar = new QHBoxLayout();
        pmTopBar->setObjectName(QString::fromUtf8("pmTopBar"));
        pmTitle = new QLabel(pmChat);
        pmTitle->setObjectName(QString::fromUtf8("pmTitle"));

        pmTopBar->addWidget(pmTitle);

        closeButton = new QToolButton(pmChat);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        pmTopBar->addWidget(closeButton);


        verticalLayout_2->addLayout(pmTopBar);

        pmText = new QTextBrowser(pmChat);
        pmText->setObjectName(QString::fromUtf8("pmText"));
        pmText->setOpenExternalLinks(true);

        verticalLayout_2->addWidget(pmText);

        pmBox = new QLineEdit(pmChat);
        pmBox->setObjectName(QString::fromUtf8("pmBox"));

        verticalLayout_2->addWidget(pmBox);

        tabWidget->addTab(pmChat, QString());

        verticalLayout->addWidget(tabWidget);

        CyanChat->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CyanChat);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 747, 21));
        menuChat = new QMenu(menubar);
        menuChat->setObjectName(QString::fromUtf8("menuChat"));
        CyanChat->setMenuBar(menubar);
        statusbar = new QStatusBar(CyanChat);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CyanChat->setStatusBar(statusbar);

        menubar->addAction(menuChat->menuAction());
        menuChat->addAction(actionConnect);
        menuChat->addAction(actionDisconnect);
        menuChat->addSeparator();
        menuChat->addAction(actionOptionsDialog);
        menuChat->addSeparator();
        menuChat->addAction(actionQuit);

        retranslateUi(CyanChat);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CyanChat);
    } // setupUi

    void retranslateUi(QMainWindow *CyanChat)
    {
        CyanChat->setWindowTitle(QApplication::translate("CyanChat", "CyanChat", 0, QApplication::UnicodeUTF8));
        actionConnect->setText(QApplication::translate("CyanChat", "Connect", 0, QApplication::UnicodeUTF8));
        actionDisconnect->setText(QApplication::translate("CyanChat", "Disconnect", 0, QApplication::UnicodeUTF8));
        actionOptionsDialog->setText(QApplication::translate("CyanChat", "Options", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("CyanChat", "Quit", 0, QApplication::UnicodeUTF8));
        nameBox->setText(QString());
        loginButton->setText(QApplication::translate("CyanChat", "Login", 0, QApplication::UnicodeUTF8));
        ignoreButton->setText(QApplication::translate("CyanChat", "Ignore", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(mainChat), QApplication::translate("CyanChat", "CyanChat", 0, QApplication::UnicodeUTF8));
        pmTitle->setText(QApplication::translate("CyanChat", "Private chat with [Name]", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("CyanChat", "Close", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(pmChat), QApplication::translate("CyanChat", "Name", 0, QApplication::UnicodeUTF8));
        menuChat->setTitle(QApplication::translate("CyanChat", "Chat", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CyanChat: public Ui_CyanChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYANCHAT_H
