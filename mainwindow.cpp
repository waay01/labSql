#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "dialog.h"
#include "dialogupdate.h"
#include <QSql>
#include <QSqlQuery>

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog *dialog = new Dialog;
    dialog->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    DialogUpdate *dialogUpdate = new DialogUpdate;
    dialogUpdate->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery query;
    db.setDatabaseName("lab.db");

    qDebug() << ui->tableWidget->currentRow();
    db.open();
    query.exec(QString("delete from author where id = %1").arg(ui->tableWidget->currentItem()->text().toInt()));
    db.close();
}

void MainWindow::on_pushButton_4_clicked()
{
    int countRow = 0, countColumn = 0;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery query;
    QStringList nameColumn, itemList;


    db.setDatabaseName("lab.db");
    db.open();

    query.exec("PRAGMA table_info(author)");
    while(query.next()) {
        nameColumn += query.value(1).toStringList();
    }
    countColumn = nameColumn.size();


    query.exec("select * from author");
    while(query.next()) {
        itemList += query.value(0).toString();
        itemList += query.value(1).toString();
        itemList += query.value(2).toString();
        ++countRow;
    }
    db.close();

    ui->tableWidget->setColumnCount(countColumn);
    ui->tableWidget->setRowCount(countRow);
    ui->tableWidget->setHorizontalHeaderLabels(nameColumn);

    int countResultQuery = 0;
    for(int i = 0; i < countRow; ++i){
        for(int j = 0; j < countColumn; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(itemList[j+countResultQuery]);
            ui->tableWidget->setItem(i,j,item);
        }
        countResultQuery += countColumn;
    }
}


