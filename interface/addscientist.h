#ifndef ADDSCIENTIST_H
#define ADDSCIENTIST_H

#include <QDialog>
#include "services/scientistservice.h"
#include "models/scientist.h"

namespace Ui {
class AddScientist;
}

class AddScientist : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientist(QWidget *parent = 0);
    ~AddScientist();

private slots:
    void on_buttonOkCancel_accepted();

    void on_lineScientistName_textChanged(const QString &arg1);

    void on_lineYearOfBirth_textEdited(const QString &arg1);

    void on_lineScientistName_returnPressed();

private:
    Ui::AddScientist *ui;
    ScientistService sciServ;
};

#endif // ADDSCIENTIST_H
