#include "editscientist.h"
#include "ui_editscientist.h"

#include "utilities/utils.h"

EditScientist::EditScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditScientist)
{
    ui->setupUi(this);
}

EditScientist::~EditScientist()
{
    delete ui;
}

void EditScientist::displayInfo(Scientist sci)
{
    ui->comboGender->setCurrentText(QString::fromStdString(utils::sexToString(sci.getSex())));
    ui->lineNameScientist->setText(QString::fromStdString(sci.getName()));
    ui->lineYearOfBirth->setText(QString::number(sci.getYearBorn()));
    ui->lineYearOfDeath->setText(QString::number(sci.getYearDied()));

    sciID = sci.getId();
}

void EditScientist::on_buttonOkCancel_accepted()
{
    std::string name = ui->lineNameScientist->text().toStdString();
    sexType gender = utils::stringToSex(ui->comboGender->currentText().toStdString());
    int yearBorn = ui->lineYearOfBirth->text().toInt();
    int yearDied = ui->lineYearOfDeath->text().toInt();

    Scientist newScientist = Scientist(name, gender, yearBorn, yearDied);
    newScientist.setId(sciID);

    sciServ.updateScientist(newScientist);
}
