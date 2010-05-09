#ifndef PMWIDGET_H
#define PMWIDGET_H

#include "cyanchat.h"
#include <QLineEdit>
#include <QtGui/QWidget>

namespace Ui {
    class PMWidget;
}

class PMWidget : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(PMWidget)

private:
    Ui::PMWidget *m_ui;

public:
    explicit PMWidget(CyanChat::User user, CyanChat* tcc, QWidget *parent = 0);
    virtual ~PMWidget();

    void pmRecv(const CyanChat::User&, const CyanChat::Msg&);
    QLineEdit* pmBox;
    CyanChat::User target;
    CyanChat* cc;


private slots:
    void pmSendSlot();
    void closeSlot();

protected:
    virtual void changeEvent(QEvent *e);
};

#endif // PMWIDGET_H
