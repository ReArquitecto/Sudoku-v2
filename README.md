# Sudoku-v2   
A Sudoku puzzle generator and player.   
Sudoku is of 16th century Swiss origin. It recieved   
its name in Japan and was later adopted by American    
and other cultures and widly popularized by newspapers.
The first newspaper to host the puzzle was The Conway    
Daily Sun.


# Purpose

## Video Demonstration and Code Walkthrough
[Sudoku YouTube Video](https://youtu.be/tqNJvK5f7MM)

## Features   
- Generate random boards of varying difficulties      
- Export Generated boards into files   
- Simple console user interface  
- Timed Gameplay   
- Turn on and off placement warnings   
- Time and record moves   
- Export game data  

## To Do List
- Further randomize the board generation algorithm 
- Replace the number placeholders with dashes
- Improve visibility
- Improve placement warning errors
- Correct a specific bug where the user can win on incorrectly competed boards

## Instructions
- Fork, download or clone the repository to your local machine   
- Compile and run the code

## Thoughts
This simple project was a lot of fun to make. Take it as inspiration for your own projects. It is far from perfect 

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

## Where to learn   
In the development of this project, many sources were used among the following:   
- https://devdocs.io/cpp/ (DevDocks)   
- https://learn.microsoft.com/en-us/cpp/?view=msvc-170 (Microsoft Documentation)   
- https://stackoverflow.com/ (Stack Overflow)

I did not do very much research on Sudoku Puzzles and used intuition to figure out how to generate the puzzles, however if you would like to learn more about them, here are a few links that I found helpfull. 
- https://www.sudokuwiki.org/ (Sudoku Wiki)
- https://www.sudokudragon.com/unsolvable.htm (Sudoku Dragon)
- https://sudokuprimer.com/patterns.php (Sudoku Primer - analizes patterns found in puzzles)

The internet has lots of sources to learn to code as well as learn about Sudoku
