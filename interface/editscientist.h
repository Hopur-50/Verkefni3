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

<<<<<<< HEAD
=======
    void displayInfo(Scientist sci);

>>>>>>> 54d9480397f0f5f0a107c67d5d230f594accba6d
private slots:
    void on_buttonOkCancel_accepted();

private:
    Ui::EditScientist *ui;
    ScientistService sciServ;
};

#endif // EDITSCIENTIST_H
