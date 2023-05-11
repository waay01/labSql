#include "searchdb.h"
#include "ui_searchdb.h"

searchDB::searchDB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchDB)
{
    ui->setupUi(this);
    for (auto lineEdit : {ui->lineEdit, ui->lineEdit_2, ui->lineEdit_3, ui->lineEdit_4, ui->lineEdit_5, ui->lineEdit_6, ui->lineEdit_7, ui->lineEdit_8, ui->lineEdit_9, ui->lineEdit_10, ui->lineEdit_11, ui->lineEdit_12, ui->lineEdit_13, ui->lineEdit_14, ui->lineEdit_15, ui->lineEdit_16, ui->lineEdit_17, ui->lineEdit_18, ui->lineEdit_19, ui->lineEdit_20, ui->lineEdit_21, ui->lineEdit_22, ui->lineEdit_23, ui->lineEdit_24, ui->lineEdit_25, ui->lineEdit_26, ui->lineEdit_27, ui->lineEdit_28, ui->lineEdit_29, ui->lineEdit_30, ui->lineEdit_31}) {
        lineEdit->setEnabled(false);
    }
}

searchDB::~searchDB()
{
    delete ui;
}

void searchDB::getWindow(int index) {
    ui->stackedWidget->setCurrentIndex(index);
}

void searchDB::on_pushButton_4_clicked()
{
    close();
}

void searchDB::onCheckBoxStateChanged(QCheckBox* checkBox, QLineEdit* lineEdit)
{
    if (checkBox->isChecked())
        lineEdit->setEnabled(true);
    else {
        lineEdit->setEnabled(false);
        lineEdit->setText("");
    }
}

void searchDB::on_checkBox_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox, ui->lineEdit);
}

void searchDB::on_checkBox_2_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_2, ui->lineEdit_2);
}

void searchDB::on_checkBox_3_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_3, ui->lineEdit_3);
}

void searchDB::on_checkBox_4_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_4, ui->lineEdit_4);
}

void searchDB::on_checkBox_5_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_5, ui->lineEdit_5);
}

void searchDB::on_checkBox_6_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_6, ui->lineEdit_6);
}

void searchDB::on_checkBox_7_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_7, ui->lineEdit_7);
}

void searchDB::on_checkBox_8_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_8, ui->lineEdit_8);
}

void searchDB::on_checkBox_9_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_9, ui->lineEdit_9);
}

void searchDB::on_checkBox_10_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_10, ui->lineEdit_10);
}

void searchDB::on_checkBox_11_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_11, ui->lineEdit_11);
}

void searchDB::on_checkBox_12_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_12, ui->lineEdit_12);
}

void searchDB::on_checkBox_13_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_13, ui->lineEdit_13);
}

void searchDB::on_checkBox_14_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_14, ui->lineEdit_14);
}

void searchDB::on_checkBox_15_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_15, ui->lineEdit_15);
}

void searchDB::on_checkBox_16_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_16, ui->lineEdit_16);
}

void searchDB::on_checkBox_17_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_17, ui->lineEdit_17);
}

void searchDB::on_checkBox_18_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_18, ui->lineEdit_18);
}

void searchDB::on_checkBox_19_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_19, ui->lineEdit_19);
}

void searchDB::on_checkBox_20_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_20, ui->lineEdit_20);
}

void searchDB::on_checkBox_21_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_21, ui->lineEdit_21);
}

void searchDB::on_checkBox_22_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_22, ui->lineEdit_22);
}

void searchDB::on_checkBox_23_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_23, ui->lineEdit_23);
}

void searchDB::on_checkBox_24_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_24, ui->lineEdit_24);
}

void searchDB::on_checkBox_25_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_25, ui->lineEdit_25);
}

void searchDB::on_checkBox_26_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_26, ui->lineEdit_26);
}

void searchDB::on_checkBox_27_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_27, ui->lineEdit_27);
}

void searchDB::on_checkBox_28_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_28, ui->lineEdit_28);
}

void searchDB::on_checkBox_29_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_29, ui->lineEdit_29);
}

void searchDB::on_checkBox_30_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_30, ui->lineEdit_30);
}

void searchDB::on_checkBox_31_stateChanged(int arg1)
{
    onCheckBoxStateChanged(ui->checkBox_31, ui->lineEdit_31);
}


void searchDB::on_pushButton_clicked()
{
    QList nameTable = {"action", "allDeliveries", "author", "book", "logs", "marketBook", "staffMember", "typeStyle"};
    MainWindow mWindow;
    std::map<int, int> st;
    int countRow = 0, countColumn = 0;
    QStringList nameColumn, itemList;

    QString strTable = nameTable[ui->stackedWidget->currentIndex()];

    databaseQuery databaseQuery;
    nameColumn = databaseQuery.execQueryPRAGMA(strTable);
    countColumn = nameColumn.size();

//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    db.setDatabaseName("lab.db");
    db.open();

    switch(ui->stackedWidget->currentIndex()) {
        case 0: {
            const QStringList& data = {ui->lineEdit->text(), ui->lineEdit_2->text()};
            query.exec(QString("select * from %1 where ID like '%%2%' and NameAction like '%%3%'").arg(strTable, data[0], data[1]));
            break;
        }

        case 1: {
            const QStringList& data = {ui->lineEdit_3->text(), ui->lineEdit_4->text(), ui->lineEdit_5->text()};
            query.exec(QString("select * from %1 where ID like '%%2%' and id_book like '%%3%' and count >= %4").arg(strTable, data[0], data[1], data[2]));
            break;
        }

        case 2: {
            const QStringList& data = {ui->lineEdit_6->text(), ui->lineEdit_7->text(), ui->lineEdit_8->text()};
            query.exec(QString("select * from %1 where ID like '%%2%' and fio like '%%3%' and address like '%%4%'").arg(strTable, data[0], data[1], data[2]));
            break;
        }

        case 3: {
            const QStringList& data = {ui->lineEdit_9->text(), ui->lineEdit_10->text(), ui->lineEdit_11->text(), ui->lineEdit_12->text(), ui->lineEdit_13->text(), ui->lineEdit_14->text()};
            query.exec(QString("select * from %1 where ID like '%%2%' and name like '%%3%' and id_author like '%%4%' and id_typeStyle like '%%5%' and year >= %6 and countList >= %7").arg(strTable, data[0], data[1], data[2], data[3], data[4], data[5]));
            break;
        }

        case 4: {
            const QStringList& data = {ui->lineEdit_15->text(), ui->lineEdit_16->text(), ui->lineEdit_17->text(), ui->lineEdit_18->text()};
            query.exec(QString("select * from %1 where ID like '%%2%' and nameAction like '%%3%' and date like '%%4%' and nameTable like '%%5%'").arg(strTable, data[0], data[1], data[2], data[3]));
            break;
        }

        case 5: {
            const QStringList& data = {ui->lineEdit_19->text(), ui->lineEdit_20->text(), ui->lineEdit_21->text(), ui->lineEdit_22->text(), ui->lineEdit_23->text(), ui->lineEdit_24->text(), ui->lineEdit_25->text()};
            query.exec(QString("select * from %1 where ID like '%%2%' and date like '%%3%' and id_action like '%%4%' and id_staffMember like '%%5%' and id_book like '%%6%' and count >= %7 and price >= %8").arg(strTable, data[0], data[1], data[2], data[3], data[4], data[5], data[6]));
            break;
        }

        case 6: {
            const QStringList& data = {ui->lineEdit_26->text(), ui->lineEdit_27->text(), ui->lineEdit_28->text(), ui->lineEdit_29->text()};
            query.exec(QString("select * from %1 where ID like '%%2%' and fio like '%%3%' and numberPhone like '%%4%' and inn like '%%5%'").arg(strTable, data[0], data[1], data[2], data[3]));
            break;
        }

        case 7: {
            const QStringList& data = {ui->lineEdit_30->text(), ui->lineEdit_31->text()};
            query.exec(QString("select * from %1 where ID like '%%2%' and nameStyle like '%%3%'").arg(strTable, data[0], data[1]));
            break;
        }
    }
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

void searchDB::on_pushButton_2_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableWidget->rowCount();
    const int columnCount = ui->tableWidget->columnCount();

    out << "<html>\n" << "<head>\n"
           "<style>\n"
           "body {"
             "margin: 0;"
             "padding: 24px;"
             "font-family: 'Source Sans Pro', sans-serif;"
           "}"

          " table {"
             "width: 100%;"
             "border: 1px solid #eee;"
             "border-collapse: collapse;"
           "}"

           "thead {"
             "background-color: #000;"
             "color: #fff;"
           "}"

           "th,"
           "td {"
             "padding: 12px;"
             "text-align: center;"
             "color: black;"
           "}"

           "th {"
             "text-transform: uppercase;"
           "}"

           "tr:nth-of-type(odd) {"
             "background-color: #f0dfce;"
           "}"
           "</style>\n"
        << QString("<title>%1</title>").arg("lab")
        << "</head>\n"
           "<body>\n"
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
