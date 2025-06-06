#include <iostream>
#include <vector>
#define rows 9
#define cols 9
class SudokuBoard {

    public:
    static int Mistakes_count;
    std::vector<std::vector<int>> board; 
    SudokuBoard();  // Constructor
    void select_difficulty(void) ;
    void check_validity(int x_row, int y_col, int z_value);
    void check_generation(int x_row, int y_col, int z_value);
    void generate_matrix();
    void print_board() const;
    void load_preset_puzzle(int difficulty) ;
};
std::ostream& operator<<(std::ostream& os, const SudokuBoard& board);
