#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H

#include <QDialog>
#include "services/computerservice.h"
#include "models/computer.h"

namespace Ui {
class AddComputer;
}

class AddComputer : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputer(QWidget *parent = 0);
    ~AddComputer();

private slots:
    void on_buttonOkCancel_accepted();
    void on_lineComputerName_textChanged(const QString &arg1);
    void on_lineComputerName_textEdited(const QString &arg1);

private:
    Ui::AddComputer *ui;
    ComputerService compServ;
    bool isValid(QString s, int i) const;
};

#endif // ADDCOMPUTER_H
