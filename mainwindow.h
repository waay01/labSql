#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QSqlQuery>
#include <QFile>
#include <QMessageBox>

#include "databaseQuery.h"
#include "addnametable.h"
#include "dialog.h"
#include "searchDB.h"

#include "qtextdocument.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void slotContexMenu(QPoint pos);

    void on_pushButton_5_clicked();

    void on_actionAdd_Table_triggered();

    void on_comboBox_activated(int index);

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
