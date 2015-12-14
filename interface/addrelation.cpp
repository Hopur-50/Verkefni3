#include "addrelation.h"
#include "ui_addrelation.h"

AddRelation::AddRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRelation)
{
    ui->setupUi(this);
    fillScientists();
    fillComputers();
}

AddRelation::~AddRelation()
{
    delete ui;
}

void AddRelation::fillScientists()
{
    std::vector<Scientist> scientists = sciServ.getAllScientists();

    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        QString name = QString::fromStdString(scientists.at(i).getName());
        ui->comboSelectScientist->addItem(name);
    }
}

void AddRelation::fillComputers()
{
    std::vector<Computer> computers = compServ.getAllComputers();

    for (unsigned int i = 0; i <computers.size(); i++)
    {
        QString name = QString::fromStdString(computers.at(i).getName());
        ui->comboSelectComputer->addItem(name);
    }
}

void AddRelation::on_buttonBox_accepted()
{
    std::string sciName = ui->comboSelectScientist->currentText().toStdString();
    std::string compName = ui->comboSelectComputer->currentText().toStdString();

    baseServ.addRelation(sciName, compName);
}
