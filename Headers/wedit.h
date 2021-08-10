#pragma once
#ifndef WEDIT_H
#define WEDIT_H

#include <QWidget>
#include "../Headers/addnewfilm.h"
#include "../Headers/wdelete.h"
#include "../Headers/wchange.h"

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

    void on_BDel_clicked();

    void on_BEdit_clicked();

private:
    Ui::WEdit *ui;
    AddNewFilm *AddWindow;
    WDelete *DelWindow;
    WChange *ChangeWindow;
};

#endif // WEDIT_H
