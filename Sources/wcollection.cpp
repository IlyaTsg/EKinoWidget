#include "../Headers/wcollection.h"
#include "ui_wcollection.h"

WCollection::WCollection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WCollection)
{
    ui->setupUi(this);
}

WCollection::~WCollection()
{
    delete ui;
}

void WCollection::on_BBack_clicked()
{
    hide();
    emit MainMenu();
}

