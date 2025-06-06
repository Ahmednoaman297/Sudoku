#include <iostream>
#include "Board_Sudoku.hpp"
#include <random>
class Solver
{
    public:
    Solver();   
    bool check_generation(SudokuBoard& board, int x_row, int y_col, int z_value);
    bool Is_empty(SudokuBoard& board);
    bool solve(SudokuBoard& board);
    
};