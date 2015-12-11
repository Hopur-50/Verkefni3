#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <services/scientistservice.h>
#include <services/computerservice.h>
#include <services/baseservice.h>
#include <utilities/utils.h>
#include <utilities/constants.h>

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

    void on_addRelationsButton_clicked();

    void displayAllScientists();

    void displayScientists(std::vector<Scientist> sci);

    void displayAllComputers();

    void displayComputers(std::vector<Computer> comp);

private:
    Ui::MainWindow *ui;
    std::string input_text;

    ScientistService sciServ;
    ComputerService compServ;
    BaseService baseServ;

};

#endif // MAINWINDOW_H
