#ifndef DATABASEQUERY_H
#define DATABASEQUERY_H

#include <QSql>
#include <QSqlQuery>

class databaseQuery
{
public:
    void execQuery(const QString& strQuery);

    QStringList execQueryPRAGMA(const QString& strTable);
};

#endif // DATABASEQUERY_H
