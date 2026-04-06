#ifndef LISTNODE_H
#define LISTNODE_H

template<typename T>
struct ListNode {
  T element;
  ListNode* next;

  ListNode(T value) {
    element = value;
    next = nullptr;
  }
};

#endif // LISTNODE_H
