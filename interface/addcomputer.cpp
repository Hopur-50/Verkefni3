#include "addcomputer.h"
#include "ui_addcomputer.h"

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

    if (built == "No")
    {
        compServ.addComputer(Computer(name, type, false));
    }
    else
    {
        int yearConstructed = ui->lineYearOfConstruction->text().toInt();
        compServ.addComputer(Computer(name, type, true, yearConstructed));
    }


}

//bool AddComputer::isValid() const
//{
//    std::string emptyLine = "";

//    if(ui->lineYearOfConstruction->text().toStdString() == emptyLine)
//    {
//        return false == (this, "Error!", "Line is empty");
//    }
//    else
//    {
//        return true;
//    }

//    return false;
//}

bool AddComputer::isValid(QString s, int i) const
{
    if (s.isEmpty() || s == "-")
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
