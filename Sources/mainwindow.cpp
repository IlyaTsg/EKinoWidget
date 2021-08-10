#include "../Headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    EditWindow = new WEdit();
    FindWinfow = new WFind();
    SortWindow = new WSort();
    connect(EditWindow, &WEdit::MainMenu, this, &MainWindow::show); // Обработка сигнала от EditWindow, открытие основного окна
    connect(FindWinfow, &WFind::MainMenu, this, &MainWindow::show);
    connect(SortWindow, &WSort::MainMenu, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BExit_clicked()
{
    QApplication::quit();
}


void MainWindow::on_BEdit_clicked()
{
    EditWindow->show();
    hide();
}


void MainWindow::on_BFind_clicked()
{
    FindWinfow->show();
    hide();
}


void MainWindow::on_BSort_clicked()
{
    SortWindow->show();
    hide();
}

