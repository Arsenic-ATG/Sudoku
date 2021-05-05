#include "mainwindow.h"
#include "ui_mainwindow.h"


sudoku puzzle;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->sudoku_board->item(i, j);
            Cell->setTextAlignment(Qt::AlignCenter);
            if (puzzle.at(i, j))
            {
                const QString str = QString::number(puzzle.at(i, j));
                Cell->setText(str);
                Cell->QTableWidgetItem::setBackground(Qt::green);
                Cell->QTableWidgetItem::setForeground(Qt::black);
            }
            else
            {
                Cell->setText("");
            }
        }
    }

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
    ui->erase_button->setCheckable(true);


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
            const QString str = QString::number(puzzle.at(i,j));
            Cell->setText(str);
        }
    }
}


void MainWindow::keypad_number_pressed()
{
    QPushButton * button = (QPushButton *)sender();
    activated_number = button->text().toUInt();
    button->setChecked(true);
}

void MainWindow::on_sudoku_board_cellClicked(int row, int column)
{
    QTableWidgetItem* cell = ui->sudoku_board->item(row, column);

    //qDebug() << ui->sudoku_board->item(row, column)->background().color() << "\n";

    // permanent cell
    if(cell->background().color() == Qt::green)
    {
        return;
    }

    else if(activated_number)
    {
        const QString str = QString::number(activated_number);
        cell->setText(str);
    }

    // else erase is selected
    else
    {
        cell->setText("");
    }
}

void MainWindow::on_erase_button_released()
{
    activated_number = 0;
    ui->erase_button->setChecked(true);
}

void MainWindow::on_reset_button_clicked()
{
    puzzle.generate_new_puzzle();
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            QTableWidgetItem* Cell = ui->sudoku_board->item(i, j);
            Cell->setTextAlignment(Qt::AlignCenter);
            if (puzzle.at(i, j))
            {
                const QString str = QString::number(puzzle.at(i, j));
                Cell->setText(str);
                Cell->QTableWidgetItem::setBackground(Qt::green);
                Cell->QTableWidgetItem::setForeground(Qt::black);
            }
            else
            {
                Cell->setText("");
            }
        }
    }
}
