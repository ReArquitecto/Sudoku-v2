#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
#include <algorithm>

class Board {
private:
    int board[9][9];

public:
    // Constructor
    Board() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = 0;
            }
        }
    }

    // Function to generate a random board
    void generate() {
    // Clear board
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            board[row][col] = 0;
        }
    }
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Shuffle the numbers
    std::mt19937 rng(std::random_device{}());
    std::shuffle(nums.begin(), nums.end(), rng);

    // fill first row
    for (int col = 0; col < 9; col++) {
        board[0][col] = nums[col];
    }

    // shuffle the list again
    std::shuffle(nums.begin(), nums.end(), rng);
    for (int row = 1; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] != 0) {
                continue;
            }
            else {
                for (int i = 0; i < nums.size(); i++) {
                    // check if number already exists in the same row, column, or 3x3 sub-grid
                    if (!isSafe(board, row, col, nums[i])) {
                        continue;
                    }
                    else {
                        board[row][col] = nums[i];
                        break;
                    }
                }
            }
        }
    }

    // remove some numbers
    int numRemoved = 0;
    std::uniform_int_distribution<> dist(0, 8);
    while (numRemoved < 40) {
        int row = dist(rng);
        int col = dist(rng);
        if (board[row][col] != 0) {
            board[row][col] = 0;
            numRemoved++;
        }
    }
}

// Function to check if a number is safe to place in a cell
    bool isSafe(int board[9][9], int row, int col, int num) {
        // Check row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) {
                return false;
            }
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) {
                return false;
            }
        }

        // Check 3x3 sub-grid
        int boxRow = row / 3;
        int boxCol = col / 3;
        for (int i = boxRow * 3; i < (boxRow + 1) * 3; i++) {
            for (int j = boxCol * 3; j < (boxCol + 1) * 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }


    // Function to set the value of a cell
    void setCell(int row, int col, int value) {
        if(row<0 || row>8 || col<0 || col>8 || value<1 || value>9){
            throw std::out_of_range("Invalid input, please try again");
        } 
        // code to set the value of a cell
        board[row][col] = value;
    }

    // Function to get the value of a cell
    int getCell(int row, int col) {
        if (row >= 0 && row < 9 && col >= 0 && col < 9) {
            return board[row][col];
        }
        else {
            return -1;
        }
    }

    // method to print the board
    void print() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Function to check if the board is complete
    bool isComplete() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // UNUSED SO FAR
    // Function to check if the board is valid
    bool isValid() {
        // Check rows
        for (int i = 0; i < 9; i++) {
            bool used[9] = { false };
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != 0) {
                    if (used[board[i][j] - 1]) {
                        return false;
                    }
                    used[board[i][j] - 1] = true;
                }
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            bool used[9] = { false };
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != 0) {
                    if (used[board[i][j] - 1]) {
                        return false;
                    }
                    used[board[i][j] - 1] = true;
                }
            }
        }

        // Check 3x3 sub-grids
        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                bool used[9] = { false };
                for (int i = boxRow * 3; i < (boxRow + 1) * 3; i++) {
                    for (int j = boxCol * 3; j < (boxCol + 1) * 3; j++) {
                        if (board[i][j] != 0) {
                            if (used[board[i][j] - 1]) {
                                return false;
                            }
                            used[board[i][j] - 1] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};

