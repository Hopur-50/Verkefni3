#ifndef ADDRELATION_H
#define ADDRELATION_H

#include <QDialog>
#include "services/scientistservice.h"
#include "services/computerservice.h"

namespace Ui {
class AddRelation;
}

class AddRelation : public QDialog
{
    Q_OBJECT

public:
    explicit AddRelation(QWidget *parent = 0);
    ~AddRelation();

    void setComputer(Computer comp);
    void setScientist(Scientist sci);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddRelation *ui;
    void fillScientists();
    void fillComputers();

    ScientistService sciServ;
    ComputerService compServ;
};

#endif // ADDRELATION_H
