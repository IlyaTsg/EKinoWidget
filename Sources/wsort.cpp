#include "../Headers/wsort.h"
#include "ui_wsort.h"

WSort::WSort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WSort)
{
    ui->setupUi(this);
}

WSort::~WSort()
{
    delete ui;
}

void WSort::on_BBack_clicked()
{
    hide();
    emit MainMenu();
}

