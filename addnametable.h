#ifndef ADDNAMETABLE_H
#define ADDNAMETABLE_H

#include <QDialog>

namespace Ui {
class addNameTable;
}

class addNameTable : public QDialog
{
    Q_OBJECT

public:
    explicit addNameTable(QWidget *parent = nullptr);
    ~addNameTable();

    QString getName();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addNameTable *ui;
};

#endif // ADDNAMETABLE_H
