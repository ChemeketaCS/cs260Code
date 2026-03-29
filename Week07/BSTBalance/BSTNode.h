#ifndef BSTNODE_H
#define BSTNODE_H

template<typename T>
struct BSTNode {
  /// Store a value and two child pointers
  T value;
  BSTNode<T>* left;
  BSTNode<T>* right;

  /// Constructor - left/right set to null
  BSTNode(T val);
};

template<typename T>
BSTNode<T>::BSTNode(T val) {
  value = val;
  left = nullptr;
  right = nullptr;
}

#endif // BSTNODE_H
