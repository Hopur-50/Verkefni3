#include "addscientist.h"
#include "ui_addscientist.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

AddScientist::AddScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientist)
{
    ui->setupUi(this);
}

AddScientist::~AddScientist()
{
    delete ui;
}

void AddScientist::on_buttonOkCancel_accepted()
{
    std::string name = ui->lineScientistName->text().toStdString();
    sexType gender = utils::stringToSex(ui->comboGender->currentText().toStdString());
    int yearBorn = ui->lineYearOfBirth->text().toInt();
    int yearDied = ui->lineYearOfDeath->text().toInt();

    if (ui->lineScientistName->text() == "" || ui->lineScientistName->text() == " ")
    {
            QValidator::Invalid;  //Eigum við að hafa eitthvað villu message? hvað finnst ykkur? Kv. Sandra
    }
    else
    {
        if (ui->lineYearOfDeath->text() == "" && ui->lineYearOfBirth->text().toInt() < 2016)
        {
            sciServ.addScientist(Scientist(name,gender, yearBorn));
        }
        else if(ui->lineYearOfBirth->text().toInt() < 2016)
        {
            sciServ.addScientist(Scientist(name,gender,yearBorn,yearDied));
        }
    }
}

