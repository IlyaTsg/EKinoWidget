#include "wedit.h"
#include "ui_wedit.h"

WEdit::WEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WEdit)
{
    ui->setupUi(this);
    AddWindow = new AddNewFilm();
    connect(AddWindow, SIGNAL(GiveListToEvery(film*)), this, SLOT(GetList(film*)));
    connect(AddWindow, &AddNewFilm::EditCatalog, this, &WEdit::show);
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


void WEdit::on_BBack_clicked()
{
    hide();
    emit MainMenu();
}

void WEdit::GetList(film *list)
{
    std::cout << list->title << std::endl;
}
