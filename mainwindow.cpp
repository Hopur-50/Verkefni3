#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QDebug>
#include <QMainWindow>
#include "services/computerservice.h"
#include "services/scientistservice.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllScientists();
    displayAllComputers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()
{
    displayScientists(sciServ.getAllScientists());
}

void MainWindow::displayScientists(vector<Scientist> sci)
{

    ui->tableScientist->clear();
    ui->tableScientist->setRowCount(sci.size());

    ui->tableScientist->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableScientist->setHorizontalHeaderItem(1, new QTableWidgetItem("Gender"));
    ui->tableScientist->setHorizontalHeaderItem(2, new QTableWidgetItem("Year born"));
    ui->tableScientist->setHorizontalHeaderItem(3, new QTableWidgetItem("Year died"));

    for (unsigned int row = 0; row < sci.size(); row++)
    {
        Scientist currentSci = sci.at(row);

        QString name = QString::fromStdString(currentSci.getName());
        QString gender = QString::fromStdString(utils::sexToString(currentSci.getSex()));
        QString yearBorn = QString::number(currentSci.getYearBorn());
        QString yearDied = QString::number(currentSci.getYearDied());
        if (yearDied == QString::number(constants::YEAR_DIED_DEFAULT_VALUE)) yearDied = "alive";

        ui->tableScientist->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableScientist->setItem(row, 1, new QTableWidgetItem(gender));
        ui->tableScientist->setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui->tableScientist->setItem(row, 3, new QTableWidgetItem(yearDied));
    }

}

void MainWindow::displayAllComputers()
{
    displayComputers(compServ.getAllComputers());
}

void MainWindow::displayComputers(vector<Computer> comp)
{
    ui->tableComputer->clear();
    ui->tableComputer->setRowCount(comp.size());

    ui->tableComputer->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableComputer->setHorizontalHeaderItem(1, new QTableWidgetItem("Type"));
    ui->tableComputer->setHorizontalHeaderItem(2, new QTableWidgetItem("Year built"));

    for (unsigned int row = 0; row < comp.size(); row++)
    {
        Computer currentComp = comp.at(row);

        QString name = QString::fromStdString(currentComp.getName());
        QString type = QString::fromStdString(currentComp.getType());
        QString yearBuilt = QString::number(currentComp.getYearOfConstruction());
        if (yearBuilt == QString::number(constants::YEAR_OF_CONSTRUCTION_VALUE)) yearBuilt = "not built";

        ui->tableComputer->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableComputer->setItem(row, 1, new QTableWidgetItem(type));
        ui->tableComputer->setItem(row, 2, new QTableWidgetItem(yearBuilt));
    }

}

void MainWindow::on_addNewScientistButton_clicked()
{
    AddScientist addSci;
    addSci.exec();
    displayAllScientists();
}

void MainWindow::on_addNewComputerButton_clicked()
{
    AddComputer addComp;
    addComp.exec();
}

void MainWindow::on_editScientistButton_clicked()
{
    EditScientist editSci;
    editSci.exec();
}

void MainWindow::on_editComputerButton_clicked()
{
    EditComputer editComp;
    editComp.exec();
}

void MainWindow::on_deleteScientistButton_clicked()
{

}

void MainWindow::on_deleteComputerButton_clicked()
{

}

void MainWindow::on_addRelationsButton_clicked()
{
    AddRelation addRel;
    addRel.exec();
}

void MainWindow::on_inputFilterScientists_textChanged()
{
    string userInput = ui->inputFilterScientists->text().toStdString();

    vector<Scientist> scientists = sciServ.searchForScientists(userInput);
    displayScientists(scientists);
}

void MainWindow::on_inputFilterComputers_textChanged()
{
    string userInput = ui->inputFilterComputers->text().toStdString();

    vector<Computer> computers = compServ.searchForComputers(userInput);
    displayComputers(computers);
}

void MainWindow::on_tableScientist_clicked(const QModelIndex &index)
{
    int currentRow = index.row();
    std::string name = ui->tableScientist->item(currentRow, 0)->text().toStdString();
    std::vector<Computer> computers = sciServ.getRelatedComputers(name);
    displayComputers(computers);
}

void MainWindow::on_tableComputer_clicked(const QModelIndex &index)
{
    int currentRow = index.row();
    std::string name = ui->tableComputer->item(currentRow, 0)->text().toStdString();
    std::vector<Scientist> scientists = compServ.getRelatedScientists(name);
    displayScientists(scientists);
}
