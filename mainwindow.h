#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_AddNewScientist_clicked();

    void on_AddNewComputer_clicked();

    void on_editScientist_clicked();

    void on_editComputer_clicked();

    void on_deleteScientist_clicked();

    void on_deleteComputer_clicked();

    void on_addRelations_clicked();

    void on_GetAllScientists_clicked();

    void on_GetAllComputers_clicked();

private:
    Ui::MainWindow *ui;
    std::string input_text;

};

#endif // MAINWINDOW_H
