#ifndef BSTNODE_H
#define BSTNODE_H

template <class T>
struct BSTNode {
    ///Store a value and two child pointers
    T value;
    BSTNode<T>* left;
    BSTNode<T>* right;

    ///Constructor - left/right set to null
    BSTNode(T val);

    ///Destructor - decrement counter
    ~BSTNode();

    ///Debugging purposes only - Not a normal feature
    ///  Used for tracking memory allocation, updated in constructor/destructor
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
