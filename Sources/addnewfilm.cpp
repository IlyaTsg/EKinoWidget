#include "../Headers/addnewfilm.h"
#include "ui_addnewfilm.h"

AddNewFilm::AddNewFilm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewFilm)
{
    ui->setupUi(this);
}

AddNewFilm::~AddNewFilm()
{
    delete ui;
}

void AddNewFilm::on_BAdd_clicked()
{
    emit EditCatalog(); // Возврат к предыдущему пункту меню
}
