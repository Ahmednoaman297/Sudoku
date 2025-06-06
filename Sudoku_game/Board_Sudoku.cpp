#include "Board_Sudoku.hpp"
#include <random>
#include <stdexcept>

SudokuBoard::SudokuBoard() : board(9, std::vector<int>(9, 0)) {}
    void SudokuBoard::select_difficulty(void) {
    std::cout << "=========================================\n";
    std::cout << "       Welcome to the Sudoku Game!\n";
    std::cout << "=========================================\n\n";
    std::cout << "Please select a difficulty level:\n\n";
    std::cout << "   1) Easy\n";
    std::cout << "   2) Medium\n";
    std::cout << "   3) Hard\n\n";
    std::cout << "Enter your choice (1-3): ";
}

void SudokuBoard::load_preset_puzzle(int difficulty) {
      int easy[9][9] = {
        {4, 0, 0, 0, 5, 0, 8, 0, 6},
        {0, 5, 6, 0, 0, 8, 0, 0, 0},
        {0, 0, 0, 6, 0, 0, 1, 0, 0},
        {0, 0, 8, 0, 6, 0, 0, 3, 0},
        {0, 6, 0, 0, 0, 0, 0, 9, 0},
        {0, 1, 0, 0, 4, 0, 6, 0, 0},
        {0, 0, 5, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 9, 0, 0, 2, 7, 0},
        {3, 0, 9, 0, 7, 0, 0, 0, 4}
    };

    int medium[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int hard[9][9] = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };

    const int (*selected_puzzle)[9] = nullptr;
    switch(difficulty) {
        case 0: selected_puzzle = easy; break;
        case 1: selected_puzzle = medium; break;
        case 2: selected_puzzle = hard; break;
        default: selected_puzzle = medium;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = selected_puzzle[i][j];
        }
    }
}

void SudokuBoard::check_validity(int x_row, int y_col, int z_value) {
    if (board[x_row][y_col] != 0)
    {
                Mistakes_count++;
        throw std::runtime_error("Cell already filled.\n");
    }

    for (int j = 0; j < cols; j++)
        if (board[x_row][j] == z_value)
        {
            Mistakes_count++;
            throw std::runtime_error("Value exists in row.\n");
          


        }

    for (int i = 0; i < rows; i++)
        if (board[i][y_col] == z_value)
        {
             Mistakes_count++;
            throw std::runtime_error("Value exists in column.\n");


        }

    int startRow = (x_row / 3) * 3;
    int startCol = (y_col / 3) * 3;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[startRow + i][startCol + j] == z_value)
            {
             Mistakes_count++;
                throw std::runtime_error("Value exists in subgrid.\n");


            }

    board[x_row][y_col] = z_value;
}

void SudokuBoard::check_generation(int x_row, int y_col, int z_value) 
{
    bool checker = true;

    for (int j = 0; j < cols; j++)
        if (board[x_row][j] == z_value)
            checker = false;

    for (int i = 0; i < rows; i++)
        if (board[i][y_col] == z_value)
            checker = false;

    int startRow = (x_row / 3) * 3;
    int startCol = (y_col / 3) * 3;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[startRow + i][startCol + j] == z_value)
                checker = false;

    if (checker)
        board[x_row][y_col] = z_value;
}

void SudokuBoard::generate_matrix() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 9);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            check_generation(i, j, dis(gen));
}

void SudokuBoard::print_board() const {
    std::cout << "\nMistakes: " << SudokuBoard::Mistakes_count << " / 3\n";
    std::cout << "     1 2 3   4 5 6   7 8 9\n";
    std::cout << "   +-------+-------+-------+\n";

    char row_labels[] = {'A','B','C','D','E','F','G','H','I'};
    
    for (int i = 0; i < rows; i++) {
        std::cout << " " << row_labels[i] << " |";
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 0)
                std::cout << " .";
            else
                std::cout << " " << board[i][j];

            if ((j + 1) % 3 == 0)
                std::cout << " |";
        }
        std::cout << "\n";
        if ((i + 1) % 3 == 0)
            std::cout << "   +-------+-------+-------+\n";
    }
}


std::ostream& operator<<(std::ostream& os, const SudokuBoard& board) 
{
    os << "\nMistakes: " << SudokuBoard::Mistakes_count << " / 3\n";
    os << "     1 2 3   4 5 6  7 8 9\n";
    os<< "   +-------+-------+-------+\n";

    char row_labels[] = {'A','B','C','D','E','F','G','H','I'};
    for (int i = 0; i < rows; i++) {
        os << " " << row_labels[i] << " |";
        for (int j = 0; j < cols; j++) {
            if (board.board[i][j] == 0)
                os<< " .";
            else
                os<< " " << board.board[i][j];

            if ((j + 1) % 3 == 0)
                os<< " |";
        }
        os << "\n";
        if ((i + 1) % 3 == 0)
            os << "   +-------+-------+-------+\n";
    }
        return os;
    }