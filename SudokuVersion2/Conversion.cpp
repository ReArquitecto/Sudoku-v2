class Conversion
{
private:
    int row;
    int col;

public:
    // create conversion constructor
    Conversion(int subgrid, int position)
    {   
        // Assign subgrid starting point
        if (subgrid == 1) {
            row = 1;
            col = 1;
        }
        else if (subgrid == 2) {
            row = 1;
            col = 4;
        }
        else if (subgrid == 3) {
            row = 1;
            col = 7;
        }
        else if (subgrid == 4) {
            row = 4;
            col = 1;
        }
        else if (subgrid == 5) {
            row = 4;
            col = 4;
        }
        else if (subgrid == 6) {
            row = 4;
            col = 7;
        }
        else if (subgrid == 7) {
            row = 7;
            col = 1;
        }
        else if (subgrid == 8) {
            row = 7;
            col = 4;
        }
        else if (subgrid == 9) {
            row = 7;
            col = 7;
        }
        
        // subgrid starting point to rows
        if (position == 1 || position == 2 || position == 3) {
            row = row;
        }
        else if (position == 4 || position == 5 || position == 6) {
            row = row + 1;
        }
        else if (position == 7 || position == 8 || position == 9) {
            row = row + 2;
        }

        // subgrid starting point to columns
        if (position == 1 || position == 4 || position == 7) {
            col = col;
        }
        else if (position == 2 || position == 5 || position == 8) {
            col = col + 1;
        }
        else if (position == 3 || position == 6 || position == 9) {
            col = col + 2;
        }
    }


    // create getRow and getColumn functions
    int getRow()
    {
        return row;
    }
    int getCol()
    {
        return col;
    }

};
