#pragma once
#ifndef WSORT_H
#define WSORT_H

#include <QWidget>

namespace Ui {
class WSort;
}

class WSort : public QWidget
{
    Q_OBJECT

public:
    explicit WSort(QWidget *parent = nullptr);
    ~WSort();

signals:
    void MainMenu();

private slots:
    void on_BBack_clicked();

private:
    Ui::WSort *ui;
};

#endif // WSORT_H
