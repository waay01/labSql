#include "dialogbook.h"
#include "ui_dialogbook.h"


DialogBook::DialogBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBook)
{
    ui->setupUi(this);
}

DialogBook::~DialogBook()
{
    delete ui;
}

void DialogBook::setName(QString name) {
    ui->label->setText(name);
}

QStringList DialogBook::getData()
{
    QStringList dataList;

    dataList += ui->lineEdit->text();
    dataList += ui->lineEdit_2->text();
    dataList += ui->lineEdit_3->text();
    dataList += ui->lineEdit_4->text();
    dataList += ui->lineEdit_5->text();

    return dataList;
}

void DialogBook::on_pushButton_clicked()
{
    close();
}
