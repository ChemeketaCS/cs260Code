#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>

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

#endif // LOCATION_H
