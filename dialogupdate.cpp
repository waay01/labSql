#include "dialogupdate.h"
#include "ui_dialogupdate.h"


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

void DialogUpdate::setName(QString name) {
    ui->label->setText(name);
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

