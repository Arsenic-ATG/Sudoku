#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

sudoku puzzle;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->keypad_button_1,SIGNAL(released()),this,SLOT(keypad_number_pressed()));
    connect(ui->keypad_button_2,SIGNAL(released()),this,SLOT(keypad_number_pressed()));
    connect(ui->keypad_button_3,SIGNAL(released()),this,SLOT(keypad_number_pressed()));
    connect(ui->keypad_button_4,SIGNAL(released()),this,SLOT(keypad_number_pressed()));
    connect(ui->keypad_button_5,SIGNAL(released()),this,SLOT(keypad_number_pressed()));
    connect(ui->keypad_button_6,SIGNAL(released()),this,SLOT(keypad_number_pressed()));
    connect(ui->keypad_button_7,SIGNAL(released()),this,SLOT(keypad_number_pressed()));
    connect(ui->keypad_button_8,SIGNAL(released()),this,SLOT(keypad_number_pressed()));
    connect(ui->keypad_button_9,SIGNAL(released()),this,SLOT(keypad_number_pressed()));

    ui->keypad_button_1->setCheckable(true);
    ui->keypad_button_2->setCheckable(true);
    ui->keypad_button_3->setCheckable(true);
    ui->keypad_button_4->setCheckable(true);
    ui->keypad_button_5->setCheckable(true);
    ui->keypad_button_6->setCheckable(true);
    ui->keypad_button_7->setCheckable(true);
    ui->keypad_button_8->setCheckable(true);
    ui->keypad_button_9->setCheckable(true);

    ui->keypad_button_1->setChecked(true);

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


void MainWindow::keypad_number_pressed()
{
    QPushButton * button = (QPushButton *)sender();
    activated_number = button->text().toUInt();
    button->setChecked(true);

}
