#include "../Headers/wchange.h"
#include "ui_wchange.h"

WChange::WChange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WChange)
{
    ui->setupUi(this);
}

WChange::~WChange()
{
    delete ui;
}

void WChange::on_BBack_clicked()
{
    hide();
    emit EditCatalog();
}

