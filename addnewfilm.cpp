#include "addnewfilm.h"
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

film *MakeList()
{
    film *first_el = NULL;
    if((first_el = (film*)malloc(sizeof(film)))){
        first_el->prev = NULL;
        first_el->next = NULL;
    }else std::cout << "Memory allocation! Func: MakeList" << std::endl;
    return first_el;
}

void InsertAfter(film *cur_el, film *new_el)
{
    if(new_el&&cur_el){
        if(!cur_el->next || cur_el->next==new_el){
            cur_el->next = new_el;
            new_el->next = NULL;
        }
        else{
            new_el->next = cur_el->next;
            new_el->next->prev = new_el;
            cur_el->next = new_el;
        }
        new_el->prev = cur_el;
    }
}

void AddNewFilm::on_BAdd_clicked()
{
    film *list = NULL;
    film *tmp_el = NULL;

    tmp_el = list;

    while(list){
        tmp_el = list;
        list = list->next;
    }
    list = MakeList();
    InsertAfter(tmp_el, list);


    if(list){
        list->title = (ui->EdTitle->text()).toStdString(); // Копирование информации из поля в структуру
        list->director_name = (ui->EdDirecor_name->text()).toStdString();
        list->genre = (ui->EdGenre->text()).toStdString();
        list->realese_date = (ui->EdDate->text()).toStdString();

        list->rating[0] = (ui->EdIMDb->text()).toFloat();
        list->rating[1] = (ui->EdKinoP->text()).toFloat();
        list->kinopoisk_star = (ui->EdStar->text()).toUInt();
    }else std::cout << "Memory allocation! Func: ListFromKeyboard" << std::endl;
    while(list->prev) list = list->prev;
    hide();
    emit GiveListToEvery(list); // Отправка списка всем формам
    emit EditCatalog(); // Возврат назад
}
