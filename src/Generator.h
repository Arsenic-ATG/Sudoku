/*the program needs a solver.h to execute, it outputs three matrices first being a random number feeder to the SolveSudoku fn second is the
solved sudoku(mind u that there can be multiple solutions but the SolveSudoku gives just one soln) and the third is the final matrix we get
after hiding random cells*/

//Headers
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "sudoku.h"
#define MAX 9

void column_loop(std::vector<std::vector<int>>,bool[MAX],bool[3], int, int);
void gen_ins(std::vector<std::vector<int>>);
void gen_hide(std::vector<std::vector<int>>);

//main//
int main()
{
    std::vector<std::vector<int>> arr(MAX, std::vector<int>(MAX,0));
    bool solved_flag = 0;
    gen_ins(arr);
    std::cout << "\n\n\n";
    // SolveSudoku(arr, solved_flag); output from the solver goes here
    std::cout << "\n\n\n";
    gen_hide(arr);
    std::cout << "\n\n\n";
    return 0;
}

//this function traverses all numbers from 1-MAX and each row
void gen_ins(std::vector <std::vector<int>> arr)
{
    for (int i = 1; i < 10; i = i + 3)
    {
        bool blocked_col[MAX] = {0};
        bool blocked_square_1[3] = {0};
        bool blocked_square_2[3] = {0};
        bool blocked_square_3[3] = {0};
        //3 different loops bcs blocked_squre arrays get modified for each one of them
        for (int j = 0; j < 3; j++)
        {
            column_loop(arr, blocked_col, blocked_square_1, i, j);
        }
        for (int j = 3; j < 6; j++)
        {
            column_loop(arr, blocked_col, blocked_square_2, i, j);
        }
        for (int j = 6; j < MAX; j++)
        {
            column_loop(arr, blocked_col, blocked_square_3, i, j);
        }
    }
    return;
}
//this function traverses each cell of the matrix and decided whether to actually put the number or not
void column_loop(std::vector <std::vector<int>> arr, bool blocked_col[MAX], bool blocked_square[3], int i, int j)
{
    srand(time(0));
    for (int k = 0; k < MAX; k++)
    {
        if (rand() % 100 + 1 > 60 && !blocked_col[k] && !blocked_square[k / 3])
        {
            if (arr[j][k] == 0)
            {
                arr[j][k] = i;
                blocked_col[k] = 1;
                blocked_square[k / 3] = 1;
                break;
            }
        }
        else
            arr[j][k] = 0;
    }
    return;
}
//simple matrix/sudoku displayer
// void display(int arr[][MAX])
// {
//     for (int i = 0; i < MAX; i++)
//     {
//         for (int j = 0; j < MAX; j++)
//         {
//             if (j % 3 == 0 && j)
//                 std::cout << " || " << arr[i][j];
//             else
//                 std::cout << " " << arr[i][j];
//         }
//         std::cout << "\n------------------------" << std::endl;
//     }
//     return;
// }

//this function hides random cells from the solved sudoku and makes them 0
void gen_hide(std::vector <std::vector<int>> arr)
{
    srand(time(0));
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (rand() % 100 + 1 > 30)
            {
                arr[i][j] = 0;
            }
        }
    }
    std::cout << "\n\n\n";
}