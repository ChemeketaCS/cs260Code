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

    ///Produce an in order string representation
    std::string toString() const;

    ///check if value is present
    bool containsRecursive(char val) const;
    bool containsIterative(char val) const;

    ///add (a possibly duplicate) value to tree
    void insertRecursive(char val);
    void insertIterative(char val);

    ///Disable copy/assignment - these are declared but not defined
    CharBST(const CharBST& val);
    CharBST& operator=(const CharBST& val);
};

#endif // CHARBST_H

