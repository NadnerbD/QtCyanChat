#include "pmwidget.h"
#include "ui_pmwidget.h"
#include <QTabWidget>

PMWidget::PMWidget(CyanChat::User user, CyanChat* tcc, QWidget *parent) : QWidget(parent), m_ui(new Ui::PMWidget), target(user), cc(tcc) {
    this->setObjectName(user.fullName());

    m_ui->setupUi(this);

    pmBox = m_ui->pmBox;

    // there used to be a label in this widget
    //m_ui->pmTitle->setText("Private chat with [" + user.name + "]");
    ((QTabWidget*)parent)->addTab(this, user.name);

    connect(m_ui->pmBox, SIGNAL(returnPressed()), this, SLOT(pmSendSlot()));
}

PMWidget::~PMWidget() {
    delete m_ui;
}

void PMWidget::changeEvent(QEvent *e) {
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void PMWidget::pmSendSlot() {
    QStringList lines = m_ui->pmBox->text().split("\n");
    foreach(QString line, lines) {
        QStringList args = line.split(" ");
        if(args.count() > 1 && args[0] == "/me") {
            args.pop_front();
            line = "*" + args.join(" ") + "*";
        }
        cc->addChatLine(m_ui->pmText, CyanChat::User("0" + cc->currentName), CyanChat::Msg(line, 1));
        cc->pm(target, line);
    }
    m_ui->pmBox->clear();
}

void PMWidget::closeSlot() {
    cc->closeTabSlot(this);
}

void PMWidget::pmRecv(const CyanChat::User& user, const CyanChat::Msg& message) {
    cc->addChatLine(m_ui->pmText, user, CyanChat::Msg(message.text, 1));
}
