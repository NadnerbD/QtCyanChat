/********************************************************************************
** Form generated from reading UI file 'pmwidget.ui'
**
** Created: Sun Mar 28 22:58:32 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PMWIDGET_H
#define UI_PMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PMWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *pmTopBar;
    QLabel *pmTitle;
    QToolButton *closeButton;
    QLineEdit *pmBox;
    QTextBrowser *pmText;

    void setupUi(QWidget *PMWidget)
    {
        if (PMWidget->objectName().isEmpty())
            PMWidget->setObjectName(QString::fromUtf8("PMWidget"));
        PMWidget->resize(493, 300);
        verticalLayout = new QVBoxLayout(PMWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pmTopBar = new QHBoxLayout();
        pmTopBar->setObjectName(QString::fromUtf8("pmTopBar"));
        pmTitle = new QLabel(PMWidget);
        pmTitle->setObjectName(QString::fromUtf8("pmTitle"));

        pmTopBar->addWidget(pmTitle);

        closeButton = new QToolButton(PMWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        pmTopBar->addWidget(closeButton);


        verticalLayout->addLayout(pmTopBar);

        pmBox = new QLineEdit(PMWidget);
        pmBox->setObjectName(QString::fromUtf8("pmBox"));

        verticalLayout->addWidget(pmBox);

        pmText = new QTextBrowser(PMWidget);
        pmText->setObjectName(QString::fromUtf8("pmText"));
        pmText->setOpenExternalLinks(true);

        verticalLayout->addWidget(pmText);


        retranslateUi(PMWidget);

        QMetaObject::connectSlotsByName(PMWidget);
    } // setupUi

    void retranslateUi(QWidget *PMWidget)
    {
        PMWidget->setWindowTitle(QApplication::translate("PMWidget", "Form", 0, QApplication::UnicodeUTF8));
        pmTitle->setText(QApplication::translate("PMWidget", "Private chat with [Name]", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("PMWidget", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PMWidget: public Ui_PMWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PMWIDGET_H
