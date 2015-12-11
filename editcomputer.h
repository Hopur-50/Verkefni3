#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>

namespace Ui {
class EditComputer;
}

class EditComputer : public QDialog
{
    Q_OBJECT

public:
    explicit EditComputer(QWidget *parent = 0);
    ~EditComputer();

private:
    Ui::EditComputer *ui;
};

#endif // EDITCOMPUTER_H
