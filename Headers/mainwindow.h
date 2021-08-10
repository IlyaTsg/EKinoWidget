#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Headers/wedit.h"
#include "../Headers/wfind.h"
#include "../Headers/wsort.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BExit_clicked();

    void on_BEdit_clicked();

    void on_BFind_clicked();

    void on_BSort_clicked();

private:
    Ui::MainWindow *ui;

    WEdit *EditWindow;
    WFind *FindWinfow;
    WSort *SortWindow;
};
#endif // MAINWINDOW_H
