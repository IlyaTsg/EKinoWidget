#pragma once
#ifndef WFIND_H
#define WFIND_H

#include <QWidget>

namespace Ui {
class WFind;
}

class WFind : public QWidget
{
    Q_OBJECT

public:
    explicit WFind(QWidget *parent = nullptr);
    ~WFind();

signals:
    void MainMenu();

private slots:
    void on_BBack_clicked();

private:
    Ui::WFind *ui;
};

#endif // WFIND_H
