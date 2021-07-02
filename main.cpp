#include <QApplication>
#include "cyanchat.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CyanChat w;
    w.show();
    return a.exec();
}
