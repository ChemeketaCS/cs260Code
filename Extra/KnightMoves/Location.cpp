#include "Location.h"

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


std::ostream& operator<<(std::ostream& os, const Location& aLocation) {
    os << "(" << aLocation.row << "," << aLocation.col << ")";
    return os;
}


unsigned int LocationHasher::operator()(const Location& l) const {
    return l.col << 16 ^ l.row;
}
