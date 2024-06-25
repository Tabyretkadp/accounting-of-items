#ifndef ADDMAN_H
#define ADDMAN_H

#include <QDialog>

namespace Ui {
class addMan;
}

class addMan : public QDialog
{
    Q_OBJECT

public:
    explicit addMan(QWidget *parent = nullptr);
    ~addMan();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addMan *ui;

signals:
    void signal(QString, QString, QString);
};

#endif // ADDMAN_H
