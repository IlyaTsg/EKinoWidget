#pragma once
#ifndef WCHANGE_H
#define WCHANGE_H

#include <QWidget>

namespace Ui {
class WChange;
}

class WChange : public QWidget
{
    Q_OBJECT

public:
    explicit WChange(QWidget *parent = nullptr);
    ~WChange();

signals:
    void EditCatalog();

private slots:
    void on_BBack_clicked();

private:
    Ui::WChange *ui;
};

#endif // WCHANGE_H
