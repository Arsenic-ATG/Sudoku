#include "mainwindow.h"
#include "ui_mainwindow.h"

sudoku puzzle;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_solve_button_clicked()
{
    puzzle.solve();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->sudoku_board->item(i, j);
            QString str = "";
            str += '0' + puzzle.at(i,j);
            const QString cstr = str;
            Cell->setText(cstr);
        }
    }
}
