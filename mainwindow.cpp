#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qtextdocument.h"
#include "dialog.h"
#include <QFile>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_pushButton_clicked()));
    connect(ui->tableWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_pushButton_2_clicked()));
    connect(ui->tableWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_pushButton_3_clicked()));
    connect(ui->tableWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContexMenu(QPoint)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // для comboBox
    std::vector<QStringList> itemList;
    QStringList tmp;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery query;
    db.setDatabaseName("lab.db");
    //


    dialog dialogInsert;
    dialogInsert.setName("Добавление");
    dialogInsert.setModal(true);

    databaseQuery databaseQuery;
    switch (ui->comboBox->currentIndex()) {
        case 0:
            dialogInsert.getWindow(0);
            dialogInsert.exec();
            if (dialogInsert.getData(0)[0] != "") {
                QString strQuery = "insert into action(NameAction) values('%1');";
                databaseQuery.execQuery(QString(strQuery).arg(dialogInsert.getData(0)[0]));
            }
            break;

        case 1:
            db.open();
            query.exec(QString("select id from marketBook"));
            while(query.next())
                tmp += query.value(0).toString();
            db.close();
            itemList.emplace_back(tmp);
            dialogInsert.sendData(ui->comboBox->currentIndex(), itemList);
            itemList.clear();
            tmp = {};

            dialogInsert.getWindow(1);
            dialogInsert.exec();
            if (dialogInsert.getData(1)[0] != "" && dialogInsert.getData(1)[1] != "") {
                QString strQuery = "insert into allDeliveries(id_book, count) values(%1,%2);";
                databaseQuery.execQuery(QString(strQuery).arg(dialogInsert.getData(1)[0], dialogInsert.getData(1)[1]));
            }
            break;

        case 2:
            dialogInsert.getWindow(2);
            dialogInsert.exec();
            if (dialogInsert.getData(2)[0] != "" && dialogInsert.getData(2)[1] != "") {
                QString strQuery = "insert into author(fio, address) values('%1','%2');";
                databaseQuery.execQuery(QString(strQuery).arg(dialogInsert.getData(2)[0], dialogInsert.getData(2)[1]));
            }
            break;

        case 3:
            db.open();
            query.exec(QString("select id from author"));
            while(query.next())
                tmp += query.value(0).toString();
            db.close();
            itemList.emplace_back(tmp);
            tmp = {};

            db.open();
            query.exec(QString("select id from typeStyle"));
            while(query.next())
                tmp += query.value(0).toString();
            db.close();
            itemList.emplace_back(tmp);
            tmp = {};

            dialogInsert.sendData(ui->comboBox->currentIndex(), itemList);
            itemList.clear();

            dialogInsert.getWindow(3);
            dialogInsert.exec();
            if (dialogInsert.getData(3)[0] != "" && dialogInsert.getData(3)[1] != "" && dialogInsert.getData(3)[2] != "" && dialogInsert.getData(3)[3] != "" && dialogInsert.getData(3)[4] != "") {
                QString strQuery = "insert into book(name, id_author, id_typeStyle, year, countList) values ('%1',%2,%3,%4,%5);";
                databaseQuery.execQuery(QString(strQuery).arg(dialogInsert.getData(3)[0], dialogInsert.getData(3)[1], dialogInsert.getData(3)[2], dialogInsert.getData(3)[3], dialogInsert.getData(3)[4]));
            }
            break;

        case 4:
            dialogInsert.getWindow(4);
            dialogInsert.exec();
            if (dialogInsert.getData(4)[0] != "" && dialogInsert.getData(4)[1] != "" && dialogInsert.getData(4)[2] != "") {
                QString strQuery = "insert into logs(nameAction, date, nameTable) values ('%1','%2','%3');";
                databaseQuery.execQuery(QString(strQuery).arg(dialogInsert.getData(4)[0], dialogInsert.getData(4)[1], dialogInsert.getData(4)[2]));
            }
            break;

        case 5:
            db.open();
            query.exec(QString("select id from action"));
            while(query.next())
                tmp += query.value(0).toString();
            db.close();
            itemList.emplace_back(tmp);
            tmp = {};


            db.open();
            query.exec(QString("select id from staffMember"));
            while(query.next())
                tmp += query.value(0).toString();
            db.close();
            itemList.emplace_back(tmp);
            tmp = {};

            db.open();
            query.exec(QString("select id from book"));
            while(query.next())
                tmp += query.value(0).toString();
            db.close();
            itemList.emplace_back(tmp);
            tmp = {};

            dialogInsert.sendData(ui->comboBox->currentIndex(), itemList);
            itemList.clear();


            dialogInsert.getWindow(5);
            dialogInsert.exec();
            if (dialogInsert.getData(5)[0] != "" && dialogInsert.getData(5)[1] != "" && dialogInsert.getData(5)[2] != "" && dialogInsert.getData(5)[3] != "" && dialogInsert.getData(5)[4] != "" && dialogInsert.getData(5)[5] != "") {
                QString strQuery = "insert into marketBook(date, id_action, id_staffMember, id_book, count, price) values ('%1',%2,%3,%4,%5,%6);";
                databaseQuery.execQuery(QString(strQuery).arg(dialogInsert.getData(5)[0], dialogInsert.getData(5)[1], dialogInsert.getData(5)[2], dialogInsert.getData(5)[3], dialogInsert.getData(5)[4], dialogInsert.getData(5)[5]));
            }
            break;

        case 6:
            dialogInsert.getWindow(6);
            dialogInsert.exec();
            if (dialogInsert.getData(6)[0] != "" && dialogInsert.getData(6)[1] != "" && dialogInsert.getData(6)[2] != "") {
                QString strQuery = "insert into staffMember(fio, numberPhone, inn) values ('%1',%2,%3);";
                databaseQuery.execQuery(QString(strQuery).arg(dialogInsert.getData(6)[0], dialogInsert.getData(6)[1], dialogInsert.getData(6)[2]));
            }
            break;

        case 7:
            dialogInsert.getWindow(7);
            dialogInsert.exec();
            if (dialogInsert.getData(7)[0] != "") {
                QString strQuery = "insert into typeStyle(nameStyle) values ('%1');";
                databaseQuery.execQuery(QString(strQuery).arg(dialogInsert.getData(7)[0]));
            }
            break;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    dialog dialogUpdate;
    dialogUpdate.setName("Редактирование");
    dialogUpdate.setModal(true);

    databaseQuery databaseQuery;
    switch (ui->comboBox->currentIndex()) {
        case 0:
            dialogUpdate.getWindow(0);
            dialogUpdate.exec();
            if (dialogUpdate.getData(0)[0] != "") {
                QString strQuery = "update action set NameAction = '%1' where id = %2;";
                databaseQuery.execQuery(QString(strQuery).arg(dialogUpdate.getData(0)[0], ui->tableWidget->currentItem()->text()));
            }
            break;

        case 1:
            dialogUpdate.getWindow(1);
            dialogUpdate.exec();
            if (dialogUpdate.getData(1)[0] != "" && dialogUpdate.getData(1)[1] != "") {
                QString strQuery = "update allDeliveries set id_book = %1, count = %2 where id %3;";
                databaseQuery.execQuery(QString(strQuery).arg(dialogUpdate.getData(1)[0], dialogUpdate.getData(1)[1], ui->tableWidget->currentItem()->text()));
            }
            break;

        case 2:
            dialogUpdate.getWindow(2);
            dialogUpdate.exec();
            if (dialogUpdate.getData(2)[0] != "" && dialogUpdate.getData(2)[1] != "") {
                QString strQuery = "update author set fio = '%1', address = '%2' where id = %3;";
                databaseQuery.execQuery(QString(strQuery).arg(dialogUpdate.getData(2)[0], dialogUpdate.getData(2)[1], ui->tableWidget->currentItem()->text()));
            }
            break;

        case 3:
            dialogUpdate.getWindow(3);
            dialogUpdate.exec();
            if (dialogUpdate.getData(3)[0] != "" && dialogUpdate.getData(3)[1] != "" && dialogUpdate.getData(3)[2] != "" && dialogUpdate.getData(3)[3] != "" && dialogUpdate.getData(3)[4] != "") {
                QString strQuery = "update book set name = '%1', id_author = %2, id_typeStyle = %3, yea = %4, countList = %5 where id = %6";
                databaseQuery.execQuery(QString(strQuery).arg(dialogUpdate.getData(3)[0], dialogUpdate.getData(3)[1], dialogUpdate.getData(3)[2], dialogUpdate.getData(3)[3], dialogUpdate.getData(3)[4], ui->tableWidget->currentItem()->text()));
            }
            break;

        case 4:
            dialogUpdate.getWindow(4);
            dialogUpdate.exec();
            if (dialogUpdate.getData(4)[0] != "" && dialogUpdate.getData(4)[1] != "" && dialogUpdate.getData(4)[2] != "") {
                QString strQuery = "update logs set nameAction = '%1', date = '%2', nameTable = '%3' where id = %4";
                databaseQuery.execQuery(QString(strQuery).arg(dialogUpdate.getData(4)[0], dialogUpdate.getData(4)[1], dialogUpdate.getData(4)[2], ui->tableWidget->currentItem()->text()));
            }
            break;

        case 5:
            dialogUpdate.getWindow(5);
            dialogUpdate.exec();
            if (dialogUpdate.getData(5)[0] != "" && dialogUpdate.getData(5)[1] != "" && dialogUpdate.getData(5)[2] != "" && dialogUpdate.getData(5)[3] != "" && dialogUpdate.getData(5)[4] != "" && dialogUpdate.getData(5)[5] != "") {
                QString strQuery = "update marketBook set date = '%1', id_action = %2, id_staffMember = %3, id_book = %4, count = %5, price = %6 where id = %7";
                databaseQuery.execQuery(QString(strQuery).arg(dialogUpdate.getData(5)[0], dialogUpdate.getData(5)[1], dialogUpdate.getData(5)[2], dialogUpdate.getData(5)[3], dialogUpdate.getData(5)[4], dialogUpdate.getData(5)[5], ui->tableWidget->currentItem()->text()));
            }
            break;

        case 6:
            dialogUpdate.getWindow(6);
            dialogUpdate.exec();
            if (dialogUpdate.getData(6)[0] != "" && dialogUpdate.getData(6)[1] != "" && dialogUpdate.getData(6)[2] != "") {
                QString strQuery = "update staffMember set fio = '%1', numberPhone = %2, inn = %3 where id = %4";
                databaseQuery.execQuery(QString(strQuery).arg(dialogUpdate.getData(6)[0], dialogUpdate.getData(6)[1], dialogUpdate.getData(6)[2], ui->tableWidget->currentItem()->text()));
            }
            break;

        case 7:
            dialogUpdate.getWindow(7);
            dialogUpdate.exec();
            if (dialogUpdate.getData(7)[0] != "") {
                QString strQuery = "update typeStyle set nameStyle = '%1' where id = %2";
                databaseQuery.execQuery(QString(strQuery).arg(dialogUpdate.getData(7)[0], ui->tableWidget->currentItem()->text()));
            }
            break;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString strQuery = "";
    databaseQuery databaseQuery;
    switch (ui->comboBox->currentIndex()) {
        case 0:
            strQuery = "delete from action where id = %1;";
            databaseQuery.execQuery(QString(strQuery).arg(ui->tableWidget->currentItem()->text()));
            break;

        case 1:
            strQuery = "delete from allDeliveries where id %1;";
            databaseQuery.execQuery(QString(strQuery).arg(ui->tableWidget->currentItem()->text()));
            break;

        case 2:
            strQuery = "delete from author where id = %1;";
            databaseQuery.execQuery(QString(strQuery).arg(ui->tableWidget->currentItem()->text()));
            break;

        case 3:
            strQuery = "delete from book where id = %1;";
            databaseQuery.execQuery(QString(strQuery).arg(ui->tableWidget->currentItem()->text()));
            break;

        case 4:
            strQuery = "delete from logs where id = %1;";
            databaseQuery.execQuery(QString(strQuery).arg(ui->tableWidget->currentItem()->text()));
            break;

        case 5:
            strQuery = "delete from marketBook where id = %1;";
            databaseQuery.execQuery(QString(strQuery).arg(ui->tableWidget->currentItem()->text()));
            break;

        case 6:
            strQuery = "delete from staffMember where id = %1";
            databaseQuery.execQuery(QString(strQuery).arg(ui->tableWidget->currentItem()->text()));
            break;

        case 7:
            strQuery = "delete from typeStyle where id = %1";
            databaseQuery.execQuery(QString(strQuery).arg(ui->tableWidget->currentItem()->text()));
            break;
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    int countRow = 0, countColumn = 0;
    QStringList nameColumn, itemList;

    QString strTable = ui->comboBox->currentText();

    databaseQuery databaseQuery;
    nameColumn = databaseQuery.execQueryPRAGMA(strTable);
    countColumn = nameColumn.size();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery query;
    db.setDatabaseName("lab.db");
    db.open();

    query.exec(QString("select * from %1").arg(strTable));
    while(query.next()) {
        for (int i = 0; i < countColumn; ++i)
            itemList += query.value(i).toString();
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

void MainWindow::slotContexMenu(QPoint pos) {
    QMenu *menu = new QMenu(this);

    QAction *addSlot = new QAction("Добавить", this);
    connect(addSlot, SIGNAL(triggered()), this, SLOT(on_pushButton_clicked()));

    QAction *editSlot = new QAction("Редактировать", this);
    connect(editSlot, SIGNAL(triggered()), this, SLOT(on_pushButton_2_clicked()));

    QAction *deleteSlot = new QAction("Удалить", this);
    connect(deleteSlot, SIGNAL(triggered()), this, SLOT(on_pushButton_3_clicked()));

    menu->addAction(addSlot);
    menu->addAction(editSlot);
    menu->addAction(deleteSlot);
    menu->popup(ui->tableWidget->viewport()->mapToGlobal(pos));
}

void MainWindow::on_pushButton_5_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableWidget->rowCount();
    const int columnCount = ui->tableWidget->columnCount();

    out << "<html>\n" << "<head>\n" <<
        QString("<title>%1</title>").arg("lab")
        << "</head>\n"
           "<body bgcolor = #f0f0f0>\n"
           "<table border = 1>\n";

    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; ++column) {
        out << QString("<th>%1</th>").arg(ui->tableWidget->model()->headerData(column, Qt::Horizontal).toString());
    }
    out << "</th></thead>\n";

    for (int row = 0; row < rowCount; ++row) {
        out << "<tr>";
        for (int column = 0; column < columnCount; ++column) {
            QString data = ui->tableWidget->model()->data(ui->tableWidget->model()->index(row, column)).toString().simplified();
            out << QString("<td bkcolor = 0>%1</td>").arg((!data.isEmpty()) ? data:QString("&nbsp;"));
        }
        out << "</tr>\n";
    }
    out << "</table>\n" << "</body>\n" << "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QFile fileOut("documnt.html");
    if(fileOut.open(QIODevice::WriteOnly)) {
        fileOut.write(strStream.toStdString().c_str());
        fileOut.close();
    }


    delete document;
}

void MainWindow::on_actionAdd_Table_triggered()
{
    addNameTable addNameTable;
    addNameTable.setModal(true);
    addNameTable.exec();

    if (addNameTable.getName() != "")
        ui->comboBox->addItem(addNameTable.getName());
}

void MainWindow::on_comboBox_activated(int index)
{
    on_pushButton_4_clicked();
    if (index == 8) {
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
    }
    else {
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
    }
}

