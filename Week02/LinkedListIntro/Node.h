#ifndef LISTNODE_H
#define LISTNODE_H

template<typename T>
class Node {
public:
  // Value stored in this node
  int data;
  // Next node in list (nullptr == end of list)
  ListNode* next = nullptr;

  // Node must be constructed with a value - stored as data
  Node(int value) {
    data = value;
  }
};

#endif // LISTNODE_H
