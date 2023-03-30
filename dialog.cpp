#include "dialog.h"
#include "ui_dialog.h"
#include <QSql>
#include <QSqlQuery>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("lab.db");
    QSqlQuery query;

    db.open();
    query.exec(QString("insert into author(fio, address) values(%1,%2);").arg(ui->lineEdit->text(), ui->lineEdit_2->text()));
    db.close();
    close();
}

