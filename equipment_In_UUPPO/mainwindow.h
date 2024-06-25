#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QVBoxLayout>
#include <QScrollArea>

#include "addman.h"
#include "additem.h"
#include "additemkomp.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addMen_clicked();

    void on_addMen_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_addMen_3_clicked();

    void initDatabase();

    void saveData();

    void loadData();


    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    addMan *addman;
    addItem *additem;
    addItemKomp *additemkomp;

    int originalWidgetWidth = 0;
    int originalScrollWidth = 0;

public slots:
    void slot(QString a, QString b, QString C);
    void slotItem(QString q, QString w, QString e, QString r, QString t);
    void slotItemKomp(QString a, QString s, QString d, QString f, QString g);
};
#endif // MAINWINDOW_H
