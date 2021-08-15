#include "../EKinoWidget/Headers/wedit.h"
#include "ui_wedit.h"

WEdit::WEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WEdit)
{
    ui->setupUi(this);
    AddWindow = new AddNewFilm();
    DelWindow = new WDelete();
    ChangeWindow = new WChange();
    connect(AddWindow, &AddNewFilm::EditCatalog, this, &WEdit::show);
    connect(DelWindow, &WDelete::EditCatalog, this, &WEdit::show);
    connect(ChangeWindow, &WChange::EditCatalog, this, &WEdit::show);
}

WEdit::~WEdit()
{
    delete ui;
}

void WEdit::on_BAdd_clicked()
{
    AddWindow->show();
    hide();
}

void WEdit::on_BDel_clicked()
{
    DelWindow->show();
    hide();
}

void WEdit::on_BBack_clicked()
{
    hide();
    emit MainMenu();
}

void WEdit::on_BEdit_clicked()
{
    ChangeWindow->show();
    hide();
}

