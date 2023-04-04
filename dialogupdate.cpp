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

QStringList DialogUpdate::getData()
{
    QStringList dataList;

    dataList += ui->lineEdit->text();
    dataList += ui->lineEdit_2->text();

    return dataList;
}

void DialogUpdate::on_pushButton_clicked()
{
    close();
}

