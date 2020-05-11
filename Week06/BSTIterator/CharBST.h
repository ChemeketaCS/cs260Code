#ifndef CHARBST_H
#define CHARBST_H

#include <vector>
#include "BSTNode.h"
#include "CharBSTIterator.h"
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

    ///create a vector with contents of tree
    std::vector<char> toVector();

    ///get iterators to the tree
    CharBSTIterator begin();
    CharBSTIterator end();
};

#endif // CHARBST_H

