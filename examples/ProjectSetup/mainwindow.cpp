#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //The green led is configured with the designer.

    //The red led is configured with code to show this possibility, too:
    ui->ledRed->setOnColor(QColor(255, 0, 0)); //Pure red.
    ui->ledRed->setOffColor(QColor(50, 0, 0)); //Dark red.
    ui->ledRed->setBlinkCycleMS(1000);
    ui->ledRed->setValue(true);
    ui->ledRed->setBlinking(true);
    ui->ledRed->setClickable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
