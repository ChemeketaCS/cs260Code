#ifndef LISTNODE_H
#define LISTNODE_H

template<typename T>
class Node {
public:
  // Value stored in this node
  T element;
  // Next node in list (nullptr == end of list)
  Node* next = nullptr;

  // Node must be constructed with a value - stored as element
  Node(T value): element(value) {
  }
};

#endif // LISTNODE_H
