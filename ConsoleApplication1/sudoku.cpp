#include <iostream>
#include <exception>
#include "Board.cpp"

int main()
{
    //give a welcome message
    std::cout << "Welcome to Sudoku!" << std::endl;
    //create a new board
    Board board;
    //generate a random board
    board.generate();
    //loop until the board is solved
    while (!board.isComplete()) {
        //print the board
        // board.print();
        //get the user input
        std::cin.clear();
        std::cout << "Enter the row, column, and value of the cell you want to change: ";
        int row, col, value;
        std::cin >> row >> col >> value;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Invalid input, please try again with integers");
    }
    if(row<0 || row>8 || col<0 || col>8 || value<1 || value>9){
        throw std::out_of_range("Invalid input, please try again");
    }            
    try
    {
    board.setCell(row, col, value);
    }
    catch (const std::out_of_range& oor)
    {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
    catch (const std::runtime_error& e)
    {
    std::cerr << e.what() << '\n';
    }
    }
    //print the board
    board.print();
    //print a message
    std::cout << "Congratulations! You solved the puzzle!" << std::endl;
    return 0;
}
