#include "dialogupdate.h"
#include "ui_dialogupdate.h"

#include <QSql>
#include <QSqlQuery>

DialogUpdate::DialogUpdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUpdate)
{
    ui->setupUi(this);
}

DialogUpdate::~DialogUpdate()
{
    delete ui;
}

void DialogUpdate::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("lab.db");
    QSqlQuery query;

    db.open();
    query.exec(QString("update author set fio = '%1', address = '%2' where id = %3").arg(ui->lineEdit->text(), ui->lineEdit_2->text(), MainWindow.sendData(0);));
    db.close();
    close();
}

