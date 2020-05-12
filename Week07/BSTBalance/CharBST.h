#ifndef CHARBST_H
#define CHARBST_H

#include "BSTNode.h"

class CharBST {
public:  ///Public to allow testing of helper functions outside the class
    BSTNode<char>* root;

    ///Helper function for cleaning up memory
    void deleteSubTree(BSTNode<char>* startNode);


    /**
     * @brief rotateLeft rotates the parent to the left, pulling up right child
     * @return the newly promoted parent node
     */
    BSTNode<char>* rotateLeft(BSTNode<char>* parent);

    /**
     * @brief rotateRight rotates the parent to the right, pulling up left child
     * @return the newly promoted parent node
     */
    BSTNode<char>* rotateRight(BSTNode<char>* parent);

public:
    ///Constructors/assignment op
    CharBST();
    CharBST(const CharBST& other);
    CharBST& operator=(const CharBST& other);
    ///Destructor - deletes any child nodes
    ~CharBST();

    ///in order print
    void print();

    void splay();
};


#endif // CHARBST_H

