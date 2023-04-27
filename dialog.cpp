#include "dialog.h"
#include "ui_dialog.h"

bool status = false;

dialog::dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
}

dialog::~dialog()
{
    delete ui;
}

void dialog::getWindow(int index) {
    ui->stackedWidget->setCurrentIndex(index);
}

void dialog::setName(QString name) {
    ui->label->setText(name + ':');
}

void dialog::sendData(int index, std::vector<QStringList> itemList) {
    switch(index) {
        case 1:
            ui->comboBox->addItems(itemList[0]);
            break;

        case 3:
            ui->comboBox_2->addItems(itemList[0]);
            ui->comboBox_3->addItems(itemList[1]);
            break;

        case 5:
            ui->comboBox_6->addItems(itemList[0]);
            ui->comboBox_5->addItems(itemList[1]);
            ui->comboBox_4->addItems(itemList[2]);
            break;
    }
}

QStringList dialog::getData(int index) {
    QStringList dataList = {};

    switch(index) {
        case 0:
            dataList += ui->lineEdit_6->text();
            break;
        case 1:
            dataList += ui->comboBox->currentText();
            dataList += ui->lineEdit_2->text();
            break;
        case 2:
            dataList += ui->lineEdit->text();
            dataList += ui->lineEdit_3->text();
            break;
        case 3:
            dataList += ui->lineEdit_4->text();
            dataList += ui->comboBox_2->currentText();
            dataList += ui->comboBox_3->currentText();
            dataList += ui->lineEdit_8->text();
            dataList += ui->lineEdit_9->text();
            break;
        case 4:
            dataList += ui->lineEdit_18->text();
            dataList += ui->lineEdit_7->text();
            dataList += ui->lineEdit_10->text();
            break;
        case 5:
            dataList += ui->lineEdit_11->text();
            dataList += ui->comboBox_6->currentText();
            dataList += ui->comboBox_5->currentText();
            dataList += ui->comboBox_4->currentText();
            dataList += ui->lineEdit_15->text();
            dataList += ui->lineEdit_16->text();
            break;
        case 6:
            dataList += ui->lineEdit_12->text();
            dataList += ui->lineEdit_13->text();
            dataList += ui->lineEdit_14->text();
            break;
        case 7:
            dataList += ui->lineEdit_5->text();
            break;
    }

//    qDebug() << "1-" << status;
//    if (!status)
//        return {""};

//    status = false;
    return dataList;
}

void dialog::on_pushButton_clicked()
{
    status = true;
    close();
}
