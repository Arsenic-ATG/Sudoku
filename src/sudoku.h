#ifndef SUDOKU_H

#include <vector>
#include<stdlib.h>
#include<time.h>

#define SUDOKU_H

class sudoku
{
    const int MAX;
    std::vector <std::vector<int>> board;
    bool is_solved;
    bool is_full();
    int find_possible_values(std::vector<int> &, int , int );

public:
    sudoku();
    int at(int,int);
    void generate_new_puzzle();
    void solve();
    void column_loop(std::vector<std::vector<int>>,bool[],bool[], int, int);
    void gen_ins(std::vector<std::vector<int>>);
    void gen_hide(std::vector<std::vector<int>>);
};

#endif // SUDOKU_H
