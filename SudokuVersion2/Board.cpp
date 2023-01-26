#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

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
    void generate(int removeAmt) {

        // Clear board
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                board[row][col] = 0;
            }
        }

        //Grab numbers 1-9
        std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        // Shuffle the numbers
        std::mt19937 rng(std::random_device{}());
        std::shuffle(nums.begin(), nums.end(), rng);

        // Split the numbers into 3 groups
        std::vector<int> group1 = { nums[0], nums[1], nums[2] };
        std::vector<int> group2 = { nums[3], nums[4], nums[5] };
        std::vector<int> group3 = { nums[6], nums[7], nums[8] };

        // fill in first row group 1 group 2 group 3
        for (int i = 0; i < 3; i++) {
            board[0][i] = group1[i];
            board[0][i + 3] = group2[i];
            board[0][i + 6] = group3[i];
        }

        // fill in second row group 2 group 3 group 1
        for (int i = 0; i < 3; i++) {
            board[1][i] = group2[i];
            board[1][i + 3] = group3[i];
            board[1][i + 6] = group1[i];
        }

        // fill in third row group 3 group 1 group 2
        for (int i = 0; i < 3; i++) {
            board[2][i] = group3[i];
            board[2][i + 3] = group1[i];
            board[2][i + 6] = group2[i];
        }

        // mix up numbers
        // Split the numbers into 3 groups
        group1 = { nums[2], nums[0], nums[1] };
        group2 = { nums[5], nums[3], nums[4] };
        group3 = { nums[8], nums[6], nums[7] };

        // fill in fourth row group 1 group 2 group 3
        for (int i = 0; i < 3; i++) {
            board[3][i] = group1[i];
            board[3][i + 3] = group2[i];
            board[3][i + 6] = group3[i];
        }

        // fill in fifth row group 2 group 3 group 1
        for (int i = 0; i < 3; i++) {
            board[4][i] = group2[i];
            board[4][i + 3] = group3[i];
            board[4][i + 6] = group1[i];
        }

        // fill in sixth row group 3 group 1 group 2
        for (int i = 0; i < 3; i++) {
            board[5][i] = group3[i];
            board[5][i + 3] = group1[i];
            board[5][i + 6] = group2[i];
        }

        // mix up numbers
        // Split the numbers into 3 groups
        group1 = { nums[1], nums[2], nums[0] };
        group2 = { nums[4], nums[5], nums[3] };
        group3 = { nums[7], nums[8], nums[6] };

        // fill in seventh row group 1 group 2 group 3
        for (int i = 0; i < 3; i++) {
            board[6][i] = group1[i];
            board[6][i + 3] = group2[i];
            board[6][i + 6] = group3[i];
        }

        // fill in eighth row group 2 group 3 group 1
        for (int i = 0; i < 3; i++) {
            board[7][i] = group2[i];
            board[7][i + 3] = group3[i];
            board[7][i + 6] = group1[i];
        }

        // fill in ninth row group 3 group 1 group 2
        for (int i = 0; i < 3; i++) {
            board[8][i] = group3[i];
            board[8][i + 3] = group1[i];
            board[8][i + 6] = group2[i];
        }

        // mix up columns
        // Split the columns into vectors
        std::vector<int> col1 = { board[0][0], board[1][0], board[2][0], board[3][0], board[4][0], board[5][0], board[6][0], board[7][0], board[8][0] };
        std::vector<int> col2 = { board[0][1], board[1][1], board[2][1], board[3][1], board[4][1], board[5][1], board[6][1], board[7][1], board[8][1] };
        std::vector<int> col3 = { board[0][2], board[1][2], board[2][2], board[3][2], board[4][2], board[5][2], board[6][2], board[7][2], board[8][2] };
        std::vector<int> col4 = { board[0][3], board[1][3], board[2][3], board[3][3], board[4][3], board[5][3], board[6][3], board[7][3], board[8][3] };
        std::vector<int> col5 = { board[0][4], board[1][4], board[2][4], board[3][4], board[4][4], board[5][4], board[6][4], board[7][4], board[8][4] };
        std::vector<int> col6 = { board[0][5], board[1][5], board[2][5], board[3][5], board[4][5], board[5][5], board[6][5], board[7][5], board[8][5] };
        std::vector<int> col7 = { board[0][6], board[1][6], board[2][6], board[3][6], board[4][6], board[5][6], board[6][6], board[7][6], board[8][6] };
        std::vector<int> col8 = { board[0][7], board[1][7], board[2][7], board[3][7], board[4][7], board[5][7], board[6][7], board[7][7], board[8][7] };
        std::vector<int> col9 = { board[0][8], board[1][8], board[2][8], board[3][8], board[4][8], board[5][8], board[6][8], board[7][8], board[8][8] };

        // make vectors for col1 col2 col3
        std::vector<std::vector<int>> colgroup1 = { col1, col2, col3 };
        std::vector<std::vector<int>> colgroup2 = { col4, col5, col6 };
        std::vector<std::vector<int>> colgroup3 = { col7, col8, col9 };


        // shuffle colgroups
        std::shuffle(colgroup1.begin(), colgroup1.end(), rng);
        std::shuffle(colgroup2.begin(), colgroup2.end(), rng);
        std::shuffle(colgroup3.begin(), colgroup3.end(), rng);

        // assign new values to board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 9; j++) {
                board[j][i] = colgroup1[i][j];
                board[j][i + 3] = colgroup2[i][j];
                board[j][i + 6] = colgroup3[i][j];
            }
        }

        // remove some numbers
        int numRemoved = 0;
        std::uniform_int_distribution<> dist(0, 8);
        while (numRemoved < removeAmt) {
            int row = dist(rng);
            int col = dist(rng);
            if (board[row][col] != 0) {
                board[row][col] = 0;
                numRemoved++;
            }
        }
        std::cout << "" << std::endl;
        std::cout << "Board Generated" << std::endl;
    }

    // Function to check if a number is safe to place in a cell
    bool isSafe(int row, int col, int value) {
        // check if the value is already in the row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == value) {
                return false;
            }
        }

        // check if the value is already in the column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == value) {
                return false;
            }
        }

        // check if the value is already in the 3x3 box
        int boxRow = row - row % 3;
        int boxCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[boxRow + i][boxCol + j] == value) {
                    return false;
                }
            }
        }

        // if the value is not in the row, column or 3x3 box, return true
        return true;
    }


    // Function to set the value of a cell
    void setCell(int row, int col, int value) {
        if (row < 0 || row>8 || col < 0 || col>8 || value < 1 || value>9) {
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

    void print() {
        for (int i = 0; i < 9; i++) {
            // add an extra space every three rows
            if (i % 3 == 0) {
                std::cout << std::endl;
            }
            for (int j = 0; j < 9; j++) {
                // add an extra space every three columns
                if (j % 3 == 0) {
                    std::cout << " ";
                }
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

    // Function to export the board to a new file
    void exportBoard(std::string filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    file << board[i][j] << " ";
                }
                file << std::endl;
            }
            file.close();
        }
        else {
            throw std::runtime_error("Unable to open file");
        }
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

