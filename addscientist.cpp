#include "addscientist.h"
#include "ui_addstudent.h"

AddScientist::AddScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudent)
{
    ui->setupUi(this);
}

AddScientist::~AddScientist()
{
    delete ui;
}
