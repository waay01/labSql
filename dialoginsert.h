#ifndef DIALOGINSERT_H
#define DIALOGINSERT_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class dialogInsert;
}

class dialogInsert : public QDialog
{
    Q_OBJECT

public:
    explicit dialogInsert(QWidget *parent = nullptr);
    ~dialogInsert();

    void getWindow(int index);

    QStringList getData(int index);

    void setName(QString name);

private slots:

    void on_pushButton_clicked();

private:
    Ui::dialogInsert *ui;
};

#endif // DIALOGINSERT_H
