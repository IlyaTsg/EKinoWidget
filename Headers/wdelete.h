#pragma once
#ifndef WDELETE_H
#define WDELETE_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class WDelete;
}

class WDelete : public QWidget
{
    Q_OBJECT

public:
    explicit WDelete(QWidget *parent = nullptr);
    ~WDelete();

signals:
    void EditCatalog();

private slots:
    void on_BBack_clicked();

    void on_BNext_clicked();

private:
    Ui::WDelete *ui;
};

#endif // WDELETE_H
