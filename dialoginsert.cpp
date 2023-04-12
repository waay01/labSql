#include "dialoginsert.h"
#include "ui_dialoginsert.h"

dialogInsert::dialogInsert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogInsert)
{
    ui->setupUi(this);
}

dialogInsert::~dialogInsert()
{
    delete ui;
}

void dialogInsert::getWindow(int index) {
    ui->stackedWidget->setCurrentIndex(index);
}

void dialogInsert::setName(QString name) {
    ui->label_4->setText(name + ':');
}

QStringList dialogInsert::getData()
{
    QStringList dataList;

    dataList += ui->lineEdit->text();
    dataList += ui->lineEdit_3->text();

    return dataList;
}

void dialogInsert::on_pushButton_3_clicked()
{
    close();
}

