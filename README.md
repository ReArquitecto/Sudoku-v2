# sudoku
A re-creation of the popular Sudoku game of Swiss origin later adopted by Japanese and other cultures written in C++ 

create a board
make a list from 1-9
randomize the list
assign the list from 0,0 to 0,8
make a new list from 1-9
randomize the list
loop through the rest of the columns {
    loop through the second row {
        loop through the list of rand 1-9 {
            if number exists in column
                continue
          else
                fill in number and remove from list
        }
    }
}  