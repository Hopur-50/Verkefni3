#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include <QDialog>
#include <models/scientist.h>
#include <services/scientistservice.h>

namespace Ui {
class EditScientist;
}

class EditScientist : public QDialog
{
    Q_OBJECT

public:
    explicit EditScientist(QWidget *parent = 0);
    ~EditScientist();

    void displayInfo(Scientist sci);

private slots:
    void on_buttonOkCancel_accepted();

private:
    Ui::EditScientist *ui;
    int sciID;
    ScientistService sciServ;
};

#endif // EDITSCIENTIST_H
