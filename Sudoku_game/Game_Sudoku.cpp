#include<iostream>
#include <fstream>
#include "Game_Sudoku.hpp"
void Save_file(SudokuBoard object,std::string text)
{
  std::ofstream outputFile(text);
            if (!outputFile.is_open()) {
                std::cerr << "Couldn't open file for writing!\n";
            }
            outputFile << object;
            std::cout << "Board saved to Sudoku.txt\n";
            outputFile.close();
}
void load_file(std::string text)
{
     std::ifstream inputFile(text);
            std::string line;
            if(!inputFile.is_open())
            {
                throw std::runtime_error("Couldn't open file for reading!" );
            }
            while(std::getline(inputFile,line))
            {
                std::cout<<line<<"\n";
            }
            inputFile.close();
}
void console_app(void)
{   
     std::cout<<"Options:\n" << "1) Enter a move\n"
    << "2) Solve automatically\n"
    << "3) Load puzzle from file\n"
    << "4) Save current puzzle to file\n"
    << "5) Exit\n"
    << "Choice: ";
}