#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <services/scientistservice.h>
#include <services/computerservice.h>
#include <services/baseservice.h>

#include <utilities/utils.h>
#include <utilities/constants.h>

#include <interface/addscientist.h>
#include <interface/addcomputer.h>
#include <interface/editscientist.h>
#include <interface/editcomputer.h>
#include <interface/addrelation.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
     ~MainWindow();

private slots:

    void on_addNewScientistButton_clicked();

    void on_addNewComputerButton_clicked();

    void on_editScientistButton_clicked();

    void on_editComputerButton_clicked();

    void on_deleteScientistButton_clicked();

    void on_deleteComputerButton_clicked();

    void displayAllScientists();

    void displayScientists(std::vector<Scientist> sci);

    void displayRelatedComputers(std::vector<Computer> comp);

    void displayAllComputers();

    void displayComputers(std::vector<Computer> comp);

    void displayRelatedScientists(std::vector<Scientist> sci);

    void on_inputFilterScientists_textChanged();

    void on_inputFilterComputers_textChanged();

    void on_tableScientist_clicked(const QModelIndex &index);

    void on_tableComputer_clicked(const QModelIndex &index);


    void on_buttonAddRelation_clicked();

    void on_buttonAddRelation2_clicked();

    void on_tableRelatedScientists_clicked(const QModelIndex &index);

    void on_tableRelatedComputers_clicked(const QModelIndex &index);

    void on_removeRelationButtonSci_clicked();

    void on_removeRelationButtonComp_clicked();

private:
    Ui::MainWindow *ui;
    std::string input_text;

    //Keeps track of which items are selected in the tables
    int selectedSciRow;
    int selectedCompRow;
    int selectedRelSciRow;
    int selectedRelCompRow;

    ScientistService sciServ;
    ComputerService compServ;
    BaseService baseServ;

    std::vector<Scientist> displayedScientists;
    std::vector<Computer> displayedComputers;

    Computer getComputer(int id);
    Scientist getScientist(int id);
};

#endif // MAINWINDOW_H
