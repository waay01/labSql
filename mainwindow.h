#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QSqlQuery>
#include <iostream>

#include "databaseQuery.h"
#include "dialogbook.h"
#include "dialogupdate.h"
#include "addnametable.h"


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

    void slotAdd();

    void slotEdit();

    void slotDelete();

    void slotContexMenu(QPoint pos);
    void on_pushButton_5_clicked();

    void on_actionAdd_Table_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
