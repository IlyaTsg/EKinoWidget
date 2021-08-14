#include "../Headers/wcollection.h"
#include "ui_wcollection.h"

QSqlDatabase films = QSqlDatabase::addDatabase("QSQLITE");
QSqlQuery query( films );
QSqlRecord rec;

WCollection::WCollection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WCollection)
{
    ui->setupUi(this);

    // Open database
    films.setDatabaseName("ekino.db");
    if(!films.open()){ // Open's error
        qDebug() << films.lastError().text();
        qDebug() << "Open's error!";
        exit(-1);
    }
    if(!query.exec("SELECT * FROM films")){
        qDebug() << films.lastError().text();
        exit(-2);
    }
}

WCollection::~WCollection()
{
    delete ui;
}

void WCollection::on_BBack_clicked()
{
    if(query.previous()){ // Проверка на первый фильм
        ui->BNext->setEnabled(true); // Теперь можно нажимать на next
        rec = query.record();
        ui->LTitle->setText(query.value(rec.indexOf("title")).toString());
        ui->LDirector->setText(query.value(rec.indexOf("director_name")).toString());
        ui->LGenre->setText(query.value(rec.indexOf("genre")).toString());
        ui->LDate->setText(query.value(rec.indexOf("release_date")).toString());
        ui->LImdb->setText(query.value(rec.indexOf("rating_imdb")).toString());
        ui->Lkinop->setText(query.value(rec.indexOf("rating_kinop")).toString());
        ui->LStar->setText(query.value(rec.indexOf("kinopoisk_star")).toString());
    }
    else{
        hide();
        films.close();
        emit MainMenu();
    }
}


void WCollection::on_BNext_clicked()
{
    if(query.next()){
        rec = query.record();
        ui->LTitle->setText(query.value(rec.indexOf("title")).toString());
        ui->LDirector->setText(query.value(rec.indexOf("director_name")).toString());
        ui->LGenre->setText(query.value(rec.indexOf("genre")).toString());
        ui->LDate->setText(query.value(rec.indexOf("release_date")).toString());
        ui->LImdb->setText(query.value(rec.indexOf("rating_imdb")).toString());
        ui->Lkinop->setText(query.value(rec.indexOf("rating_kinop")).toString());
        ui->LStar->setText(query.value(rec.indexOf("kinopoisk_star")).toString());
    }
    else{ // Если фильмов большге нет
        ui->BNext->setEnabled(false);
    }
}

