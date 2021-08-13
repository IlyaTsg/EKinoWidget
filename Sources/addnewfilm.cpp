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
    // Open database
    QSqlDatabase films = QSqlDatabase::addDatabase("QSQLITE");
    films.setDatabaseName("ekino.db");
    if(!films.open()){ // Open's error
        qDebug() << films.lastError().text();
        qDebug() << "Open's error!";
    }

    // Edit database
    QSqlQuery query( films );
    QString insert_str = "INSERT INTO films (title, director_name, genre, release_date, rating_imdb, rating_kinop, kinopoisk_star)"
                               "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', %7);";
    insert_str = insert_str.arg(ui->EdTitle->text())
            .arg(ui->EdDirecor_name->text())
            .arg(ui->EdGenre->text())
            .arg(ui->EdDate->text())
            .arg(ui->EdIMDb->text())
            .arg(ui->EdKinoP->text())
            .arg(ui->EdStar->text());
    if(!query.exec(insert_str)){ // INSERT error's
        qDebug() << films.lastError().text();
        qDebug() << "INSERT error!";
    }

    hide();
    films.close();
    emit EditCatalog(); // Возврат к предыдущему пункту меню    
}
