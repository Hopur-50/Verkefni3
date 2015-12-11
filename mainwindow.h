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

    void on_addNewScientistButton_clicked();

    void on_addNewComputerButton_clicked();

    void on_editScientistButton_clicked();

    void on_editComputerButton_clicked();

    void on_deleteScientistButton_clicked();

    void on_deleteComputerButton_clicked();

    void on_addRelationsButton_clicked();

    void displayAllScientists();

    void displayAllComputers();

private:
    Ui::MainWindow *ui;
    std::string input_text;

};

#endif // MAINWINDOW_H
