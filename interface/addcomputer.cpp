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
