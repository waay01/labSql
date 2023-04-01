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

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogUpdate *ui;
    MainWindow *mainWindow;
};

#endif // DIALOGUPDATE_H
