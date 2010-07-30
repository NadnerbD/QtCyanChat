#include <QMap>
#include <QFile>
#include <QList>
#include <QString>
#include <QStringList>
#include <QTextStream>

#include "useriptable.h"

UserIPTable::UserIPTable(QString filename) {
    this->filename = filename;
    QFile infile(filename);
    if(infile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&infile);
        while(!in.atEnd()) {
            QString line = in.readLine();
            QStringList args = line.split("\t");
            nameTable[args.takeFirst()] = args;
        }
        infile.close();
    }
}

QString UserIPTable::getRealName(QString IPHash, QString name) {
    if(!nameTable.contains(IPHash)) {
        QStringList newlist;
        newlist.append(name);
        nameTable[IPHash] = newlist;
        writeTable();
    }
    if(!nameTable[IPHash].contains(name)) {
        nameTable[IPHash].append(name);
        writeTable();
    }
    return nameTable[IPHash][0];
}

QStringList UserIPTable::getAllNames(QString IPHash) {
    return nameTable[IPHash];
}

void UserIPTable::setRealName(QString IPHash, QString name) {
    if(name != getRealName(IPHash, name)) {
        nameTable[IPHash].removeAll(name);
        nameTable[IPHash].insert(0, name);
        writeTable();
    }
}

void UserIPTable::writeTable() {
    QFile outfile(filename);
    outfile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&outfile);
    foreach(QString key, nameTable.keys()) {
        out << key;
        foreach(QString name, nameTable[key]) {
            out << "\t";
            out << name;
        }
        out << "\n";
    }
    outfile.close();
}
