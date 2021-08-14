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
    CollWindow = new WCollection();
    connect(EditWindow, &WEdit::MainMenu, this, &MainWindow::show); // Обработка сигнала от EditWindow, открытие основного окна
    connect(FindWinfow, &WFind::MainMenu, this, &MainWindow::show);
    connect(SortWindow, &WSort::MainMenu, this, &MainWindow::show);
    connect(CollWindow, &WCollection::MainMenu, this, &MainWindow::show);
    connect(this, SIGNAL(ShowFilms()), CollWindow, SLOT(on_BNext_clicked()));
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


void MainWindow::on_BOutput_clicked()
{
    emit ShowFilms(); // Сразу открыть базу данных по открытии окна простомтра коллекции
    CollWindow->show();
    hide();
}

