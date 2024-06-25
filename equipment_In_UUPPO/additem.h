#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>

namespace Ui {
class addItem;
}

class addItem : public QDialog
{
    Q_OBJECT

public:
    explicit addItem(QWidget *parent = nullptr);
    ~addItem();

private:
    Ui::addItem *ui;

signals:
    void sifnalItem(QString, QString, QString, QString, QString);
private slots:
    void on_pushButton_clicked();
};

#endif // ADDITEM_H
