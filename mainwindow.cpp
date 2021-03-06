#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QDebug>
#include <QHeaderView>
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

    selectedCompRow = 0;
    selectedSciRow = 0;
    selectedRelCompRow = 0;
    selectedRelSciRow = 0;

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

void MainWindow::displayScientists(std::vector<Scientist> sci)
{

    ui->tableScientist->clear();
    ui->tableScientist->setRowCount(sci.size());
    ui->tableScientist->setColumnCount(5);
    ui->tableScientist->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

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

        //Sorting must be disabled before inserting items
        //Otherwise table woll try to sort while inserting which usually fails
        ui->tableScientist->setSortingEnabled(false);
        ui->tableScientist->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableScientist->setItem(row, 1, new QTableWidgetItem(gender));
        ui->tableScientist->setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui->tableScientist->setItem(row, 3, new QTableWidgetItem(yearDied));
        ui->tableScientist->setItem(row, 4, new QTableWidgetItem(id));
        ui->tableScientist->setSortingEnabled(true);
    }

    //We must have access to IDs but do not want to display them
    ui->tableScientist->hideColumn(4);

    displayedScientists = sci;
}

void MainWindow::displayRelatedComputers(std::vector<Computer> comp)
{
    ui->tableRelatedComputers->clear();
    ui->tableRelatedComputers->setRowCount(comp.size());
    ui->tableRelatedComputers->setColumnCount(4);
    ui->tableRelatedComputers->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    ui->tableRelatedComputers->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableRelatedComputers->setHorizontalHeaderItem(1, new QTableWidgetItem("Type"));
    ui->tableRelatedComputers->setHorizontalHeaderItem(2, new QTableWidgetItem("Year built"));
    ui->tableRelatedComputers->setHorizontalHeaderItem(3, new QTableWidgetItem("ID"));

    for (unsigned int row = 0; row < comp.size(); row++)
    {
        Computer currentComp = comp.at(row);

        QString name = QString::fromStdString(currentComp.getName());
        QString type = QString::fromStdString(currentComp.getType());
        QString yearOfConstruction = QString::number(currentComp.getYearOfConstruction());
        QString id = QString::number(currentComp.getId());
        if (yearOfConstruction == QString::number(constants::YEAR_OF_CONSTRUCTION_VALUE)) yearOfConstruction = "not built";

        ui->tableRelatedComputers->setSortingEnabled(false);
        ui->tableRelatedComputers->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableRelatedComputers->setItem(row, 1, new QTableWidgetItem(type));
        ui->tableRelatedComputers->setItem(row, 2, new QTableWidgetItem(yearOfConstruction));
        ui->tableRelatedComputers->setItem(row, 3, new QTableWidgetItem(id));
        ui->tableRelatedComputers->setSortingEnabled(true);
    }

    ui->tableRelatedComputers->hideColumn(3);
}

void MainWindow::displayAllComputers()
{
    displayComputers(compServ.getAllComputers());
}

void MainWindow::displayComputers(std::vector<Computer> comp)
{
    ui->tableComputer->clear();
    ui->tableComputer->setRowCount(comp.size());
    ui->tableComputer->setColumnCount(4);
    ui->tableComputer->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    ui->tableComputer->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableComputer->setHorizontalHeaderItem(1, new QTableWidgetItem("Type"));
    ui->tableComputer->setHorizontalHeaderItem(2, new QTableWidgetItem("Year built"));
    ui->tableComputer->setHorizontalHeaderItem(3, new QTableWidgetItem("ID"));

    for (unsigned int row = 0; row < comp.size(); row++)
    {
        Computer currentComp = comp.at(row);

        QString name = QString::fromStdString(currentComp.getName());
        QString type = QString::fromStdString(currentComp.getType());
        QString yearOfConstruction = QString::number(currentComp.getYearOfConstruction());
        QString id = QString::number(currentComp.getId());
        if (yearOfConstruction == QString::number(constants::YEAR_OF_CONSTRUCTION_VALUE)) yearOfConstruction = "not built";

        ui->tableComputer->setSortingEnabled(false);
        ui->tableComputer->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableComputer->setItem(row, 1, new QTableWidgetItem(type));
        ui->tableComputer->setItem(row, 2, new QTableWidgetItem(yearOfConstruction));
        ui->tableComputer->setItem(row, 3, new QTableWidgetItem(id));
        ui->tableComputer->setSortingEnabled(true);
    }

    ui->tableComputer->hideColumn(3);

  displayedComputers = comp;
}

void MainWindow::displayRelatedScientists(std::vector<Scientist> sci)
{
    ui->tableRelatedScientists->clear();
    ui->tableRelatedScientists->setRowCount(sci.size());
    ui->tableRelatedScientists->setColumnCount(5);
    ui->tableRelatedScientists->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

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

        ui->tableRelatedScientists->setSortingEnabled(false);
        ui->tableRelatedScientists->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableRelatedScientists->setItem(row, 1, new QTableWidgetItem(gender));
        ui->tableRelatedScientists->setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui->tableRelatedScientists->setItem(row, 3, new QTableWidgetItem(yearDied));
        ui->tableRelatedScientists->setItem(row, 4, new QTableWidgetItem(id));
        ui->tableRelatedScientists->setSortingEnabled(true);
    }
    ui->tableRelatedScientists->hideColumn(4);
}

void MainWindow::on_addNewScientistButton_clicked()
{
    AddScientist addSci;
    addSci.exec();

    refreshTables();
}

void MainWindow::on_addNewComputerButton_clicked()
{
    AddComputer addComp;
    addComp.exec();

    refreshTables();
}

void MainWindow::on_editScientistButton_clicked()
{
    int sciID = ui->tableScientist->item(selectedSciRow, 4)->text().toInt();
    EditScientist editSci;
    editSci.displayInfo(getScientist(sciID));
    editSci.exec();

    refreshTables();
}

void MainWindow::on_editComputerButton_clicked()
{
    int compID = ui->tableComputer->item(selectedCompRow, 3)->text().toInt();
    EditComputer editComp;
    editComp.displayInfo(getComputer(compID));
    editComp.exec();

    refreshTables();
}

void MainWindow::on_deleteScientistButton_clicked()
{
    int answer = QMessageBox::question(this, "Confirm", constants::CONFIRM_DEL_SCIENTIST);
    if (answer == QMessageBox::No) return;

    int id = ui->tableScientist->item(selectedSciRow, 4)->text().toInt();
    sciServ.deleteScientist(id);

    ui->tableRelatedComputers->clear();
    displayRelatedComputers(emptyComputer);
    refreshTables();
}

void MainWindow::on_deleteComputerButton_clicked()
{
    int answer = QMessageBox::question(this, "Confirm", constants::CONFIRM_DEL_COMPUTER);
    if (answer == QMessageBox::No) return;

    int id = ui->tableComputer->item(selectedCompRow, 3)->text().toInt();
    compServ.deleteComputer(id);

    ui->tableRelatedScientists->clear();
    displayRelatedScientists(emptyScientist);
    refreshTables();
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
    int id = ui->tableScientist->item(selectedSciRow, 4)->text().toInt();
    std::vector<Computer> computers = sciServ.getRelatedComputers(id);
    displayRelatedComputers(computers);

    ui->removeRelationButtonSci->setEnabled(false);
}

void MainWindow::on_tableComputer_clicked(const QModelIndex &index)
{
    ui->editComputerButton->setEnabled(true);
    ui->deleteComputerButton->setEnabled(true);
    selectedCompRow = index.row();
    int id = ui->tableComputer->item(selectedCompRow, 3)->text().toInt();
    std::vector<Scientist> scientists = compServ.getRelatedScientists(id);
    displayRelatedScientists(scientists);

    ui->removeRelationButtonComp->setEnabled(false);
}

Computer MainWindow::getComputer(int id)
{
    for (unsigned int i = 0; i < displayedComputers.size(); i++)
    {
        if (id == displayedComputers.at(i).getId())
        {
            return displayedComputers.at(i);
        }
    }
    return displayedComputers[0]; //Should not reach this point. Just suppressing warning.
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
    return displayedScientists[0]; //Should not reach this point. Just suppressing warning.
}

void MainWindow::on_buttonAddRelationSci_clicked()
{
    int compID = ui->tableComputer->item(selectedCompRow, 3)->text().toInt();
    int sciID = ui->tableScientist->item(selectedSciRow, 4)->text().toInt();
    AddRelation addRel;
    addRel.setComputer(getComputer(compID));
    addRel.setScientist(getScientist(sciID));
    addRel.exec();

    refreshTables();
}

void MainWindow::on_buttonAddRelationComp_clicked()
{
    int compID = ui->tableComputer->item(selectedCompRow, 3)->text().toInt();
    int sciID = ui->tableScientist->item(selectedSciRow, 4)->text().toInt();
    AddRelation addRel;
    addRel.setComputer(getComputer(compID));
    addRel.setScientist(getScientist(sciID));
    addRel.exec();

    refreshTables();
}

void MainWindow::on_tableRelatedScientists_clicked(const QModelIndex &index)
{
    ui->removeRelationButtonComp->setEnabled(true);
    selectedRelSciRow = index.row();
}

void MainWindow::on_tableRelatedComputers_clicked(const QModelIndex &index)
{
    ui->removeRelationButtonSci->setEnabled(true);
    selectedRelCompRow = index.row();
}

void MainWindow::on_removeRelationButtonSci_clicked()
{
    int answer = QMessageBox::question(this, "Confirm", constants::CONFIRM_DEL_RELATION);
    if (answer == QMessageBox::No) return;

    int sciID = ui->tableScientist->item(selectedSciRow, 4)->text().toInt();
    int compID = ui->tableRelatedComputers->item(selectedRelCompRow, 3)->text().toInt();
    compServ.deleteRelation(compID, sciID);

    std::vector<Computer> computers = sciServ.getRelatedComputers(sciID);
    displayRelatedComputers(computers);

    refreshTables();
}


void MainWindow::on_removeRelationButtonComp_clicked()
{
    int answer = QMessageBox::question(this, "Confirm", constants::CONFIRM_DEL_RELATION);
    if (answer == QMessageBox::No) return;

    int compID = ui->tableComputer->item(selectedCompRow, 3)->text().toInt();
    int sciID = ui->tableRelatedScientists->item(selectedRelSciRow, 4)->text().toInt();
    compServ.deleteRelation(compID, sciID);

    std::vector<Scientist> scientists = compServ.getRelatedScientists(compID);
    displayRelatedScientists(scientists);

    refreshTables();
}

void MainWindow::refreshTables()
{
    ui->inputFilterScientists->setText("");
    displayAllScientists();
    ui->editScientistButton->setEnabled(false);
    ui->deleteScientistButton->setEnabled(false);

    ui->inputFilterComputers->setText("");
    displayAllComputers();
    ui->editComputerButton->setEnabled(false);
    ui->deleteComputerButton->setEnabled(false);

    ui->removeRelationButtonComp->setEnabled(false);
    ui->removeRelationButtonSci->setEnabled(false);
}
