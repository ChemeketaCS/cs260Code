
#ifndef CHARBSTITERATOR_H
#define CHARBSTITERATOR_H

#include <vector>
#include "BSTNode.h"

class CharBSTIterator
{
//Declare CharBST a friend so it has access to the positionStack
friend class CharBST;

private:
    //Vector used as a stack:
    std::vector< BSTNode<char>* > positionStack;

public:
    //Constructor
    CharBSTIterator();

    //Compare two iterators with ==
    bool operator==(const CharBSTIterator& other) const;

    //Compare two iterators with !=
    bool operator!=(const CharBSTIterator& other) const;

    //Dereference iterator to retrieve data in current node
    // return reference to allow modification
    char& operator*();

    //Advance iterator position by one
    void operator++();

    //Dumps contents of stack to cout
    void printDebug();
};

#endif
