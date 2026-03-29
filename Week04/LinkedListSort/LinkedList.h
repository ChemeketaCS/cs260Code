#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

///-----------------------------LIST NODE---------------------------------
template<typename T>
struct ListNode {
  T data;
  ListNode* next;

  // Maintain a count of active nodes for testing
  //  Not normally a part of the struct.
  //  You should NOT modify or even use this value in your code.
  static int nodeCount;

  ListNode(T value) {
    data = value;
    next = nullptr;
    nodeCount++;
  }

  ~ListNode() {
    nodeCount--;
  }
};

template<typename T>
int ListNode<T>::nodeCount = 0;

///-----------------------------LINKED LIST---------------------------------
template<typename T>
class LinkedList {
  // These would normally be private. They are public to enable simpler unit
  // tests.
public:
  ListNode<T>* head;
  ListNode<T>* tail;
  int size;

public:
  //-----------New Functions-----------------------
  /**
   * @brief Cuts list into two halves.
   *   This linked list retains first half of data,
   *   secondHalfList contains data from midpoint to end
   *
   *   If there are an odd number of items, the middle one should be part of
   *    the second half
   *
   * @return list containing second half of this list
   */
  LinkedList<T> sliceInHalf();

  /**
   * @brief Move all values from otherList to this one
   * @param otherList sorted LinkedList. Left empty by this function.
   *
   * @pre Assumes the list this is called on is empty
   */
  void splice(LinkedList<T>& otherList);

  /**
   * @brief mergeIn combines otherList into this list to produce one long sorted
   * list.
   * @param otherList sorted LinkedList. Left empty by this function
   *
   * @pre Assumes this list and other List are both sorted lists
   */
  void mergeIn(LinkedList<T>& otherList);

  /**
   * @brief mergeSort Sorts this linked list using mergesort algorithm
   */
  void mergeSort();

  //-----------Other functions------------------------
  LinkedList();
  ~LinkedList();
  LinkedList(const LinkedList<T>& otherList);
  // declared but not implemented:
  LinkedList<T>& operator=(const LinkedList<T>& otherList);

  void insertEnd(T value);
  T removeStart();
  T retrieveAt(int index) const;
};

///-----------------------------SORT RELATED-----------------------

template<typename T>
void LinkedList<T>::splice(LinkedList<T>& otherList) {
  // TODO - FIXME
  // Move all data from otherList to this one
  // Other list ends up empty
}

template<typename T>
LinkedList<T> LinkedList<T>::sliceInHalf() {
  ListNode<T>* cur = head;
  for (int i = 0; i < size / 2 - 1; i++) {
    cur = cur->next;
  }

  // Create the LinkedList we will return
  LinkedList<T> otherList;

  // TODO - FIXME
  // Set up head, tail and size of other list so it gets
  //  everything after the current pointer
  // Update the tail of this list and disconnect it from second half
  // Update size of both lists

  return otherList;
}

template<typename T>
void LinkedList<T>::mergeIn(LinkedList<T>& otherList) {
  // Temporary list we will build up results in
  LinkedList<T> mergeList;

  // TODO:
  // Merge this and otherList into mergeList
  //  by moving one value at a time to it.

  // Steal the data from mergeList back to this list
}

template<typename T>
void LinkedList<T>::mergeSort() {
  if (this->size <= 1)
    return;

  // Split so this list retains first half of the items
  //  and secondList contains the rest of of them
  LinkedList<T> secondList = this->sliceInHalf();

  this->mergeSort();      // sort first half
  secondList.mergeSort(); // sort second half

  // Combine them back into one list
  this->mergeIn(secondList);
}

///-----------------------------OTHER LINKED LIST
///FUNCTIONS-----------------------

template<typename T>
LinkedList<T>::LinkedList() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
  while (size > 0) {
    removeStart();
  }
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherList) {
  head = nullptr;
  tail = nullptr;
  size = 0;

  ListNode<T>* currentInOther = otherList.head;
  while (currentInOther != nullptr) {
    this->insertEnd(currentInOther->data);
  }
}

template<typename T>
void LinkedList<T>::insertEnd(T value) {
  ListNode<T>* current = new ListNode<T>(value);
  if (size == 0) {
    head = current;
  } else {
    tail->next = current;
  }
  tail = current;
  size++;
}

template<typename T>
T LinkedList<T>::removeStart() {
  if (size == 0) {
    throw out_of_range("Can't removeStart from empty list");
  }

  ListNode<T>* nodeToDelete = head;
  T value = nodeToDelete->data;

  head = head->next;
  delete nodeToDelete;
  size--;

  if (size == 0)
    tail = nullptr;

  return value;
}

template<typename T>
T LinkedList<T>::retrieveAt(int index) const {
  if (index < 0 || index >= size)
    throw out_of_range("Bad index in retrieveAt");

  ListNode<T>* current = head;
  for (int stepsLeft = index; stepsLeft > 0; stepsLeft--) {
    current = current->next;
  }

  return current->data;
}

#endif
