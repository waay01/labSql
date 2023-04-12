#include "addnametable.h"
#include "ui_addnametable.h"

bool statusClose = false;

addNameTable::addNameTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNameTable)
{
    ui->setupUi(this);
}

addNameTable::~addNameTable()
{
    delete ui;
}

QString addNameTable::getName() {
    if (statusClose)
        return ui->lineEdit->text();
    else
        return "";
}



void addNameTable::on_pushButton_clicked()
{
    statusClose = true;
    close();
}

