#ifndef BSTNODE_H
#define BSTNODE_H

template <class T>
struct BSTNode {
    //Store a value and two child pointers
    T value;
    BSTNode<T>* left;
    BSTNode<T>* right;

    ///-------------------------------------------------------
    ///  Everything else just to provide tracking of nodes
    ///-------------------------------------------------------

    //Constructor - left/right set to null
    BSTNode(T val);

    //Disable copy/assignment - these are declared but not defined
    BSTNode(const BSTNode<T>& val);
    BSTNode& operator=(const BSTNode<T>& val);

    //Destructor - decrement counter
    ~BSTNode();

    //Debugging purposes only - Not a normal feature
    //  Used for tracking memory allocation, updated in constructor/destructor
    static int nodeCount;
};

template <class T>
int BSTNode<T>::nodeCount = 0;

template <class T>
BSTNode<T>::BSTNode(T val) {
    value = val;
    left = nullptr;
    right = nullptr;
    nodeCount++;
}

template <class T>
BSTNode<T>::~BSTNode() {
    nodeCount--;
}

#endif // BSTNODE_H
