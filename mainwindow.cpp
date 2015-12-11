#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    displayScientists(sciServ.getAllScientists());
}

void MainWindow::displayScientists(vector sci)
{
    ui->tableScientist->clear();
    ui->tableScientist->setRowCount(sci.size());

    for (unsigned int row = 0; row < sci.size(); row++)
    {
        Scientist currentSci = sci.at(i);

        QString name = QString::fromStdString(currentSci.getName());
        QString gender = QString::fromStdString(utils::sexToString(currentSci.getSex()));
        QString yearBorn = QString::number(currentSci.getYearBorn());
        QString yearDied = QString::number(currentSci.getYearDied());
        if (yearDied == constants::YEAR_DIED_DEFAULT_VALUE) yearDied = "alive";

        ui->tableScientist->setItem(row, 0, QTableWidgetItem(name));
        ui->tableScientist->setItem(row, 1, QTableWidgetItem(gender));
        ui->tableScientist->setItem(row, 2, QTableWidgetItem(yearBorn));
        ui->tableScientist->setItem(row, 3, QTableWidgetItem(yearDied));
    }

}

void MainWindow::displayAllComputers()
{
    //qDebug() << ui->computerRepo.getAllComputers(currentOrder)->text();
}

void MainWindow::displayComputers(vector comp)
{
    ui->tableComputer->clear();
    ui->tableComputer->setRowCount(comp.size());

    for (unsigned int row = 0; row < comp.size(); row++)
    {
        Computer currentComp = comp.at(i);

        QString name = QString::fromStdString(currentComp.getName());
        QString type = QString::fromStdString(currentComp.getType());
        QString yearBuilt = QString::number(currentComp.getYearOfConstruction());
        if (yearBuilt == constants::YEAR_OF_CONSTRUCTION_VALUE) yearBuilt = "not built";

        ui->tableComputer->setItem(row, 0, QTableWidgetItem(name));
        ui->tableComputer->setItem(row, 1, QTableWidgetItem(type));
        ui->tableComputer->setItem(row, 2, QTableWidgetItem(yearBuilt));
    }

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



