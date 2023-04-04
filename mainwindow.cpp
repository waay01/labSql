#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotAdd()));
    connect(ui->tableWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEdit()));
    connect(ui->tableWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotDelete()));
    connect(ui->tableWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContexMenu(QPoint)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    Dialog dialog;
//    dialog.setModal(true);
//    dialog.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
//    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(ui->tableWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEdit()));

//    connect(ui->tableWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContexMenu(QPoint)));
//
}

void MainWindow::on_pushButton_3_clicked()
{
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    QSqlQuery query;
//    db.setDatabaseName("lab.db");

//    qDebug() << ui->tableWidget->currentRow();
//    db.open();
//    query.exec(QString("delete from author where id = %1").arg(ui->tableWidget->currentItem()->text().toInt()));
//    db.close();
}

void MainWindow::on_pushButton_4_clicked()
{
    int countRow = 0, countColumn = 0;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery query;
    QStringList nameColumn, itemList;

    QString strTable = ui->comboBox->currentText();

    db.setDatabaseName("lab.db");
    db.open();

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
    // optimizate
}

void MainWindow::slotContexMenu(QPoint pos) {
    QMenu *menu = new QMenu(this);

    QAction *addSlot = new QAction("Добавить", this);
    connect(addSlot, SIGNAL(triggered()), this, SLOT(slotAdd()));

    QAction *editSlot = new QAction("Редактировать", this);
    connect(editSlot, SIGNAL(triggered()), this, SLOT(slotEdit()));

    QAction *deleteSlot = new QAction("Удалить", this);
    connect(deleteSlot, SIGNAL(triggered()), this, SLOT(slotDelete()));

    menu->addAction(addSlot);
    menu->addAction(editSlot);
    menu->addAction(deleteSlot);
    menu->popup(ui->tableWidget->viewport()->mapToGlobal(pos));
}

void MainWindow::slotAdd() {
    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();

    databaseQuery databaseQuery;
    databaseQuery.execQuery(QString("insert into author(fio, address) values(%1,%2);").arg(dialog.getData()[0], dialog.getData()[1]));
}

void MainWindow::slotEdit() {

    DialogUpdate dialogUpdate;
    dialogUpdate.setModal(true);
    dialogUpdate.exec();

    if (dialogUpdate.getData()[0] != "" && dialogUpdate.getData()[1] != "") {
        databaseQuery databaseQuery;
        databaseQuery.execQuery(QString("update author set fio = '%1', address = '%2' where id = %3").arg(dialogUpdate.getData()[0], dialogUpdate.getData()[1], QString::number(ui->tableWidget->currentItem()->text().toInt())));
    }
}

void MainWindow::slotDelete() {
    databaseQuery databaseQuery;
    databaseQuery.execQuery(QString("delete from author where id = %1").arg(ui->tableWidget->currentItem()->text().toInt()));
}
