#include "addcomputer.h"
#include "ui_addcomputer.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

AddComputer::AddComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputer)
{
    ui->setupUi(this);
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

    if (ui->lineComputerName->text() == "" || ui->lineComputerName->text() == " ")
    {
        return;
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

void AddComputer::on_lineComputerName_textEdited(const QString &arg1)
{
    if (arg1 == "" || arg1 == " ")
    {
        QPalette pal = ui->labelErrorName->palette();
        pal.setColor(QPalette::WindowText, Qt::red);
        ui->labelErrorName->setPalette(pal);
        ui->labelErrorName->setText("Name can't be empty");
    }
    else if (ui->lineComputerName->text() != "")
    {
        ui->labelErrorName->setText("");
    }
}

void AddComputer::on_lineYearOfConstruction_textChanged(const QString &arg1)
{
    if (arg1.toInt() > 2016)
    {
            QPalette pal = ui->labelErrorYearConstruct->palette();
            pal.setColor(QPalette::WindowText, Qt::red);
            ui->labelErrorYearConstruct->setPalette(pal);
            ui->labelErrorYearConstruct->setText("Invaid year of construction!");
    }
    else if(ui->lineYearOfConstruction->text() == "" || ui->lineYearOfConstruction->text() == " ")
    {
        QPalette pal = ui->labelErrorYearConstruct->palette();
        pal.setColor(QPalette::WindowText, Qt::red);
        ui->labelErrorYearConstruct->setPalette(pal);
        ui->labelErrorYearConstruct->setText("Year of construction can't be empty");
    }
    else if(ui->lineYearOfConstruction->text() != "")
    {
        ui->labelErrorYearConstruct->clear();
        ui->labelErrorYearConstruct->setText("");
        ui->buttonOkCancel->setEnabled(true);
    }
}
