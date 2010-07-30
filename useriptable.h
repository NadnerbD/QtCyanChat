class UserIPTable {
    public:
        UserIPTable(QString filename);
        QString getRealName(QString IPHash, QString name);
        void setRealName(QString IPHash, QString name);
    private:
        QString filename;
        QMap<QString, QStringList> nameTable;

        void writeTable();
};
