#pragma once
#ifndef ADDNEWFILM_H
#define ADDNEWFILM_H

#include <QWidget>
#include "ekino.h"

namespace Ui {
class AddNewFilm;
}

class AddNewFilm : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewFilm(QWidget *parent = nullptr);
    ~AddNewFilm();

signals:
    void EditCatalog();
    void GiveListToEvery(film *list);

private slots:
    void on_BAdd_clicked();

private:
    Ui::AddNewFilm *ui;
};

#endif // ADDNEWFILM_H
