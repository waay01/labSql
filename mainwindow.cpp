#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qtextdocument.h"
#include <QFile>

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
    if (ui->comboBox->currentIndex() == 2) {
        DialogUpdate dialogUpdate;
        dialogUpdate.setName("Добавление");
        dialogUpdate.setModal(true);
        dialogUpdate.exec();

        databaseQuery databaseQuery;
        databaseQuery.execQuery(QString("insert into author(fio, address) values(%1,%2);").arg(dialogUpdate.getData()[0], dialogUpdate.getData()[1]));
    }

    if (ui->comboBox->currentIndex() == 3) {
        DialogBook dialogbook;
        dialogbook.setName("Добавление");
        dialogbook.setModal(true);
        dialogbook.exec();

        if (dialogbook.getData()[0] != "" && dialogbook.getData()[1] != "" && dialogbook.getData()[2] != "" && dialogbook.getData()[3] != "" && dialogbook.getData()[4] != "") {
            databaseQuery databaseQuery;
            QString strQuery = "insert into book(name, id_author, id_typeStyle, year, countList) values (%1,%2,%3,%4,%5);";
            databaseQuery.execQuery(QString(strQuery).arg(dialogbook.getData()[0], dialogbook.getData()[1], dialogbook.getData()[2], dialogbook.getData()[3], dialogbook.getData()[4]));
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (ui->comboBox->currentIndex() == 2) {
        DialogUpdate dialogUpdate;
        dialogUpdate.setName("Редактирование");
        dialogUpdate.setModal(true);
        dialogUpdate.exec();

        if (dialogUpdate.getData()[0] != "" && dialogUpdate.getData()[1] != "") {
            databaseQuery databaseQuery;
            databaseQuery.execQuery(QString("update author set fio = '%1', address = '%2' where id = %3").arg(dialogUpdate.getData()[0], dialogUpdate.getData()[1], QString::number(ui->tableWidget->currentItem()->text().toInt())));
        }
    }
    else if (ui->comboBox->currentIndex() == 3) {
        DialogBook dialogbook;
        dialogbook.setName("Редактирование");
        dialogbook.setModal(true);
        dialogbook.exec();

        if (dialogbook.getData()[0] != "" && dialogbook.getData()[1] != "" && dialogbook.getData()[2] != "" && dialogbook.getData()[3] != "" && dialogbook.getData()[4] != "") {
            databaseQuery databaseQuery;
            QString strQuery = "update book set name = '%1', id_author = '%2', id_typeStyle = '%3', year = '%4', countList = '%5' where id = %6";
            databaseQuery.execQuery(QString(strQuery).arg(dialogbook.getData()[0], dialogbook.getData()[1], dialogbook.getData()[2], dialogbook.getData()[3], dialogbook.getData()[4], QString::number(ui->tableWidget->currentItem()->text().toInt())));
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if (ui->comboBox->currentIndex() == 2) {
        databaseQuery databaseQuery;
        databaseQuery.execQuery(QString("delete from author where id = %1").arg(ui->tableWidget->currentItem()->text().toInt()));
    }
    if (ui->comboBox->currentIndex() == 3) {
        databaseQuery databaseQuery;
        databaseQuery.execQuery(QString("delete from book where id = %1").arg(ui->tableWidget->currentItem()->text().toInt()));
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
    if (ui->comboBox->currentIndex() == 2) {
        DialogUpdate dialogUpdate;
        dialogUpdate.setName("Добавление");
        dialogUpdate.setModal(true);
        dialogUpdate.exec();

        databaseQuery databaseQuery;
        databaseQuery.execQuery(QString("insert into author(fio, address) values(%1,%2);").arg(dialogUpdate.getData()[0], dialogUpdate.getData()[1]));
    }

    if (ui->comboBox->currentIndex() == 3) {
        DialogBook dialogbook;
        dialogbook.setName("Добавление");
        dialogbook.setModal(true);
        dialogbook.exec();

        if (dialogbook.getData()[0] != "" && dialogbook.getData()[1] != "" && dialogbook.getData()[2] != "" && dialogbook.getData()[3] != "" && dialogbook.getData()[4] != "") {
            databaseQuery databaseQuery;
            QString strQuery = "insert into book(name, id_author, id_typeStyle, year, countList) values (%1,%2,%3,%4,%5);";
            databaseQuery.execQuery(QString(strQuery).arg(dialogbook.getData()[0], dialogbook.getData()[1], dialogbook.getData()[2], dialogbook.getData()[3], dialogbook.getData()[4]));
        }
    }
}

void MainWindow::slotEdit() {
    if (ui->comboBox->currentIndex() == 2) {
        DialogUpdate dialogUpdate;
        dialogUpdate.setName("Редактирование");
        dialogUpdate.setModal(true);
        dialogUpdate.exec();

        if (dialogUpdate.getData()[0] != "" && dialogUpdate.getData()[1] != "") {
            databaseQuery databaseQuery;
            databaseQuery.execQuery(QString("update author set fio = '%1', address = '%2' where id = %3").arg(dialogUpdate.getData()[0], dialogUpdate.getData()[1], QString::number(ui->tableWidget->currentItem()->text().toInt())));
        }
    }
    else if (ui->comboBox->currentIndex() == 3) {
        DialogBook dialogbook;
        dialogbook.setName("Редактирование");
        dialogbook.setModal(true);
        dialogbook.exec();

        if (dialogbook.getData()[0] != "" && dialogbook.getData()[1] != "" && dialogbook.getData()[2] != "" && dialogbook.getData()[3] != "" && dialogbook.getData()[4] != "") {
            databaseQuery databaseQuery;
            QString strQuery = "update book set name = '%1', id_author = '%2', id_typeStyle = '%3', year = '%4', countList = '%5' where id = %6";
            databaseQuery.execQuery(QString(strQuery).arg(dialogbook.getData()[0], dialogbook.getData()[1], dialogbook.getData()[2], dialogbook.getData()[3], dialogbook.getData()[4], QString::number(ui->tableWidget->currentItem()->text().toInt())));
        }
    }
}

void MainWindow::slotDelete() {
    if (ui->comboBox->currentIndex() == 2) {
        databaseQuery databaseQuery;
        databaseQuery.execQuery(QString("delete from author where id = %1").arg(ui->tableWidget->currentItem()->text().toInt()));
    }
    if (ui->comboBox->currentIndex() == 3) {
        databaseQuery databaseQuery;
        databaseQuery.execQuery(QString("delete from book where id = %1").arg(ui->tableWidget->currentItem()->text().toInt()));
    }
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

