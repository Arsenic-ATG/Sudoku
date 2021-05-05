#ifndef SUDOKU_H

#include <vector>

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
};

#endif // SUDOKU_H
