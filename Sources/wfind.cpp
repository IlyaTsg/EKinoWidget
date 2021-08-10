#include "../Headers/wfind.h"
#include "ui_wfind.h"

WFind::WFind(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WFind)
{
    ui->setupUi(this);
}

WFind::~WFind()
{
    delete ui;
}

void WFind::on_BBack_clicked()
{
    hide();
    emit MainMenu();
}

