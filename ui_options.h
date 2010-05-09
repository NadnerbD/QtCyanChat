/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created: Sun Mar 28 22:58:31 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *connectionTab;
    QFormLayout *formLayout;
    QLabel *hostLabel;
    QLineEdit *hostBox;
    QLabel *portLabel;
    QLineEdit *portBox;
    QLabel *nameLabel;
    QLineEdit *nameBox;
    QCheckBox *autoLoginBox;
    QCheckBox *autoConnectBox;
    QWidget *displayTab;
    QFormLayout *formLayout_2;
    QCheckBox *minimizeTrayBox;
    QCheckBox *alwaysShowTrayBox;
    QCheckBox *highlightNickBox;
    QCheckBox *reformatActionsBox;
    QCheckBox *timestampsBox;
    QGroupBox *listOptionsBox;
    QFormLayout *formLayout_4;
    QRadioButton *listOption;
    QRadioButton *treeOption;
    QRadioButton *columnOption;
    QHBoxLayout *horizontalLayout;
    QSpinBox *fontSizeBox;
    QLabel *fontSizeLabel;
    QWidget *shortcutTab;
    QFormLayout *formLayout_6;
    QLabel *setNameLabel;
    QLineEdit *setNameShortcutBox;
    QLabel *switchTabsLabel;
    QLineEdit *switchTabsShortcutBox;
    QLabel *closeTabLabel;
    QLineEdit *closeTabShortcutBox;
    QCheckBox *autoPMBox;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_7;
    QLabel *label_11;
    QLabel *label_15;
    QLabel *label_12;
    QLabel *label_16;
    QLabel *label_13;
    QLabel *label_17;
    QLabel *label_14;
    QLabel *label_18;
    QWidget *logTab;
    QFormLayout *formLayout_5;
    QLabel *label_6;
    QLineEdit *htmlFileBox;
    QLabel *label_7;
    QLineEdit *plainFileBox;
    QCheckBox *plainLogBox;
    QCheckBox *logTimestampsBox;
    QCheckBox *logAnnounceBox;
    QLabel *label_2;
    QLineEdit *timestampFormatBox;
    QCheckBox *htmlLogBox;
    QWidget *aboutTab;
    QFormLayout *formLayout_3;
    QLabel *label;
    QLabel *AboutLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(358, 325);
        verticalLayout = new QVBoxLayout(Options);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(Options);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        connectionTab = new QWidget();
        connectionTab->setObjectName(QString::fromUtf8("connectionTab"));
        formLayout = new QFormLayout(connectionTab);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        hostLabel = new QLabel(connectionTab);
        hostLabel->setObjectName(QString::fromUtf8("hostLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, hostLabel);

        hostBox = new QLineEdit(connectionTab);
        hostBox->setObjectName(QString::fromUtf8("hostBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, hostBox);

        portLabel = new QLabel(connectionTab);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, portLabel);

        portBox = new QLineEdit(connectionTab);
        portBox->setObjectName(QString::fromUtf8("portBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, portBox);

        nameLabel = new QLabel(connectionTab);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, nameLabel);

        nameBox = new QLineEdit(connectionTab);
        nameBox->setObjectName(QString::fromUtf8("nameBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, nameBox);

        autoLoginBox = new QCheckBox(connectionTab);
        autoLoginBox->setObjectName(QString::fromUtf8("autoLoginBox"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, autoLoginBox);

        autoConnectBox = new QCheckBox(connectionTab);
        autoConnectBox->setObjectName(QString::fromUtf8("autoConnectBox"));
        autoConnectBox->setChecked(true);

        formLayout->setWidget(4, QFormLayout::SpanningRole, autoConnectBox);

        tabWidget->addTab(connectionTab, QString());
        displayTab = new QWidget();
        displayTab->setObjectName(QString::fromUtf8("displayTab"));
        formLayout_2 = new QFormLayout(displayTab);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        minimizeTrayBox = new QCheckBox(displayTab);
        minimizeTrayBox->setObjectName(QString::fromUtf8("minimizeTrayBox"));
        minimizeTrayBox->setChecked(true);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, minimizeTrayBox);

        alwaysShowTrayBox = new QCheckBox(displayTab);
        alwaysShowTrayBox->setObjectName(QString::fromUtf8("alwaysShowTrayBox"));
        alwaysShowTrayBox->setChecked(true);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, alwaysShowTrayBox);

        highlightNickBox = new QCheckBox(displayTab);
        highlightNickBox->setObjectName(QString::fromUtf8("highlightNickBox"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, highlightNickBox);

        reformatActionsBox = new QCheckBox(displayTab);
        reformatActionsBox->setObjectName(QString::fromUtf8("reformatActionsBox"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, reformatActionsBox);

        timestampsBox = new QCheckBox(displayTab);
        timestampsBox->setObjectName(QString::fromUtf8("timestampsBox"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, timestampsBox);

        listOptionsBox = new QGroupBox(displayTab);
        listOptionsBox->setObjectName(QString::fromUtf8("listOptionsBox"));
        formLayout_4 = new QFormLayout(listOptionsBox);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        listOption = new QRadioButton(listOptionsBox);
        listOption->setObjectName(QString::fromUtf8("listOption"));
        listOption->setChecked(true);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, listOption);

        treeOption = new QRadioButton(listOptionsBox);
        treeOption->setObjectName(QString::fromUtf8("treeOption"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, treeOption);

        columnOption = new QRadioButton(listOptionsBox);
        columnOption->setObjectName(QString::fromUtf8("columnOption"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, columnOption);


        formLayout_2->setWidget(6, QFormLayout::LabelRole, listOptionsBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fontSizeBox = new QSpinBox(displayTab);
        fontSizeBox->setObjectName(QString::fromUtf8("fontSizeBox"));
        fontSizeBox->setValue(12);

        horizontalLayout->addWidget(fontSizeBox);

        fontSizeLabel = new QLabel(displayTab);
        fontSizeLabel->setObjectName(QString::fromUtf8("fontSizeLabel"));

        horizontalLayout->addWidget(fontSizeLabel);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        tabWidget->addTab(displayTab, QString());
        shortcutTab = new QWidget();
        shortcutTab->setObjectName(QString::fromUtf8("shortcutTab"));
        formLayout_6 = new QFormLayout(shortcutTab);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        setNameLabel = new QLabel(shortcutTab);
        setNameLabel->setObjectName(QString::fromUtf8("setNameLabel"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, setNameLabel);

        setNameShortcutBox = new QLineEdit(shortcutTab);
        setNameShortcutBox->setObjectName(QString::fromUtf8("setNameShortcutBox"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, setNameShortcutBox);

        switchTabsLabel = new QLabel(shortcutTab);
        switchTabsLabel->setObjectName(QString::fromUtf8("switchTabsLabel"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, switchTabsLabel);

        switchTabsShortcutBox = new QLineEdit(shortcutTab);
        switchTabsShortcutBox->setObjectName(QString::fromUtf8("switchTabsShortcutBox"));

        formLayout_6->setWidget(1, QFormLayout::FieldRole, switchTabsShortcutBox);

        closeTabLabel = new QLabel(shortcutTab);
        closeTabLabel->setObjectName(QString::fromUtf8("closeTabLabel"));

        formLayout_6->setWidget(2, QFormLayout::LabelRole, closeTabLabel);

        closeTabShortcutBox = new QLineEdit(shortcutTab);
        closeTabShortcutBox->setObjectName(QString::fromUtf8("closeTabShortcutBox"));

        formLayout_6->setWidget(2, QFormLayout::FieldRole, closeTabShortcutBox);

        autoPMBox = new QCheckBox(shortcutTab);
        autoPMBox->setObjectName(QString::fromUtf8("autoPMBox"));

        formLayout_6->setWidget(3, QFormLayout::SpanningRole, autoPMBox);

        groupBox_2 = new QGroupBox(shortcutTab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_7 = new QFormLayout(groupBox_2);
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_11);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_7->setWidget(0, QFormLayout::FieldRole, label_15);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_7->setWidget(1, QFormLayout::LabelRole, label_12);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout_7->setWidget(1, QFormLayout::FieldRole, label_16);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_7->setWidget(2, QFormLayout::LabelRole, label_13);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_7->setWidget(2, QFormLayout::FieldRole, label_17);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_7->setWidget(3, QFormLayout::LabelRole, label_14);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_7->setWidget(3, QFormLayout::FieldRole, label_18);


        formLayout_6->setWidget(4, QFormLayout::SpanningRole, groupBox_2);

        tabWidget->addTab(shortcutTab, QString());
        logTab = new QWidget();
        logTab->setObjectName(QString::fromUtf8("logTab"));
        formLayout_5 = new QFormLayout(logTab);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_6 = new QLabel(logTab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_6);

        htmlFileBox = new QLineEdit(logTab);
        htmlFileBox->setObjectName(QString::fromUtf8("htmlFileBox"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, htmlFileBox);

        label_7 = new QLabel(logTab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_7);

        plainFileBox = new QLineEdit(logTab);
        plainFileBox->setObjectName(QString::fromUtf8("plainFileBox"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, plainFileBox);

        plainLogBox = new QCheckBox(logTab);
        plainLogBox->setObjectName(QString::fromUtf8("plainLogBox"));

        formLayout_5->setWidget(6, QFormLayout::SpanningRole, plainLogBox);

        logTimestampsBox = new QCheckBox(logTab);
        logTimestampsBox->setObjectName(QString::fromUtf8("logTimestampsBox"));

        formLayout_5->setWidget(7, QFormLayout::SpanningRole, logTimestampsBox);

        logAnnounceBox = new QCheckBox(logTab);
        logAnnounceBox->setObjectName(QString::fromUtf8("logAnnounceBox"));

        formLayout_5->setWidget(8, QFormLayout::SpanningRole, logAnnounceBox);

        label_2 = new QLabel(logTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_2);

        timestampFormatBox = new QLineEdit(logTab);
        timestampFormatBox->setObjectName(QString::fromUtf8("timestampFormatBox"));

        formLayout_5->setWidget(2, QFormLayout::FieldRole, timestampFormatBox);

        htmlLogBox = new QCheckBox(logTab);
        htmlLogBox->setObjectName(QString::fromUtf8("htmlLogBox"));

        formLayout_5->setWidget(5, QFormLayout::SpanningRole, htmlLogBox);

        tabWidget->addTab(logTab, QString());
        aboutTab = new QWidget();
        aboutTab->setObjectName(QString::fromUtf8("aboutTab"));
        formLayout_3 = new QFormLayout(aboutTab);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label = new QLabel(aboutTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/cyanchat32.png")));
        label->setAlignment(Qt::AlignCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        AboutLabel = new QLabel(aboutTab);
        AboutLabel->setObjectName(QString::fromUtf8("AboutLabel"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, AboutLabel);

        tabWidget->addTab(aboutTab, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(Options);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Options);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Options", 0, QApplication::UnicodeUTF8));
        hostLabel->setText(QApplication::translate("Options", "Host", 0, QApplication::UnicodeUTF8));
        hostBox->setText(QApplication::translate("Options", "cho.cyan.com", 0, QApplication::UnicodeUTF8));
        portLabel->setText(QApplication::translate("Options", "Port", 0, QApplication::UnicodeUTF8));
        portBox->setText(QApplication::translate("Options", "1812", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("Options", "Default Name", 0, QApplication::UnicodeUTF8));
        autoLoginBox->setText(QApplication::translate("Options", "Log in on connect", 0, QApplication::UnicodeUTF8));
        autoConnectBox->setText(QApplication::translate("Options", "Connect on startup", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(connectionTab), QApplication::translate("Options", "Connection", 0, QApplication::UnicodeUTF8));
        minimizeTrayBox->setText(QApplication::translate("Options", "Minimize to tray", 0, QApplication::UnicodeUTF8));
        alwaysShowTrayBox->setText(QApplication::translate("Options", "Always show tray icon", 0, QApplication::UnicodeUTF8));
        highlightNickBox->setText(QApplication::translate("Options", "Highlight local username", 0, QApplication::UnicodeUTF8));
        reformatActionsBox->setText(QApplication::translate("Options", "Format *nick actions*", 0, QApplication::UnicodeUTF8));
        timestampsBox->setText(QApplication::translate("Options", "Display timestamps", 0, QApplication::UnicodeUTF8));
        listOptionsBox->setTitle(QApplication::translate("Options", "User list", 0, QApplication::UnicodeUTF8));
        listOption->setText(QApplication::translate("Options", "List", 0, QApplication::UnicodeUTF8));
        treeOption->setText(QApplication::translate("Options", "Tree", 0, QApplication::UnicodeUTF8));
        columnOption->setText(QApplication::translate("Options", "Column view", 0, QApplication::UnicodeUTF8));
        fontSizeLabel->setText(QApplication::translate("Options", "Font size", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(displayTab), QApplication::translate("Options", "Display", 0, QApplication::UnicodeUTF8));
        setNameLabel->setText(QApplication::translate("Options", "Set Name", 0, QApplication::UnicodeUTF8));
        setNameShortcutBox->setText(QApplication::translate("Options", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        switchTabsLabel->setText(QApplication::translate("Options", "Switch Tabs", 0, QApplication::UnicodeUTF8));
        switchTabsShortcutBox->setText(QApplication::translate("Options", "Ctrl+Tab", 0, QApplication::UnicodeUTF8));
        closeTabLabel->setText(QApplication::translate("Options", "Close Tab", 0, QApplication::UnicodeUTF8));
        closeTabShortcutBox->setText(QApplication::translate("Options", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        autoPMBox->setText(QApplication::translate("Options", "Auto-create PM tabs", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Options", "Command Line Options", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Options", "-n <name>", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Options", "Set name on connect", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Options", "-h <host>", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Options", "Connect to host", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Options", "-p <port>", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Options", "Connect on port", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Options", "-b", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("Options", "Enables local user highlighting", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(shortcutTab), QApplication::translate("Options", "Shortcuts", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Options", "HTML log file", 0, QApplication::UnicodeUTF8));
        htmlFileBox->setText(QApplication::translate("Options", "CCChatLog.html", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Options", "Plain log file", 0, QApplication::UnicodeUTF8));
        plainFileBox->setText(QApplication::translate("Options", "CCChatLog.log", 0, QApplication::UnicodeUTF8));
        plainLogBox->setText(QApplication::translate("Options", "Write plain log", 0, QApplication::UnicodeUTF8));
        logTimestampsBox->setText(QApplication::translate("Options", "Include timestamps", 0, QApplication::UnicodeUTF8));
        logAnnounceBox->setText(QApplication::translate("Options", "Include client and announce messages", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Options", "Timestamp", 0, QApplication::UnicodeUTF8));
        htmlLogBox->setText(QApplication::translate("Options", "Write HTML log", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(logTab), QApplication::translate("Options", "Logging", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        AboutLabel->setText(QApplication::translate("Options", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Qt CyanChat %version%</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Written by Nadnerb</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Tango icon courtesy of Darryl \"Paradox\" Pogue</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(aboutTab), QApplication::translate("Options", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
