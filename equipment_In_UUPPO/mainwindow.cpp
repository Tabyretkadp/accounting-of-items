#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QScrollArea>
#include <QScrollBar>
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    initDatabase();

    addman = new addMan;
    additem = new addItem;
    additemkomp = new addItemKomp;
    connect(addman, &addMan::signal, this, &MainWindow::slot);
    connect(additem, &addItem::sifnalItem, this, &MainWindow::slotItem);
    connect(additemkomp, &addItemKomp::signalItemKomp, this, &MainWindow::slotItemKomp);

    loadData();
}

MainWindow::~MainWindow()
{
    saveData();

    delete ui;
    delete addman;
    delete additem;
    delete additemkomp;
}

void MainWindow::initDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");

    if (!db.open()) {
        qDebug() << "Error: connection with database fail";
    } else {
        qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS man (a TEXT, b TEXT, c TEXT)");
    query.exec("CREATE TABLE IF NOT EXISTS item (q TEXT, w TEXT, e TEXT, r TEXT, t TEXT)");
    query.exec("CREATE TABLE IF NOT EXISTS itemkomp (a TEXT, s TEXT, d TEXT, f TEXT, g TEXT)");
}

void MainWindow::saveData()
{
    QSqlQuery query;

    // Save data from `men`
    query.exec("DELETE FROM man");
    query.prepare("INSERT INTO man (a, b, c) VALUES (?, ?, ?)");
    query.addBindValue(ui->men->text().split(" ")[0]);
    query.addBindValue(ui->men->text().split(" ")[1]);
    query.addBindValue(ui->men->text().split(" ")[2]);
    query.exec();

    // Save data from `item`
    query.exec("DELETE FROM item");
    query.prepare("INSERT INTO item (q, w, e, r, t) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(ui->miskaL->text());
    query.addBindValue(ui->klavaL->text());
    query.addBindValue(ui->mikroL->text());
    query.addBindValue(ui->moniL->text());
    query.addBindValue(ui->yshiL->text());
    query.exec();

    // Save data from `itemkomp`
    query.exec("DELETE FROM itemkomp");
    query.prepare("INSERT INTO itemkomp (a, s, d, f, g) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(ui->procL->text());
    query.addBindValue(ui->bpL->text());
    query.addBindValue(ui->mamaL->text());
    query.addBindValue(ui->vidoKL->text());
    query.addBindValue(ui->pamatL->text());
    query.exec();
}

void MainWindow::loadData()
{
    QSqlQuery query;

    // Load data for `men`
    query.exec("SELECT * FROM man");
    if (query.next()) {
        QString a = query.value(0).toString();
        QString b = query.value(1).toString();
        QString c = query.value(2).toString();
        ui->men->setText(a + " " + b + " " + c);
    }

    // Load data for `item`
    query.exec("SELECT * FROM item");
    if (query.next()) {
        QString q = query.value(0).toString();
        QString w = query.value(1).toString();
        QString e = query.value(2).toString();
        QString r = query.value(3).toString();
        QString t = query.value(4).toString();
        ui->miskaL->setText(q);
        ui->klavaL->setText(w);
        ui->mikroL->setText(e);
        ui->moniL->setText(r);
        ui->yshiL->setText(t);
    }

    // Load data for `itemkomp`
    query.exec("SELECT * FROM itemkomp");
    if (query.next()) {
        QString a = query.value(0).toString();
        QString s = query.value(1).toString();
        QString d = query.value(2).toString();
        QString f = query.value(3).toString();
        QString g = query.value(4).toString();
        ui->procL->setText(a);
        ui->bpL->setText(s);
        ui->mamaL->setText(d);
        ui->vidoKL->setText(f);
        ui->pamatL->setText(g);
    }
}

void MainWindow::on_addMen_clicked()
{
    addman->show();
}

void MainWindow::slot(QString a, QString b, QString c)
{
    ui->men->setText(a + " " + b + " " + c);
}

void MainWindow::slotItem(QString q, QString w, QString e, QString r, QString t)
{
    ui->miskaL->setText(q);
    ui->klavaL->setText(w);
    ui->mikroL->setText(e);
    ui->moniL->setText(r);
    ui->yshiL->setText(t);
}

void MainWindow::slotItemKomp(QString a, QString s, QString d, QString f, QString g)
{
    ui->procL->setText(a);
    ui->bpL->setText(s);
    ui->mamaL->setText(d);
    ui->vidoKL->setText(f);
    ui->pamatL->setText(g);
}


void MainWindow::on_addMen_2_clicked()
{
    additem->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    additemkomp->show();
}

void MainWindow::on_pushButton_clicked()
{
    QScrollArea *scroll = ui->scrollArea;

    QWidget *scrollWidget = scroll->widget();
    if (!scrollWidget) {
        scrollWidget = new QWidget();
        scroll->setWidget(scrollWidget);
    }

    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());
    if (!scrollLayout) {
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    QLabel *lForLayout = new QLabel;
    lForLayout->setText(ui->miskaL->text());

    scrollLayout->addWidget(lForLayout);
    scrollLayout->setAlignment(Qt::AlignTop);

    scroll->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { background: #CCCCCC; width: 1px; }"
                                                "QScrollBar::handle:vertical { background: #999999; }"
                                                "QScrollBar::add-line:vertical { background: none; }"
                                                "QScrollBar::sub-line:vertical { background: none; }");

    ui->miskaL->clear();
}

void MainWindow::on_pushButton_5_clicked()
{
    QScrollArea *scroll = ui->scrollArea;

    QWidget *scrollWidget = scroll->widget();
    if (!scrollWidget) {
        scrollWidget = new QWidget();
        scroll->setWidget(scrollWidget);
    }

    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());
    if (!scrollLayout) {
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    QLabel *lForLayout = new QLabel;
    lForLayout->setText(ui->klavaL->text());

    scrollLayout->addWidget(lForLayout);
    scrollLayout->setAlignment(Qt::AlignTop);

    scroll->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { background: #CCCCCC; width: 1px; }"
                                               "QScrollBar::handle:vertical { background: #999999; }"
                                               "QScrollBar::add-line:vertical { background: none; }"
                                               "QScrollBar::sub-line:vertical { background: none; }");

    ui->klavaL->clear();
}

void MainWindow::on_pushButton_6_clicked()
{
    QScrollArea *scroll = ui->scrollArea;

    QWidget *scrollWidget = scroll->widget();
    if (!scrollWidget) {
        scrollWidget = new QWidget();
        scroll->setWidget(scrollWidget);
    }

    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());
    if (!scrollLayout) {
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    QLabel *lForLayout = new QLabel;
    lForLayout->setText(ui->moniL->text());

    scrollLayout->addWidget(lForLayout);
    scrollLayout->setAlignment(Qt::AlignTop);

    scroll->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { background: #CCCCCC; width: 1px; }"
                                               "QScrollBar::handle:vertical { background: #999999; }"
                                               "QScrollBar::add-line:vertical { background: none; }"
                                               "QScrollBar::sub-line:vertical { background: none; }");

    ui->moniL->clear();
}

void MainWindow::on_pushButton_7_clicked()
{
    QScrollArea *scroll = ui->scrollArea;

    QWidget *scrollWidget = scroll->widget();
    if (!scrollWidget) {
        scrollWidget = new QWidget();
        scroll->setWidget(scrollWidget);
    }

    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());
    if (!scrollLayout) {
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    QLabel *lForLayout = new QLabel;
    lForLayout->setText(ui->yshiL->text());

    scrollLayout->addWidget(lForLayout);
    scrollLayout->setAlignment(Qt::AlignTop);

    scroll->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { background: #CCCCCC; width: 1px; }"
                                               "QScrollBar::handle:vertical { background: #999999; }"
                                               "QScrollBar::add-line:vertical { background: none; }"
                                               "QScrollBar::sub-line:vertical { background: none; }");

    ui->yshiL->clear();
}

void MainWindow::on_pushButton_8_clicked()
{
    QScrollArea *scroll = ui->scrollArea;

    QWidget *scrollWidget = scroll->widget();
    if (!scrollWidget) {
        scrollWidget = new QWidget();
        scroll->setWidget(scrollWidget);
    }

    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());
    if (!scrollLayout) {
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    QLabel *lForLayout = new QLabel;
    lForLayout->setText(ui->mikroL->text());

    scrollLayout->addWidget(lForLayout);
    scrollLayout->setAlignment(Qt::AlignTop);

    scroll->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { background: #CCCCCC; width: 1px; }"
                                               "QScrollBar::handle:vertical { background: #999999; }"
                                               "QScrollBar::add-line:vertical { background: none; }"
                                               "QScrollBar::sub-line:vertical { background: none; }");

    ui->mikroL->clear();
}

void MainWindow::on_pushButton_9_clicked()
{
    QScrollArea *scroll = ui->scrollArea;

    QWidget *scrollWidget = scroll->widget();
    if (!scrollWidget) {
        scrollWidget = new QWidget();
        scroll->setWidget(scrollWidget);
    }

    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());
    if (!scrollLayout) {
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    QLabel *lForLayout = new QLabel;
    lForLayout->setText(ui->procL->text());

    scrollLayout->addWidget(lForLayout);
    scrollLayout->setAlignment(Qt::AlignTop);

    scroll->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { background: #CCCCCC; width: 1px; }"
                                               "QScrollBar::handle:vertical { background: #999999; }"
                                               "QScrollBar::add-line:vertical { background: none; }"
                                               "QScrollBar::sub-line:vertical { background: none; }");

    ui->procL->clear();
}

void MainWindow::on_pushButton_10_clicked()
{
    QScrollArea *scroll = ui->scrollArea;

    QWidget *scrollWidget = scroll->widget();
    if (!scrollWidget) {
        scrollWidget = new QWidget();
        scroll->setWidget(scrollWidget);
    }

    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());
    if (!scrollLayout) {
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    QLabel *lForLayout = new QLabel;
    lForLayout->setText(ui->bpL->text());

    scrollLayout->addWidget(lForLayout);
    scrollLayout->setAlignment(Qt::AlignTop);

    scroll->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { background: #CCCCCC; width: 1px; }"
                                               "QScrollBar::handle:vertical { background: #999999; }"
                                               "QScrollBar::add-line:vertical { background: none; }"
                                               "QScrollBar::sub-line:vertical { background: none; }");

    ui->bpL->clear();
}

void MainWindow::on_pushButton_11_clicked()
{
    QScrollArea *scroll = ui->scrollArea;

    QWidget *scrollWidget = scroll->widget();
    if (!scrollWidget) {
        scrollWidget = new QWidget();
        scroll->setWidget(scrollWidget);
    }

    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());
    if (!scrollLayout) {
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    QLabel *lForLayout = new QLabel;
    lForLayout->setText(ui->mamaL->text());

    scrollLayout->addWidget(lForLayout);
    scrollLayout->setAlignment(Qt::AlignTop);

    scroll->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { background: #CCCCCC; width: 1px; }"
                                               "QScrollBar::handle:vertical { background: #999999; }"
                                               "QScrollBar::add-line:vertical { background: none; }"
                                               "QScrollBar::sub-line:vertical { background: none; }");

    ui->mamaL->clear();
}

void MainWindow::on_pushButton_12_clicked()
{
    QScrollArea *scroll = ui->scrollArea;

    QWidget *scrollWidget = scroll->widget();
    if (!scrollWidget) {
        scrollWidget = new QWidget();
        scroll->setWidget(scrollWidget);
    }

    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());
    if (!scrollLayout) {
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    QLabel *lForLayout = new QLabel;
    lForLayout->setText(ui->vidoKL->text());

    scrollLayout->addWidget(lForLayout);
    scrollLayout->setAlignment(Qt::AlignTop);

    scroll->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { background: #CCCCCC; width: 1px; }"
                                               "QScrollBar::handle:vertical { background: #999999; }"
                                               "QScrollBar::add-line:vertical { background: none; }"
                                               "QScrollBar::sub-line:vertical { background: none; }");

    ui->vidoKL->clear();
}

void MainWindow::on_pushButton_13_clicked()
{
    QScrollArea *scroll = ui->scrollArea;

    QWidget *scrollWidget = scroll->widget();
    if (!scrollWidget) {
        scrollWidget = new QWidget();
        scroll->setWidget(scrollWidget);
    }

    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());
    if (!scrollLayout) {
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    QLabel *lForLayout = new QLabel;
    lForLayout->setText(ui->pamatL->text());

    scrollLayout->addWidget(lForLayout);
    scrollLayout->setAlignment(Qt::AlignTop);

    scroll->verticalScrollBar()->setStyleSheet("QScrollBar:vertical { background: #CCCCCC; width: 1px; }"
                                               "QScrollBar::handle:vertical { background: #999999; }"
                                               "QScrollBar::add-line:vertical { background: none; }"
                                               "QScrollBar::sub-line:vertical { background: none; }");

    ui->pamatL->clear();
}

void MainWindow::on_addMen_3_clicked()
{
    QScrollArea *scroll = ui->scrollArea;
    QWidget *scrollWidget = scroll->widget();

    if (scrollWidget) {
        QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout*>(scrollWidget->layout());
        if (scrollLayout) {
            while (QLayoutItem* item = scrollLayout->takeAt(0)) {
                QWidget *widget = item->widget();
                if (widget) {
                    widget->deleteLater();
                }
                delete item;
            }
            scrollWidget->update();
        }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->login->text() == "admin" && ui->password->text() == "12345") {
        ui->reger->hide();
    } else {
        ui->login->clear();
        ui->password->clear();
        ui->ppo->setText("Неправильный логин или пароль, попробуйте еще раз :)");
    }
}

