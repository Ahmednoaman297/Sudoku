#include <iostream>
#include <random>
#include "Solver_Sudoku.hpp"

Solver::Solver() {}

bool Solver::check_generation(SudokuBoard& board, int x_row, int y_col, int z_value) {
    for (int j = 0; j < cols; j++) {
        if (board.board[x_row][j] == z_value) return false;
    }
    for (int i = 0; i < rows; i++) {
        if (board.board[i][y_col] == z_value) return false;
    }

    int startRow = (x_row / 3) * 3;
    int startCol = (y_col / 3) * 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board.board[startRow + i][startCol + j] == z_value)
                return false;
        }
    }
    return true;
}

bool Solver::Is_empty(SudokuBoard& board) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board.board[i][j] == 0)
                return true;
        }
    }
    return false;
}

bool Solver::solve(SudokuBoard& board) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board.board[i][j] == 0) {
                for (int k = 1; k <= cols; k++) {
                    if (check_generation(board, i, j, k)) {
                        board.board[i][j] = k;

                        if (solve(board))
                            return true;

                        board.board[i][j] = 0; 
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}
