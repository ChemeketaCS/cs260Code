#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

#include "LinkedListIterator.h"
#include "ListNode.h"
template<typename T>
class LinkedList {
private:
  ListNode<T>* head = nullptr; // Pointer to the first node in the list
  ListNode<T>* tail = nullptr; // Pointer to the last node in the list
public:
  LinkedList();
  ~LinkedList();

  LinkedList(const LinkedList&) = delete;
  LinkedList& operator=(const LinkedList&) = delete;

  void insertFront(T value);

  ListIterator<T> begin();
  ListIterator<T> end();
};

template<typename T>
ListIterator<T> LinkedList<T>::begin() {
  return ListIterator<T>(head);
}

template<typename T>
ListIterator<T> LinkedList<T>::end() {
  return ListIterator<T>(nullptr);
}

template<typename T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr) {
}

template<typename T>
LinkedList<T>::~LinkedList() {
  while (head != nullptr) {
    ListNode<T>* temp = head;
    head = head->next;
    delete temp;
  }
}

template<typename T>
void LinkedList<T>::insertFront(T value) {
  ListNode<T>* newNode = new ListNode<T>(value);
  newNode->next = head;
  head = newNode;
  if (tail == nullptr) {
    tail = newNode;
  }
}

#endif
