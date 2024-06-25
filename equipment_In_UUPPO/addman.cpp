#include "addman.h"
#include "ui_addman.h"

addMan::addMan(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addMan)
{
    ui->setupUi(this);
}

addMan::~addMan()
{
    delete ui;
}

void addMan::on_pushButton_clicked()
{
    emit signal(ui->nameMan->text(), ui->familyMan->text(), ui->otchestvoMan->text());
    close();
}

