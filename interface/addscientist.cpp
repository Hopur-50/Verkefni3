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

    if (ui->lineYearOfDeath->text() == "")
    {
        sciServ.addScientist(Scientist(name,gender, yearBorn));
    }
    else
    {
        sciServ.addScientist(Scientist(name,gender,yearBorn,yearDied));
    }
}

