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


QStringList Dialog::getData()
{
    QStringList dataList;

    dataList += ui->lineEdit->text();
    dataList += ui->lineEdit_2->text();

    return dataList;
}

void Dialog::on_pushButton_clicked()
{
    close();
}

