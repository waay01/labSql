#include "databasequery.h"

QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

void databaseQuery::execQuery(const QString& strQuery) {
    db.setDatabaseName("lab.db");

    if (db.open()) {
        QSqlQuery query(db);
        query.exec(strQuery);
        db.close();
    }
}

QSqlQueryModel* databaseQuery::execSelectQuery(const QString& strQuery) {
    db.setDatabaseName("lab.db");
    QSqlQueryModel* model = new QSqlQueryModel();

    if (db.open()) {
        QSqlQuery query(db);
        query.exec(strQuery);
        model->setQuery(std::move(query));
        db.close();
    }
    return model;
}

QStringList databaseQuery::execQueryPRAGMA(const QString& strTable) {
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
