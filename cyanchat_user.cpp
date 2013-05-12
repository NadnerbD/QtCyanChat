#include "cyanchat.h"

QColor CyanChat::User::levelColors[5] = {
    QColor(255, 255, 255),
    QColor(0, 255, 255),
    QColor(0, 255, 0),
    QColor(255, 0, 0),
    QColor(0xff, 0xc8, 0x00)
};

CyanChat::User::User(QString str) {
    fromString(str);
}

QString CyanChat::User::fullName() const {
    return QString().setNum(level) + name;
}

void CyanChat::User::fromString(QString str) {
    str.remove('\n');
    str.remove('\r');
    QStringList args = str.split(",");
    if(args.count() > 1)
	addr = args[1];
    else
	addr = "";
    name = args[0].mid(1);
    level = args[0].left(1).toInt();
}

QString CyanChat::User::toString() const {
    return fullName() + "," + addr;
}

QColor CyanChat::User::color() const {
    return levelColors[level < 5 ? level : 3];
}

bool CyanChat::User::isIgnored(QList<User>& ignoreList) {
    for(int i = 0; i < ignoreList.count(); i++) {
	if(ignoreList[i].addr == addr)
	    return true;
    }
    return false;
}
