/**** headers ****/
#include <iostream>
#include <cmath>

/**** constants ****/

// This is the limit of size of sudoku board for now
// you can increase it but larger the sudoku, longer will be time taken to solve it.
#define MAX 9

/**** function declarations ****/

// utility functions
void takeInput(int[][MAX]);
void displaySolution(int [][MAX]);
bool isFull(int [][MAX]);
int findPossibleValues(int [][MAX], int [], int , int );

// solver function
void SolveSudoku(int [][MAX], bool &);

/**** the main() function ****/

//int main()
//{
//    // configuring vars
//    int sudoku[MAX][MAX] = {0};
//    bool solved_flag = 0;

//    // Input
//    takeInput(sudoku);

//    // Processing
//    std::cout<<"\n\nFinding Solution!\n\n";
//    SolveSudoku(sudoku, solved_flag);

//    // output
//    if(!solved_flag)
//        std::cout<<"Invalid Board!\n";
//    else
//    {
//        std::cout<<"solution found !\n";
//        displaySolution(sudoku);
//    }

//    return 0;
//}

/**** function definations ****/

void takeInput(int sudoku[][MAX])
{
    std::cout<<"Enter the Initial "<<MAX<<" X "<<MAX<<" Sudoku "<<std::endl;
    std::cout<<"Instruction: Enter 0 for blank"<<std::endl;

    for(int i = 0 ; i < (MAX) ; i++)
        for(int j = 0 ; j< (MAX) ; j++)
            std::cin>>sudoku[i][j];
}

//Function to display Sudoku Board
void displaySolution(int sudoku[][MAX])
{
    for(int i=0;i<(MAX);i++)
    {
        if(i%3==0 && i)
        {
             for(int j=0;j<24; j++)
                {
                    std::cout<<"=";
                }
                std::cout<<std::endl;
        }

        for(int j=0;j<(MAX); j++)
        {
            if(j%3==0 && j)
                std::cout<<"|| ";
            std::cout<<sudoku[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"\n\n*************************************************\n\n";
}

//to check whether the sudoku is full or not
bool isFull(int sudoku[][MAX])
{
    for(int i = 0 ; i < (MAX) ; i++)
        for(int j = 0 ; j < (MAX) ; j++)
            if(sudoku[i][j] == 0)
                return false;
    return true;
}

int findPossibleValues(int sudoku[][MAX], int a[], int r, int c)
{
    int n=0;
    int i,j;
    const int s = static_cast<int>(sqrt((MAX)));
    int b[MAX+1]={0};

    //Note numbers appeared in current row
    for(i = 0; i < (MAX) ; i++)
        b[sudoku[r][i]]=1;

    //Note numbers appeared in current column
    for(i = 0; i < (MAX) ; i++)
        b[sudoku[i][c]]=1;

    //Note numbers appeared in current block
    r = (r/s)*s, c = (c/s)*s;
    for(i = r; i < r+s; i++)
        for(j = c ; j < c+s ; j++)
            b[sudoku[i][j]]=1;

    //Fill array a[] with numbers that can be filled in that perticular cell
    for(i = 1 ; i <= (MAX); i++)
        if(!b[i])
            a[n++]=i;

    return n;
}


void SolveSudoku(int sudoku[][MAX], bool &solved_flag)
{
    int i, j, a[MAX+1]={0}, n=0;

    // base case
    if(solved_flag || isFull(sudoku))
    {
        solved_flag = 1;
        return;
    }

    // find next empty place on sudoku
    bool break_flag = 0;
    for(i = 0 ; i < (MAX) ; i++)
    {
        for(j = 0 ; j < (MAX) ; j++)
            if(!sudoku[i][j])
            {
                break_flag = 1;
                break;
            }

        if(break_flag)
            break;
    }

    //fill the array with all the possible values that we can fill in that empty cell
    n = findPossibleValues(sudoku, a, i, j);
    for(int l = 0 ; l < n ; l++)
    {
        sudoku[i][j] = a[l];
        //now solve the updated board
        SolveSudoku(sudoku, solved_flag);

        if(solved_flag)
            return;
    }

    // nothing worked so reset and backtrack
    sudoku[i][j]=0;
}
