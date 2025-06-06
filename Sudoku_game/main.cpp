#include "Game_Sudoku.hpp"
int SudokuBoard::Mistakes_count=0;
int main() {
    int choice=0,row,col,value;
    int Exit=0;
    int solve=0;
    SudokuBoard s1;
    Solver s2; 
    s1.select_difficulty();
    int difficulty;
    std::cin >> difficulty;
    s1.load_preset_puzzle(difficulty);
    while(1)
    {
if (Exit == 0 && SudokuBoard::Mistakes_count < 3) 
    {
    if(solve==0)
    s1.print_board();
    console_app();
    std::cin>>choice;
    switch(choice)
    {
        case 1:
        solve=1;
        std::cout<<"Enter row (1-9), column (1-9), and value (1-9):"<<std::endl;
        std::cin>>row>>col>>value;
        try
        {
            s1.check_validity(row-1,col-1,value);
            std::cout<<"Move accepted!\n ";

        }
        catch(const std::runtime_error& e)
        {
          std::cerr<<e.what();
        }

        break;
        case 2: 
        solve=1;
        Exit=s2.solve(s1);
        s1.print_board();
        break;
        case 3:
        solve=1;
        load_file("Sudoku.txt");
        break;
        case 4:
        solve=1;
        Save_file(s1,"Sudoku.txt");
        break;
   
        case 5:
        {
        Exit=1;
      }
        break;
    }
 solve=0;
}
else
{
    std::cout<<"Game Terminated"<<std::endl;
    break;
}
}
}