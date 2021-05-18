#include "sudoku.h"
#include<math.h>

sudoku::sudoku() : MAX(9)
{
    is_solved = false;

    // resize the vector
    board.resize(MAX);
    for (int i = 0; i < MAX; ++i)
        board[i].resize(MAX);

    // generate a blank board
//    for (int i = 0; i < MAX; ++i)
//        for (int j = 0; j < MAX; ++j)
//            board[i][j] = 0;
    this->generate_new_puzzle();
}

//to check whether the board is full or not
bool sudoku::is_full()
{
    for(int i = 0 ; i < (MAX) ; i++)
        for(int j = 0 ; j < (MAX) ; j++)
            if(board[i][j] == 0)
                return false;
    return true;
}

// reading the borad
int sudoku::at(int x,int y)
{
    return this->board[x][y];
}

int sudoku::find_possible_values(std::vector<int> &possible_values, int r, int c)
{
    int n = 0;
    int i,j;
    const int s = static_cast<int>(sqrt((MAX)));
    std::vector<int> b(MAX+1,0);

    // Note numbers appeared in current row
    for(i = 0; i < (MAX) ; i++)
        b[board[r][i]] = 1;

    // Note numbers appeared in current column
    for(i = 0; i < (MAX) ; i++)
        b[board[i][c]] = 1;

    // Note numbers appeared in current block
    r = (r/s)*s, c = (c/s)*s;
    for(i = r; i < r+s; i++)
        for(j = c ; j < c+s ; j++)
            b[board[i][j]] = 1;

    // Fill array possible_values[] with numbers that can be filled in that perticular cell
    for(i = 1 ; i <= (MAX); i++)
        if(!b[i])
            possible_values[n++] = i;

    return n;
}


void sudoku::solve()
{
    int i, j, n = 0;
    std::vector<int> possible_values(MAX+1,0);

    // base case
    if(is_solved || is_full())
    {
        is_solved = 1;
        return;
    }

    // find next empty place on board
    bool break_flag = 0;
    for(i = 0 ; i < (MAX) ; i++)
    {
        for(j = 0 ; j < (MAX) ; j++)
            if(!board[i][j])
            {
                break_flag = 1;
                break;
            }

        if(break_flag)
            break;
    }

    // fill the array with all the possible values that we can fill in that empty cell
    n = find_possible_values(possible_values, i, j);
    for(int l = 0 ; l < n ; l++)
    {
        board[i][j] = possible_values[l];
        // solve the updated board
        solve();

        if(is_solved)
            return;
    }

    // nothing worked so reset and backtrack
    board[i][j] = 0;
}

void sudoku::generate_new_puzzle()
{
    // using this hard coded board till the time generater is not implementaed properly
    this->board = {
     { 0, 0, 0, 2, 6, 0, 7, 0, 1 },
     { 6, 8, 0, 0, 7, 0, 0, 9, 0 },
     { 1, 9, 0, 0, 0, 4, 5, 0, 0 },
     { 8, 2, 0, 1, 0, 0, 0, 4, 0 },
     { 0, 0, 4, 6, 0, 2, 9, 0, 0 },
     { 0, 5, 0, 0, 0, 3, 0, 2, 8 },
     { 0, 0, 9, 3, 0, 0, 0, 7, 4 },
     { 0, 4, 0, 0, 5, 0, 0, 3, 6 },
     { 7, 0, 3, 0, 1, 8, 0, 0, 0 }
    };
}
