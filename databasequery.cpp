#include "databasequery.h"

void databaseQuery::execQuery(QString strQuery) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("lab.db");
    QSqlQuery query;

    db.open();
    query.exec(strQuery);
    db.close();
}

QStringList databaseQuery::execQueryPRAGMA(QString strQuery) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("lab.db");
    QSqlQuery query;
    QStringList nameColumn;

    db.open();

    query.exec(QString("PRAGMA table_info(%1)").arg(strTable));
    while(query.next()) {
        nameColumn += query.value(1).toStringList();
    }
    db.close();
}

//void databaseQuery::execQueryAdd(QString strQuery) {
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("lab.db");
//    QSqlQuery query;

//    db.open();
//    query.exec(strQuery);
//    db.close();
//}
