#ifndef DATABASEQUERY_H
#define DATABASEQUERY_H

#include <QSql>
#include <QSqlQuery>

class databaseQuery
{
public:
    void execQuery(QString strQuery);
    void execQueryAdd(QString strQuery);
    void execQueryUpdate(QString strQuery);
    void execQueryDelete(QString strQuery);

    QStringList execQueryPRAGMA(QString strQuery);
};

#endif // DATABASEQUERY_H
