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

void MainWindow::on_GetAllScientists_clicked()
{
    //qDebug() << ui-> ScientistsView ->text();
}

void MainWindow::on_GetAllComputers_clicked()
{
    //qDebug() << ui->computerRepo.getAllComputers(currentOrder)->text();
}

void MainWindow::on_AddNewScientist_clicked()
{

}

void MainWindow::on_AddNewComputer_clicked()
{

}

void MainWindow::on_editScientist_clicked()
{

}

void MainWindow::on_editComputer_clicked()
{

}

void MainWindow::on_deleteScientist_clicked()
{

}

void MainWindow::on_deleteComputer_clicked()
{

}

void MainWindow::on_addRelations_clicked()
{

}



