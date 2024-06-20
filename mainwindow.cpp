#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrNextpage = new Nextpage();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrNextpage;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
    ptrNextpage ->show();
}

