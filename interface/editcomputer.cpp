#include "editcomputer.h"
#include "ui_editcomputer.h"

#include "utilities/utils.h"

EditComputer::EditComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditComputer)
{
    ui->setupUi(this);
}

EditComputer::~EditComputer()
{
    delete ui;
}

void EditComputer::displayInfo(Computer comp)
{
    ui->lineNameComputer->setText(QString::fromStdString(comp.getName()));
    ui->comboType->setCurrentText(QString::fromStdString(comp.getType()));
    ui->lineYearOfConstruction->setText(QString::number(comp.getYearOfConstruction()));
    if (comp.getWasItConstructed()) ui->comboWasItBuilt->setCurrentText("Yes");
    else ui->comboWasItBuilt->setCurrentText("No");

    compID = comp.getId();
}

void EditComputer::on_buttonOkCancel_accepted()
{
    std::string name = ui->lineNameComputer->text().toStdString();
    std::string type = ui->comboType->currentText().toStdString();
    bool wasItConstructed = ui->comboWasItBuilt->currentText().toInt();
    int yearOfConstruction = ui->lineYearOfConstruction->text().toInt();

    Computer newComputer = Computer(name, type, wasItConstructed, yearOfConstruction);
    newComputer.setId(compID);

    compServ.updateComputer(newComputer);
}
