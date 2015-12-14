#include "addrelation.h"
#include "ui_addrelation.h"

AddRelation::AddRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRelation)
{
    ui->setupUi(this);
}

AddRelation::~AddRelation()
{
    delete ui;
}
