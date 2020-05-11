#ifndef CHARBST_H
#define CHARBST_H

#include <string>

#include "BSTNode.h"

class CharBST {
//Would normally be private.
//Made public to allow intrusive unit tests.
public:
    BSTNode<char>* root;


public:
    ///Constructor - root inited to null
    CharBST();

    ///Destructor - deletes any child nodes
    ~CharBST();

    ///Copy constructor and assignment operator do deep copy
    CharBST(const CharBST& val);
    CharBST& operator=(const CharBST& val);

    ///Produce an in order string representation
    std::string toString() const;

    ///check if value is present
    bool containsRecursive(char val);

    ///remove indicated char from tree
    void remove(char val);

    ///remove the smallest value from the tree
    void removeSmallest();

    ///return true if no values in tree
    bool isEmpty();

};

#endif // CHARBST_H

