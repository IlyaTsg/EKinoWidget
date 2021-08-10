#include "../Headers/wdelete.h"
#include "ui_wdelete.h"

WDelete::WDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WDelete)
{
    ui->setupUi(this);
}

WDelete::~WDelete()
{
    delete ui;
}

void WDelete::on_BBack_clicked()
{
    hide();
    emit EditCatalog();
}
