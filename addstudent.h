#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>

namespace Ui {
class AddStudent;
}

class AddStudent : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = 0);
    ~AddStudent();

private:
    Ui::AddStudent *ui;
};

#endif // ADDSTUDENT_H
