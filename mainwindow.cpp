#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;

map<int, int> st;
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

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

    on_pushButton_4_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int rowIndex(int row) {
    return st[row];
}

void MainWindow::on_pushButton_clicked()
{
    db.setDatabaseName("lab.db");
    databaseQuery databaseQuery;

    dialog dialogInsert;
    dialogInsert.setName("Добавление");
    dialogInsert.setModal(true);

    if (!db.isOpen())
        db.open();

    const int currentIndex = ui->comboBox->currentIndex();
    switch (currentIndex) {
        case 0: {
            dialogInsert.getWindow(0);
            dialogInsert.exec();
            const QStringList& data = dialogInsert.getData(0);
            if (dialogInsert.transaction() && !data.contains("")) {
                QString strQuery = "insert into action(NameAction) values('%1');";
                databaseQuery.execQuery(QString(strQuery).arg(data[0]));
            }
            break;
        }

        case 1: {
            QStringList marketBookIDs;

            QSqlQuery query("select id from marketBook", db);
            while(query.next())
                marketBookIDs += query.value(0).toString();

            dialogInsert.sendData(currentIndex, { marketBookIDs });
            dialogInsert.getWindow(1);
            dialogInsert.exec();
            const QStringList& data = dialogInsert.getData(1);
            if (dialogInsert.transaction() && !data.contains("")) {
                QString strQuery = "insert into allDeliveries(id_book, count) values(%1,%2);";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], data[1]));
            }
            break;
        }

        case 2: {
            dialogInsert.getWindow(2);
            dialogInsert.exec();
            const QStringList& data = dialogInsert.getData(2);
            if (dialogInsert.transaction() && !data.contains("")) {
                QString strQuery = "insert into author(fio, address) values('%1','%2');";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], data[1]));
            }
            break;
        }

        case 3: {
            QStringList authorIDs, typeStyleIDs;
            QVector<QStringList> itemList;

            QSqlQuery queryAuthor("select id from author");
            while(queryAuthor.next())
                authorIDs += queryAuthor.value(0).toString();
            itemList.emplace_back(authorIDs);

            QSqlQuery queryTypeStyle("select id from typeStyle");
            while(queryTypeStyle.next())
                typeStyleIDs += queryTypeStyle.value(0).toString();
            itemList.emplace_back(typeStyleIDs);

            dialogInsert.sendData(currentIndex, itemList);
            dialogInsert.getWindow(3);
            dialogInsert.exec();
            const QStringList& data = dialogInsert.getData(3);
            if (dialogInsert.transaction() && !data.contains("")) {
                QString strQuery = "insert into book(name, id_author, id_typeStyle, year, countList) values ('%1',%2,%3,%4,%5);";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], data[1], data[2], data[3], data[4]));
            }
            break;
        }

        case 4: {
            dialogInsert.getWindow(4);
            dialogInsert.exec();
            const QStringList& data = dialogInsert.getData(4);
            if (dialogInsert.transaction() && !data.contains("")) {
                QString strQuery = "insert into logs(nameAction, date, nameTable) values ('%1','%2','%3');";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], data[1], data[2]));
            }
            break;
        }

        case 5: {
            QStringList actionIDs, staffMemberIDs, bookIDs;
            QVector<QStringList> itemList;

            QSqlQuery queryAction("select id from action");
            while(queryAction.next())
                actionIDs += queryAction.value(0).toString();
            itemList.emplace_back(actionIDs);

            QSqlQuery querystaffMember("select id from staffMember");
            while(querystaffMember.next())
                staffMemberIDs += querystaffMember.value(0).toString();
            itemList.emplace_back(staffMemberIDs);

            QSqlQuery queryBookIDs("select id from book");
            while(queryBookIDs.next())
                bookIDs += queryBookIDs.value(0).toString();
            itemList.emplace_back(bookIDs);

            dialogInsert.sendData(currentIndex, itemList);
            dialogInsert.getWindow(5);
            dialogInsert.exec();
            const QStringList& data = dialogInsert.getData(5);
            if (dialogInsert.transaction() && !data.contains("")) {
                QString strQuery = "insert into marketBook(date, id_action, id_staffMember, id_book, count, price) values ('%1',%2,%3,%4,%5,%6);";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], data[1], data[2], data[3], data[4], data[5]));
            }
            break;
        }

        case 6: {
            dialogInsert.getWindow(6);
            dialogInsert.exec();
            const QStringList& data = dialogInsert.getData(6);
            if (dialogInsert.transaction() && !data.contains("")) {
                QString strQuery = "insert into staffMember(fio, numberPhone, inn) values ('%1',%2,%3);";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], data[1], data[2]));
            }
            break;
        }

        case 7: {
            dialogInsert.getWindow(7);
            dialogInsert.exec();
            const QStringList& data = dialogInsert.getData(7);
            if (dialogInsert.transaction() && !data.contains("")) {
                QString strQuery = "insert into typeStyle(nameStyle) values ('%1');";
                databaseQuery.execQuery(QString(strQuery).arg(data[0]));
            }
            break;
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    db.setDatabaseName("lab.db");
    databaseQuery databaseQuery;

    dialog dialogUpdate;
    dialogUpdate.setName("Редактирование");
    dialogUpdate.setModal(true);

    if (!db.isOpen())
        db.open();

    const int currentIndex = ui->comboBox->currentIndex(), currentRow = ui->tableWidget->currentItem()->row()+1;
    switch (currentIndex) {
        case 0: {
            dialogUpdate.getWindow(0);
            dialogUpdate.exec();
            const QStringList& data = dialogUpdate.getData(0);
            if (dialogUpdate.transaction() && !data.contains("")) {
                QString strQuery = "update action set NameAction = '%1' where id = %2;";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], QString::number(rowIndex(currentRow))));
            }
            break;
        }

        case 1: {
            dialogUpdate.getWindow(1);
            dialogUpdate.exec();
            const QStringList& data = dialogUpdate.getData(1);
            if (dialogUpdate.transaction() && !data.contains("")) {
                QString strQuery = "update allDeliveries set id_book = %1, count = %2 where id %3;";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], data[1], QString::number(rowIndex(currentRow))));
            }
            break;
        }

        case 2: {
            dialogUpdate.getWindow(2);
            dialogUpdate.exec();
            const QStringList& data = dialogUpdate.getData(2);
            if (dialogUpdate.transaction() && !data.contains("")) {
                QString strQuery = "update author set fio = '%1', address = '%2' where id = %3;";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], data[1], QString::number(rowIndex(currentRow))));
            }
            break;
        }

        case 3: {
            dialogUpdate.getWindow(3);
            dialogUpdate.exec();
            const QStringList& data = dialogUpdate.getData(3);
            if (dialogUpdate.transaction() && !data.contains("")) {
                QString strQuery = "update book set name = '%1', id_author = %2, id_typeStyle = %3, yea = %4, countList = %5 where id = %6";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], data[1], data[2], data[3], data[4], QString::number(rowIndex(currentRow))));
            }
            break;
        }

        case 4: {
            dialogUpdate.getWindow(4);
            dialogUpdate.exec();
            const QStringList& data = dialogUpdate.getData(4);
            if (dialogUpdate.transaction() && !data.contains("")) {
                QString strQuery = "update logs set nameAction = '%1', date = '%2', nameTable = '%3' where id = %4";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], data[1], data[2], QString::number(rowIndex(currentRow))));
            }
            break;
        }

        case 5: {
            dialogUpdate.getWindow(5);
            dialogUpdate.exec();
            const QStringList& data = dialogUpdate.getData(5);
            if (dialogUpdate.transaction() && !data.contains("")) {
                QString strQuery = "update marketBook set date = '%1', id_action = %2, id_staffMember = %3, id_book = %4, count = %5, price = %6 where id = %7";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], data[1], data[2], data[3], data[4], data[5], QString::number(rowIndex(currentRow))));
            }
            break;
        }

        case 6: {
            dialogUpdate.getWindow(6);
            dialogUpdate.exec();
            const QStringList& data = dialogUpdate.getData(6);
            if (dialogUpdate.transaction() && !data.contains("")) {
                QString strQuery = "update staffMember set fio = '%1', numberPhone = %2, inn = %3 where id = %4";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], data[1], data[2], QString::number(rowIndex(currentRow))));
            }
            break;
        }

        case 7: {
            dialogUpdate.getWindow(7);
            dialogUpdate.exec();
            const QStringList& data = dialogUpdate.getData(7);
            if (dialogUpdate.transaction() && !data.contains("")) {
                QString strQuery = "update typeStyle set nameStyle = '%1' where id = %2";
                databaseQuery.execQuery(QString(strQuery).arg(data[0], QString::number(rowIndex(currentRow))));
            }
            break;
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    db.setDatabaseName("lab.db");
    databaseQuery databaseQuery;

    if (!db.isOpen())
        db.open();

    const int currentRow = ui->tableWidget->currentItem()->row()+1, tableIndex = ui->comboBox->currentIndex();
    QStringList tableNames = {"action", "allDeliveries", "author", "book", "logs", "marketBook", "staffMember", "typeStyle"};

    if (0 <= tableIndex && tableIndex < tableNames.size()) {
        QString strQuery = "delete from %1 where id = %2";
        databaseQuery.execQuery(QString(strQuery).arg(tableNames[tableIndex]).arg(rowIndex(currentRow)));
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

    int i = 1;
    query.exec(QString("select * from %1").arg(strTable));
    while(query.next()) {
        st[i] = query.value(0).toInt();
        ++i;
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

    out << "<html>\n" << "<head>\n"
           "<style>\n"
           "table {\n"
           "font-family: \"Lucida Sans Unicode\", \"Lucida Grande\", Sans-Serif;\n"
           "font-size: 14px;\n"
           "background: white;\n"
           "max-width: 70%;\n"
           "width: 70%;\n"
           "border-collapse: collapse;\n"
           "text-align: left;\n"
           "}\n"
           "th {\n"
           "font-weight: normal;\n"
           "color: #039;\n"
           "border-bottom: 2px solid #6678b1;\n"
           "padding: 10px 8px;\n"
           "}\n"
           "td {\n"
           "border-bottom: 1px solid #ccc;\n"
           "color: #669;\n"
           "padding: 9px 8px;\n"
           "transition: .3s; linear;\n"
           "}\n"
           "tr:hover td {\n"
           "color: #6699ff;\n"
           "}\n"
           "</style>\n"
        << QString("<title>%1</title>").arg("lab")
        << "</head>\n"
           "<body bgcolor = #f0f0f0>\n"
           "<table>\n";

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

   QMessageBox::about(this, "Отчет", "Формирование отчета выполнено успешно");
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
        ui->pushButton->setStyleSheet("background-color: #d9d9d9;");
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_2->setStyleSheet("background-color: #d9d9d9;");
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_3->setStyleSheet("background-color: #d9d9d9;");
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_6->setStyleSheet("background-color: #d9d9d9;");
    }
    else {
        ui->pushButton->setEnabled(true);
        ui->pushButton->setStyleSheet("background-color: #f1f1f1;"
                                      "#pushButton:hover {background-color: #e0e0e0;}");
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_2->setStyleSheet("background-color: #f1f1f1;"
                                        "#pushButton_2:hover {background-color: #e0e0e0;}");
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_3->setStyleSheet("background-color: #f1f1f1;"
                                        "#pushButton_3:hover {background-color: #e0e0e0;}");
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_6->setStyleSheet("background-color: #f1f1f1;"
                                        "#pushButton_3:hover {background-color: #e0e0e0;}");
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    searchDB search;
    search.setModal(true);

    const int currentIndex = ui->comboBox->currentIndex();
    switch (currentIndex) {
        case 0: {
            search.getWindow(0);
            search.exec();
            break;
        }

        case 1: {
            search.getWindow(1);
            search.exec();
            break;
        }

        case 2: {
            search.getWindow(2);
            search.exec();
            break;
        }

        case 3: {
            search.getWindow(3);
            search.exec();
            break;
        }

        case 4: {
            search.getWindow(4);
            search.exec();
            break;
        }

        case 5: {
            search.getWindow(5);
            search.exec();
            break;
        }

        case 6: {
            search.getWindow(6);
            search.exec();
            break;
        }

        case 7: {
            search.getWindow(7);
            search.exec();
            break;
        }
    }
}
