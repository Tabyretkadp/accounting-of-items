#include "additem.h"
#include "ui_additem.h"

addItem::addItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addItem)
{
    ui->setupUi(this);
}

addItem::~addItem()
{
    delete ui;
}

void addItem::on_pushButton_clicked()
{
    emit sifnalItem(ui->miska->text(), ui->klava->text(), ui->mikro->text(), ui->monik->text(), ui->yshi->text());
    close();
}

