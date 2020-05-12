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
};

template <class T>
BSTNode<T>::BSTNode(T val) {
    value = val;
    left = nullptr;
    right = nullptr;
}

#endif // BSTNODE_H
