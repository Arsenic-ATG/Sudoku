#ifndef SOLVER_H
#define SOLVER_H

#define MAX 9

#endif // SOLVER_H

/**** function declarations ****/

namespace sudoku {
// utility functions
void takeInput(int[][MAX]);
void displaySolution(int [][MAX]);
bool isFull(int [][MAX]);
int findPossibleValues(int [][MAX], int [], int , int );

// solver function
void SolveSudoku(int [][MAX], bool &);
void generate(int [][MAX]);

}
