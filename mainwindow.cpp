#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QDebug>
#include <QMessageBox>
#include <QMainWindow>
#include "services/computerservice.h"
#include "services/scientistservice.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->editComputerButton->setEnabled(false);
    ui->editScientistButton->setEnabled(false);

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
    ui->tableScientist->setColumnCount(5);

    ui->tableScientist->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableScientist->setHorizontalHeaderItem(1, new QTableWidgetItem("Gender"));
    ui->tableScientist->setHorizontalHeaderItem(2, new QTableWidgetItem("Year born"));
    ui->tableScientist->setHorizontalHeaderItem(3, new QTableWidgetItem("Year died"));
    ui->tableScientist->setHorizontalHeaderItem(4, new QTableWidgetItem("ID"));

    for (unsigned int row = 0; row < sci.size(); row++)
    {
        Scientist currentSci = sci.at(row);

        QString name = QString::fromStdString(currentSci.getName());
        QString gender = QString::fromStdString(utils::sexToString(currentSci.getSex()));
        QString yearBorn = QString::number(currentSci.getYearBorn());
        QString yearDied = QString::number(currentSci.getYearDied());
        QString id = QString::number(currentSci.getId());
        if (yearDied == QString::number(constants::YEAR_DIED_DEFAULT_VALUE)) yearDied = "alive";

        ui->tableScientist->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableScientist->setItem(row, 1, new QTableWidgetItem(gender));
        ui->tableScientist->setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui->tableScientist->setItem(row, 3, new QTableWidgetItem(yearDied));
        ui->tableScientist->setItem(row, 4, new QTableWidgetItem(id));
    }
    ui->tableScientist->hideColumn(4);

    displayedScientists = sci;
}

void MainWindow::displayRelatedComputers(std::vector<Computer> comp)
{
    ui->tableRelatedComputers->clear();
    ui->tableRelatedComputers->setRowCount(comp.size());
    ui->tableRelatedComputers->setColumnCount(4);

    ui->tableRelatedComputers->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableRelatedComputers->setHorizontalHeaderItem(1, new QTableWidgetItem("Type"));
    ui->tableRelatedComputers->setHorizontalHeaderItem(2, new QTableWidgetItem("Year built"));
    ui->tableRelatedComputers->setHorizontalHeaderItem(3, new QTableWidgetItem("ID"));

    for (unsigned int row = 0; row < comp.size(); row++)
    {
        Computer currentComp = comp.at(row);

        QString name = QString::fromStdString(currentComp.getName());
        QString type = QString::fromStdString(currentComp.getType());
        QString yearBuilt = QString::number(currentComp.getYearOfConstruction());
        QString id = QString::number(currentComp.getId());
        if (yearBuilt == QString::number(constants::YEAR_OF_CONSTRUCTION_VALUE)) yearBuilt = "not built";

        ui->tableRelatedComputers->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableRelatedComputers->setItem(row, 1, new QTableWidgetItem(type));
        ui->tableRelatedComputers->setItem(row, 2, new QTableWidgetItem(yearBuilt));
        ui->tableRelatedComputers->setItem(row, 3, new QTableWidgetItem(id));
    }

    ui->tableRelatedComputers->hideColumn(3);
}

void MainWindow::displayAllComputers()
{
    displayComputers(compServ.getAllComputers());
}

void MainWindow::displayComputers(vector<Computer> comp)
{
    ui->tableComputer->clear();
    ui->tableComputer->setRowCount(comp.size());
    ui->tableComputer->setColumnCount(4);

    ui->tableComputer->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableComputer->setHorizontalHeaderItem(1, new QTableWidgetItem("Type"));
    ui->tableComputer->setHorizontalHeaderItem(2, new QTableWidgetItem("Year built"));
    ui->tableComputer->setHorizontalHeaderItem(3, new QTableWidgetItem("ID"));

    for (unsigned int row = 0; row < comp.size(); row++)
    {
        Computer currentComp = comp.at(row);

        QString name = QString::fromStdString(currentComp.getName());
        QString type = QString::fromStdString(currentComp.getType());
        QString yearBuilt = QString::number(currentComp.getYearOfConstruction());
        QString id = QString::number(currentComp.getId());
        if (yearBuilt == QString::number(constants::YEAR_OF_CONSTRUCTION_VALUE)) yearBuilt = "not built";

        ui->tableComputer->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableComputer->setItem(row, 1, new QTableWidgetItem(type));
        ui->tableComputer->setItem(row, 2, new QTableWidgetItem(yearBuilt));
        ui->tableComputer->setItem(row, 3, new QTableWidgetItem(id));
    }

    ui->tableComputer->hideColumn(3);

    displayedComputers = comp;
}

void MainWindow::displayRelatedScientists(std::vector<Scientist> sci)
{
    ui->tableRelatedScientists->clear();
    ui->tableRelatedScientists->setRowCount(sci.size());
    ui->tableRelatedScientists->setColumnCount(5);

    ui->tableRelatedScientists->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableRelatedScientists->setHorizontalHeaderItem(1, new QTableWidgetItem("Gender"));
    ui->tableRelatedScientists->setHorizontalHeaderItem(2, new QTableWidgetItem("Year born"));
    ui->tableRelatedScientists->setHorizontalHeaderItem(3, new QTableWidgetItem("Year died"));
    ui->tableRelatedScientists->setHorizontalHeaderItem(4, new QTableWidgetItem("ID"));

    for (unsigned int row = 0; row < sci.size(); row++)
    {
        Scientist currentSci = sci.at(row);

        QString name = QString::fromStdString(currentSci.getName());
        QString gender = QString::fromStdString(utils::sexToString(currentSci.getSex()));
        QString yearBorn = QString::number(currentSci.getYearBorn());
        QString yearDied = QString::number(currentSci.getYearDied());
        QString id = QString::number(currentSci.getId());
        if (yearDied == QString::number(constants::YEAR_DIED_DEFAULT_VALUE)) yearDied = "alive";

        ui->tableRelatedScientists->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableRelatedScientists->setItem(row, 1, new QTableWidgetItem(gender));
        ui->tableRelatedScientists->setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui->tableRelatedScientists->setItem(row, 3, new QTableWidgetItem(yearDied));
        ui->tableRelatedScientists->setItem(row, 4, new QTableWidgetItem(id));
    }
    ui->tableRelatedScientists->hideColumn(4);
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
    int sciID = ui->tableScientist->item(selectedSciRow, 4)->text().toInt();
    EditScientist editSci;
    editSci.displayInfo(getScientist(sciID));
    editSci.exec();
    displayAllScientists();
}

void MainWindow::on_editComputerButton_clicked()
{
    EditComputer editComp;
    editComp.exec();
}

void MainWindow::on_deleteScientistButton_clicked()
{
    int answer = QMessageBox::question(this, "Confirm", "Are you sure you wish to delete the selected scientist?");
    if (answer == QMessageBox::No)
    {
        return;
    }
    int id = ui->tableScientist->item(selectedSciRow, 4)->text().toInt();
    bool success = sciServ.deleteScientist(id);
    if(success)
    {
        //YAY
    }
    else
    {
        //NAY
    }
    displayAllScientists();
}

void MainWindow::on_deleteComputerButton_clicked()
{
    int answer = QMessageBox::question(this, "Confirm", "Are you sure you wish to delete the selected computer?");
    if (answer == QMessageBox::No)
    {
        return;
    }
    int id = ui->tableComputer->item(selectedCompRow, 3)->text().toInt();
    bool success = compServ.deleteComputer(id);
    if(success)
    {
        //YAY
    }
    else
    {
        //NAY
    }
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
    ui->editScientistButton->setEnabled(true);
    ui->deleteScientistButton->setEnabled(true);
    selectedSciRow = index.row();
    std::string name = ui->tableScientist->item(selectedSciRow, 0)->text().toStdString();
    std::vector<Computer> computers = sciServ.getRelatedComputers(name);
    displayRelatedComputers(computers);
}

void MainWindow::on_tableComputer_clicked(const QModelIndex &index)
{
    ui->editComputerButton->setEnabled(true);
    ui->deleteComputerButton->setEnabled(true);
    selectedCompRow = index.row();
    std::string name = ui->tableComputer->item(selectedCompRow, 0)->text().toStdString();
    std::vector<Scientist> scientists = compServ.getRelatedScientists(name);
    displayRelatedScientists(scientists);
}

Scientist MainWindow::getScientist(int id)
{
    for (unsigned int i = 0; i < displayedScientists.size(); i++)
    {
        if (id == displayedScientists.at(i).getId())
        {
            return displayedScientists.at(i);
        }
    }
    return displayedScientists[0]; //Should not reach this point.
}

void MainWindow::on_buttonAddRelation_clicked()
{
    AddRelation addRel;
    addRel.exec();
}

void MainWindow::on_buttonAddRelation_2_clicked()
{
    AddRelation addRel;
    addRel.exec();
}
