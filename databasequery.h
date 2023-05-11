#ifndef DATABASEQUERY_H
#define DATABASEQUERY_H

#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>

class databaseQuery
{
public:
    void execQuery(const QString& strQuery);

    QSqlQueryModel* execSelectQuery(const QString& strQuery);

    QStringList execQueryPRAGMA(const QString& strTable);
};

#endif // DATABASEQUERY_H
