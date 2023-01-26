# Sudoku-v2   
A Sudoku puzzle generator and player.   
The original Sudoku game is of Swiss origin    
and was later adopted by American, Japanese   
(where it was givin its name) and other cultures

## Features   
- Generate random boards of varying difficulties      
- Export Generated boards into files   
- Simple console user interface  
- Timed Gameplay   
- Turn on and off placement warnings   
- Time and record moves   
- Export game data  

## Instructions
- Fork, download or clone the repository to your local machine   
- Compile and run the code   

## Principle Classes and Methods
- Sudoku   
    - Welcome Message  
    - Generate new board  
    - Ask the user if they would like placement warnings  
    - Start game and timer  
    - Enter numbers by entering the index of the subrid, relative position in the subrid and entering the value  
    - Give timer updates and print the board when the user places values   
    - Convert the subgrid and relative position id's to row and column positioning    
    - check for errors and ask user to re-enter position if failure occurs   
    - Loop gameplay until board is solved  
    - Stop timer   
    - Offer to export gameplay information, time and board    

- Board  
    - Constructor  
    - generate  
    - isSafe (checks if a value is valid in a given position)  
    - setCell (sets the value of a cell)  
    - getCell (retrieves the value of a cell)  
    - print (prints the current board)  
    - isComplete (checks if the board is complete)  
    - export board (exports board to a file with user provided name)  
    - isValid (checks if the board is a valid configuration)   
    
- Conversion
    - takes subgrid number and position within the subgrid number
        - to get this count subgrid or position from left to right top to bottom.
    - Assign each subgrid starting row and column
    - Adds to starting row based on position id
        - 1, 2, 3 add 0 to row position
        - 4, 5, 6, add 1 to row position
        - 7, 8, 9, add 2 to row position
    - Add to starting column based on position id
        - 1, 4, 7 add 0 to column position
        - 2, 5, 8, add 1 to column position
        - 3, 6, 9, add 2 to column position
