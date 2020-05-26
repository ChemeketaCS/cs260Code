#include <iostream>
#include <exception>

using namespace std;

#include "Maze.h"

Location::Location() {
    row = 0;
    col = 0;
}

Location::Location(int r, int c) {
    row = r;
    col = c;
}

bool Location::operator==(const Location& other) const {
    return row == other.row && col == other.col;
}

bool Location::operator!=(const Location& other) const {
    return row != other.row || col != other.col;
}

unsigned int LocationHasher::operator()(const Location& l) const {
    return l.col << 16 ^ l.row;
}


void Maze::print() const {
    //column headers
    cout << " ";
    for(int c = 0; c < MAZE_SIZE; c++)
        cout << c;
    cout << endl;

    for(int r = 0; r < MAZE_SIZE; r++) {
        cout << r;  //row header
        for(int c = 0; c < MAZE_SIZE; c++) {
            cout << cells[r][c] ;
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}



bool Maze::locationValid(const Location& loc) const {
    if(loc.row < 0 || loc.col < 0 || loc.row >= MAZE_SIZE || loc.col >= MAZE_SIZE)
    {
        return false;   //went out of bounds
    }
    if(cells[loc.row][loc.col] != ' ') {
        return false;   //hit wall/our existing path
    }
    return true;
}

void Maze::mark(const Location& loc) {
    cells[loc.row][loc.col] = '.';
}

void Maze::clear(const Location& loc) {
    cells[loc.row][loc.col] = ' ';
}
