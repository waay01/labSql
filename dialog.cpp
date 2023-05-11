#include "dialog.h"
#include "ui_dialog.h"

bool status = false;

dialog::dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
    status = false;

}

dialog::~dialog()
{
    delete ui;
}

void dialog::getWindow(int index) {
    ui->stackedWidget->setCurrentIndex(index);
}

void dialog::preInput(int indexTable, int row) {
    databaseQuery databaseQuery;
    QStringList listTable = {"action", "allDeliveries", "author", "book", "logs", "marketBook", "staffMember", "typeStyle"}, itemList, nameColumn;
    int countRow = 0, countColumn = 0;
    nameColumn = databaseQuery.execQueryPRAGMA(listTable[indexTable]);
    countColumn = nameColumn.size();

    QSqlQueryModel* query = databaseQuery.execSelectQuery(QString("select * from %1").arg(listTable[indexTable]));

    for (int column = 1; column < countColumn; ++column)
        itemList += query->data(query->index(row, column)).toString();

    switch(indexTable) {
        case 0:
            ui->lineEdit_6->setText(itemList[0]);
            break;
        case 1:
            ui->comboBox->setCurrentText(itemList[0]);
            ui->lineEdit_2->setText(itemList[1]);
            break;
        case 2:
            ui->lineEdit->setText(itemList[0]);
            ui->lineEdit_3->setText(itemList[1]);
            break;
        case 3:
            ui->lineEdit_4->setText(itemList[0]);
            ui->comboBox_2->setCurrentText(itemList[1]);
            ui->comboBox_3->setCurrentText(itemList[2]);
            ui->lineEdit_8->setText(itemList[3]);
            ui->lineEdit_9->setText(itemList[4]);
            break;
        case 4:
            ui->lineEdit_18->setText(itemList[0]);
            ui->lineEdit_7->setText(itemList[1]);
            ui->lineEdit_10->setText(itemList[2]);
            break;
        case 5:
            ui->lineEdit_11->setText(itemList[0]);
            ui->comboBox_6->setCurrentText(itemList[1]);
            ui->comboBox_5->setCurrentText(itemList[2]);
            ui->comboBox_4->setCurrentText(itemList[3]);
            ui->lineEdit_15->setText(itemList[4]);
            ui->lineEdit_16->setText(itemList[5]);
            qDebug() << itemList;
            break;
        case 6:
            ui->lineEdit_12->setText(itemList[0]);
            ui->lineEdit_13->setText(itemList[1]);
            ui->lineEdit_14->setText(itemList[2]);
            break;
        case 7:
            ui->lineEdit_5->setText(itemList[0]);
            break;
    }

    delete query;
}

void dialog::setName(const QString& name) {
    ui->label->setText(name + ':');
}

void dialog::sendData(int index, const QVector<QStringList>& itemList) {
    if (index == 1) {
        ui->comboBox->addItems(itemList[0]);
    } else if (index == 3) {
        ui->comboBox_2->addItems(itemList[0]);
        ui->comboBox_3->addItems(itemList[1]);
    } else if (index == 5) {
        ui->comboBox_6->addItems(itemList[0]);
        ui->comboBox_5->addItems(itemList[1]);
        ui->comboBox_4->addItems(itemList[2]);
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

    return dataList;
}

bool dialog::transaction() {
    return status;
}

void dialog::on_pushButton_clicked()
{
    status = true;
    transaction();
    close();
}
