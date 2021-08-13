#ifndef WCOLLECTION_H
#define WCOLLECTION_H

#include <QWidget>

namespace Ui {
class WCollection;
}

class WCollection : public QWidget
{
    Q_OBJECT

public:
    explicit WCollection(QWidget *parent = nullptr);
    ~WCollection();

signals:
    void MainMenu();

private slots:
    void on_BBack_clicked();

private:
    Ui::WCollection *ui;
};

#endif // WCOLLECTION_H
