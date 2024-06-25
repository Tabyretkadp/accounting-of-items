#include "additemkomp.h"
#include "ui_additemkomp.h"

addItemKomp::addItemKomp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addItemKomp)
{
    ui->setupUi(this);
}

addItemKomp::~addItemKomp()
{
    delete ui;
}

void addItemKomp::on_pushButton_clicked()
{
    emit signalItemKomp(ui->proc->text(), ui->bp->text(), ui->mama->text(), ui->videoK->text(), ui->pamat->text());
    close();
}

