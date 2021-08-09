#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    EditWindow = new WEdit();
    connect(EditWindow, &WEdit::MainMenu, this, &MainWindow::show); // Обработка сигнала от EditWindow, открытие основного окна
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

