#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // I don't know why but clang++ consider it as a warning if double braces are not used
    int puzzle[9][9] = {{0}};

    for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                QTableWidgetItem* Cell = ui->board->item(i, j);
                QString str = "";
                str += '0' + puzzle[i][j];
                const QString cstr = str;
                // recheck this line
                Cell->setData(i,cstr);
                if (puzzle[i][j])
                {
                    // cell is filled so show some indication of the same like changing background color of the cell
                }
            }
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}

