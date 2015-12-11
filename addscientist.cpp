#include "addscientist.h"
#include "ui_addscientis.h"

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
