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

    if (ui->lineScientistName->text() == "" || ui->lineYearOfBirth->text() == "")
    {
           return;
    }
    else
    {
        if (ui->lineYearOfDeath->text() == "" && ui->lineYearOfBirth->text().toInt() < 2016)
        {
            sciServ.addScientist(Scientist(name, gender, yearBorn));
        }
        else if(ui->lineYearOfBirth->text().toInt() < 2016)
        {
            sciServ.addScientist(Scientist(name,gender,yearBorn,yearDied));
        }
    }
}


void AddScientist::on_lineScientistName_textChanged(const QString &arg1)
{
    if (arg1 == "" || arg1 == " ")
    {
            QPalette pal = ui->label_error_nameSci->palette();
            pal.setColor(QPalette::WindowText, Qt::red);
            ui->label_error_nameSci->setPalette(pal);
            ui->label_error_nameSci->setText("Name can't be empty");

            if(ui->lineScientistName->text().toStdString() != "")
            {
                ui->label_error_nameSci->clear();
                ui->label_error_nameSci->setText("!!");
                ui->buttonOkCancel->setEnabled(true);
            }
    }
    else if(ui->lineScientistName->text() != "")
    {
        ui->label_error_nameSci->clear();
        ui->label_error_nameSci->setText("");
        ui->buttonOkCancel->setEnabled(true);
        ui->label_error_nameSci->setText("");
    }
}

void AddScientist::on_lineYearOfBirth_textEdited(const QString &arg1)
{
    if (arg1.toInt() > 2016)
    {
            QPalette pal = ui->labelErrorYearOfBirthSci->palette();
            pal.setColor(QPalette::WindowText, Qt::red);
            ui->labelErrorYearOfBirthSci->setPalette(pal);
            ui->labelErrorYearOfBirthSci->setText("Scientist has to be born");
    }
    else if(ui->lineYearOfBirth->text() == "" || ui->lineYearOfBirth->text() == " ")
    {
        QPalette pal = ui->labelErrorYearOfBirthSci->palette();
        pal.setColor(QPalette::WindowText, Qt::red);
        ui->labelErrorYearOfBirthSci->setPalette(pal);
        ui->labelErrorYearOfBirthSci->setText("Year of birth can't be empty");
    }
    else if(ui->lineYearOfBirth->text() != "")
    {
        ui->labelErrorYearOfBirthSci->clear();
        ui->labelErrorYearOfBirthSci->setText("");
        ui->buttonOkCancel->setEnabled(true);
    }
}

void AddScientist::on_lineScientistName_returnPressed()
{
    if (ui->lineScientistName->text().toStdString() == "" || ui->lineScientistName->text().toStdString() == " ")
    {
            ui->buttonOkCancel->setEnabled(false);
            QPalette pal = ui->label_error_nameSci->palette();
            pal.setColor(QPalette::WindowText, Qt::red);
            ui->label_error_nameSci->setPalette(pal);
            ui->label_error_nameSci->setText("Name can't be empty");

            if(ui->lineScientistName->text().toStdString() != "")
            {
                ui->label_error_nameSci->clear();
                ui->label_error_nameSci->setText("");
                ui->buttonOkCancel->setEnabled(true);
            }

    }
    else if(ui->lineScientistName->text().toStdString() != "")
    {
         ui->labelErrorYearOfBirthSci->setText("");
    }
}
