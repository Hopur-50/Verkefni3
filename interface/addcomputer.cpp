#include "addcomputer.h"
#include "ui_addcomputer.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

AddComputer::AddComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputer)
{
    ui->setupUi(this);
    ui->buttonOkCancel->setEnabled(false);
}

AddComputer::~AddComputer()
{
    delete ui;
}

void AddComputer::on_buttonOkCancel_accepted()
{
    std::string name = ui->lineComputerName->text().toStdString();
    std::string type = ui->comboType->currentText().toStdString();
    std::string built = ui->comboWasItBuilt->currentText().toStdString();
    int yearConstructed = ui->lineYearOfConstruction->text().toInt();

    if (ui->lineComputerName->text().toStdString() != "" || ui->lineComputerName->text().toStdString() != " ")
    {
        QValidator::Acceptable;
    }
    else if(ui->lineComputerName->text().toStdString() == "" || ui->lineComputerName->text().toStdString() == " ")
    {
        QValidator::Invalid;
    }
    else
    {
        if (built == "No")
        {
            compServ.addComputer(Computer(name, type, false));
        }
        else
        {
            compServ.addComputer(Computer(name, type, true, yearConstructed));
        }
    }
}

bool AddComputer::isValid(QString s, int i) const
{
    if (s.isEmpty() || s == " ")
    {
        return QValidator::Invalid;
    }

    if (i > 0 && i < 2016)
    {
       return QIntValidator::Acceptable;
    }
    else
    {
       return QIntValidator::Invalid;
    }
}

void AddComputer::on_lineComputerName_textChanged(const QString &arg1)
{
    if (ui->lineComputerName->text().toStdString() != "" || ui->lineComputerName->text().toStdString() != " ")
    {
        ui->buttonOkCancel->setEnabled(true);
    }
    else if(ui->lineComputerName->text().toStdString() == "" || ui->lineComputerName->text().toStdString() == " ")
    {
        ui->labelErrorName->setText("Name cannot be empty");
        ui->buttonOkCancel->setEnabled(false);

        return;
    }
}
