#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "repositories/computerrepository.h"
#include "repositories/scientistrepository.h"
#include <string>
#include <QDebug>
#include <QMainWindow>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()
{
    //qDebug() << ui-> ScientistsView ->text();
}

void MainWindow::displayAllComputers()
{
    //qDebug() << ui->computerRepo.getAllComputers(currentOrder)->text();
}

void MainWindow::on_addNewScientistButton_clicked()
{

}

void MainWindow::on_addNewComputerButton_clicked()
{

}

void MainWindow::on_editScientistButton_clicked()
{

}

void MainWindow::on_editComputerButton_clicked()
{

}

void MainWindow::on_deleteScientistButton_clicked()
{

}

void MainWindow::on_deleteComputerButton_clicked()
{

}

void MainWindow::on_addRelationsButton_clicked()
{

}



