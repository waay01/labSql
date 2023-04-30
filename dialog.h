#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class dialog;
}

class dialog : public QDialog
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = nullptr);
    ~dialog();

    void getWindow(int index);

    void sendData(int index, const QVector<QStringList>& itemList);

    QStringList getData(int index);

    void setName(const QString& name);

    bool transaction();

private slots:

    void on_pushButton_clicked();

private:
    Ui::dialog *ui;
};

#endif // DIALOG_H
