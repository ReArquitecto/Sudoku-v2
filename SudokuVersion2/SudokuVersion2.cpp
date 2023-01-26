#include <iostream>
#include <exception>
#include "Board.cpp"
#include "Conversion.cpp"
#include <chrono>
#include <limits>

int main()
{
    //give a welcome message
    int removeAmt;
    std::cout << "Welcome to Sudoku!" << std::endl;
    std::cout << std::endl;
    std:: cout << "How many numbers would you like to remove from the board?" << std::endl;
    std:: cout << "Easy - 36-45, Medium - 46-50, Hard - 50-55: ";
    std::cin >> removeAmt;
    //create a new board
    Board board;
    //generate a random board
    board.generate(removeAmt);
    //ask if user would like to export the board
    std::cout << "Would you like to export the board to a file? (y/n): ";
    char exportBoard;
    std::cin >> exportBoard;
    if (exportBoard == 'y') {
        std::cout << "Enter the name of the file you would like to export to: ";
        std::string fileName;
        std::cin >> fileName;
        board.exportBoard(fileName);
    }

    //Ask the user if they would to play with placement warnings
    std::cout << "Would you like to play with placement warnings? (y/n): ";
    char setplacementWarnings;
    std::cin >> setplacementWarnings;
    bool PlacementWarnings;
    if (setplacementWarnings == 'y') {
        PlacementWarnings = true;
    }
    else {
        PlacementWarnings = false;
    }


    //loop until the board is solved
    //press enter to continue
    std::cin.ignore();
    std::cout << std::endl << "Press enter to start" << std::endl;
    std::cin.ignore();
    std::cout << std::endl << "If you mistype, just submit a letter instead of a number" << std::endl;

    // start a timer
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    while (!board.isComplete()) {
        // print the time elapsed so far
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << " seconds" << std::endl;
        //print the board
        std::cout << std::endl;
        board.print();
        //get the user input
        std::cin.clear();
        std::cout << std::endl;
        std::cout << "Three steps -> Enter the Subgrid, position, and new value: " << std::endl;
        int subgrid, position, value;
        std::cout << std::endl << "1. Enter the subgrid: ";
        std::cin >> subgrid;
        std::cout << std::endl << "2. Enter the position in the subgrid: ";
        std::cin >> position;
        std::cout << std::endl << "3. Enter the new value: ";
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl << "Invalid input, please try again with integers between 1 and 9" << std::endl;
            // press enter to continue
            std::cout << std::endl << "Press enter to continue" << std::endl;
            std::cin.ignore();

        }
        else if (subgrid < 1 || subgrid > 9 || position < 1 || position > 9 || value < 1 || value > 9) {
            std::cout << "Invalid input, please try again with integers between 1 and 9" << std::endl;
        }
        else {
            //convert the subgrid and position to row and column
            Conversion conversion(subgrid, position);
            int row = conversion.getRow();
            int col = conversion.getCol();
            row = row - 1;
            col = col - 1;
            // check to see if the move is valid
            if (PlacementWarnings == true) {
                if (board.isSafe(row, col, value) == false) {
                    std::cout << "Invalid move, please try again" << std::endl;
                    // press enter to continue
                    std::cout << std::endl << "Press enter to continue" << std::endl;
                    std::cin.ignore();
                }
                else {
                    //set the cell
                    board.setCell(row, col, value);
                }
            }
            else {
                //set the cell
                board.setCell(row, col, value);
            }
        }
    }
    // stop the timer
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << " seconds" << std::endl;

    //print the board
    board.print();
    //print a message
    std::cout << "Congratulations! You solved the puzzle!" << std::endl;
    
    return 0;

    //ask if user would like to export the final board
    std::cout << "Would you like to export the board to a file? (y/n): ";
    exportBoard;
    std::cin >> exportBoard;
    if (exportBoard == 'y') {
        std::cout << "Enter the name of the file you would like to export to: ";
        std::string fileName;
        std::cin >> fileName;
        // get time and date

        board.exportBoard(fileName);
    }
}
