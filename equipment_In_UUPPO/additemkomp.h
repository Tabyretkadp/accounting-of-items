#ifndef ADDITEMKOMP_H
#define ADDITEMKOMP_H

#include <QWidget>

namespace Ui {
class addItemKomp;
}

class addItemKomp : public QWidget
{
    Q_OBJECT

public:
    explicit addItemKomp(QWidget *parent = nullptr);
    ~addItemKomp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addItemKomp *ui;

signals:
    void signalItemKomp(QString, QString, QString, QString, QString);
};

#endif // ADDITEMKOMP_H
