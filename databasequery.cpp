#include "databasequery.h"

void databaseQuery::execQuery(const QString& strQuery) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("lab.db");

    if (db.open()) {
        QSqlQuery query(db);
        query.exec(strQuery);
        db.close();
    }
}

QStringList databaseQuery::execQueryPRAGMA(const QString& strTable) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("lab.db");
    QStringList nameColumn;

    if (!db.open())
        return nameColumn;

    QSqlQuery query(db);
    query.exec(QString("PRAGMA table_info(%1)").arg(strTable));
    while(query.next())
        nameColumn += query.value(1).toStringList();

    db.close();
    return nameColumn;
}
