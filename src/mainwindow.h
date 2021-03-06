#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTableWidget>
#include <QtDebug>
#include <QPalette>
#include "includes.h"
#include "sudoku.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_solve_button_clicked();
    void keypad_number_pressed();


    void on_sudoku_board_cellClicked(int row, int column);

    void on_erase_button_released();

    void on_reset_button_clicked();

private:
    int activated_number = 1;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
