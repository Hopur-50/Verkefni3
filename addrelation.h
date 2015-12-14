#ifndef ADDRELATION_H
#define ADDRELATION_H

#include <QDialog>

namespace Ui {
class AddRelation;
}

class AddRelation : public QDialog
{
    Q_OBJECT

public:
    explicit AddRelation(QWidget *parent = 0);
    ~AddRelation();

private:
    Ui::AddRelation *ui;
};

#endif // ADDRELATION_H
