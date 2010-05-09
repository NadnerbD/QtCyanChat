#ifndef OPTIONS_H
#define OPTIONS_H

#include <QtGui/QDialog>

namespace Ui {
    class Options;
}

class CyanChat;

class Options : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Options)
public:
    explicit Options(CyanChat *parent = 0);
    virtual ~Options();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::Options *ui;
    CyanChat *cc;

private slots:
    void updateOptions();
};

#endif // OPTIONS_H
