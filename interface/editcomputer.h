#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>
#include <models/computer.h>
#include <services/computerservice.h>

namespace Ui {
class EditComputer;
}

class EditComputer : public QDialog
{
    Q_OBJECT

public:
    explicit EditComputer(QWidget *parent = 0);
    ~EditComputer();
    
    void displayInfo(Computer comp);

private slots:
    void on_buttonOkCancel_accepted();

private:
    Ui::EditComputer *ui;
    int compID;
    ComputerService compServ;
};

#endif // EDITCOMPUTER_H
