#ifndef ADDRELATION_H
#define ADDRELATION_H

#include <QDialog>
#include "services/scientistservice.h"
#include "services/computerservice.h"
#include "services/baseservice.h"

namespace Ui {
class AddRelation;
}

class AddRelation : public QDialog
{
    Q_OBJECT

public:
    explicit AddRelation(QWidget *parent = 0);
    ~AddRelation();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddRelation *ui;
    void fillScientists();
    void fillComputers();

    ScientistService sciServ;
    ComputerService compServ;
    BaseService baseServ;
};

#endif // ADDRELATION_H
