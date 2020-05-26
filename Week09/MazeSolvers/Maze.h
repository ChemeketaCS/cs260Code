#ifndef MAZE_H
#define MAZE_H

#include <iostream>

const int MAZE_SIZE = 10;

struct Location {
    int row;
    int col;

    Location();
    Location(int r, int c);

    bool operator==(const Location& other) const;
    bool operator!=(const Location& other) const;
};

std::ostream& operator<<(std::ostream& os, const Location& aLocation);

struct LocationHasher {
    unsigned int operator()(const Location& l) const;
};

//-------------------------------------------------------------------

struct Maze {
    char cells[MAZE_SIZE][MAZE_SIZE] =
        {{'#','#','#','#',' ',' ','#','#','#','#'},
         {'#',' ',' ','#',' ',' ','#',' ',' ','#'},
         {'#',' ',' ','#',' ','#','#',' ','#','#'},
         {' ',' ','#','#',' ',' ',' ',' ',' ',' '},
         {' ','#','#',' ',' ',' ',' ','#','#','#'},
         {' ','#',' ',' ',' ',' ',' ','#',' ','#'},
         {' ','#',' ','#','#','#',' ','#',' ','#'},
         {' ','#',' ',' ',' ',' ',' ',' ',' ','#'},
         {' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
         {' ',' ',' ','#','#','#','#','#','#','#'}};

    void print() const;

    bool locationValid(const Location& loc) const;

    void mark(const Location& loc);
    void clear(const Location& loc);
};


#endif // MAZE_H
