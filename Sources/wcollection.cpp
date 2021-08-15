#include "../EKinoWidget/Headers/wcollection.h"
#include "ui_wcollection.h"

static int id = 0;

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
    {
        id--;
        qDebug() << id;
        // Open database
        QSqlDatabase films = QSqlDatabase::addDatabase("QSQLITE", "ConName");
        films.setDatabaseName("ekino.db");
        if(!films.open()){ // Open's error
            qDebug() << films.lastError().text();
            qDebug() << "Open's error!";
            exit(-1);
        }
        QSqlQuery query( films );
        QSqlRecord rec;
        if(!query.exec("SELECT * FROM films WHERE id=" + QString::number(id))){
            qDebug() << films.lastError().text();
            exit(-2);
        }
        if(query.next()){ // Проверка на первый фильм
            ui->BNext->setEnabled(true); // Теперь можно нажимать на next
            QSqlRecord rec = query.record();
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
            emit MainMenu();
        }
        films.close();
    }
    QSqlDatabase::removeDatabase("ConName");
}


void WCollection::on_BNext_clicked()
{
    {
        id++;
        qDebug() << id;
        // Open database
        QSqlDatabase films = QSqlDatabase::addDatabase("QSQLITE", "ConName");
        films.setDatabaseName("ekino.db");
        if(!films.open()){ // Open's error
            qDebug() << films.lastError().text();
            qDebug() << "Open's error!";
            exit(-1);
        }
        QSqlQuery query( films );
        if(!query.exec("SELECT * FROM films WHERE id=" + QString::number(id))){
            qDebug() << films.lastError().text();
            exit(-2);
        }
        if(query.next()){
            QSqlRecord rec = query.record();
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
        films.close();
    }
    QSqlDatabase::removeDatabase("ConName");
}

