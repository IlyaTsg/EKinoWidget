#pragma once
#ifndef WEDIT_H
#define WEDIT_H

#include <QWidget>
#include "addnewfilm.h"

namespace Ui {
class WEdit;
}

class WEdit : public QWidget
{
    Q_OBJECT

public:
    explicit WEdit(QWidget *parent = nullptr);
    ~WEdit();

signals:
    void MainMenu();

private slots:
    void on_BAdd_clicked();

    void on_BBack_clicked();

    void GetList(film *list);

private:
    Ui::WEdit *ui;
    AddNewFilm *AddWindow;
};

#endif // WEDIT_H
