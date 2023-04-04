#ifndef DIALOGUPDATE_H
#define DIALOGUPDATE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class DialogUpdate;
}

class DialogUpdate : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUpdate(QWidget *parent = nullptr);
    ~DialogUpdate();

    QStringList getData();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogUpdate *ui;
};

#endif // DIALOGUPDATE_H
