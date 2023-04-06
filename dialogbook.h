#ifndef DIALOGBOOK_H
#define DIALOGBOOK_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class DialogBook;
}

class DialogBook : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBook(QWidget *parent = nullptr);
    ~DialogBook();

    QStringList getData();

    void setName(QString name);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogBook *ui;
};

#endif // DIALOGBOOK_H
