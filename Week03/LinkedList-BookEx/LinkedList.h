#ifndef INTLINKEDLIST_H
#define INTLINKEDLIST_H

#include <cassert>
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

  ListNode(const T& value) {
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
  // These would normally be private.
  // They are public to enable simpler unit tests.
public:
  ListNode<T>* head;
  ListNode<T>* tail;
  int size;

public:
  /**
   * @brief Construct empty linked list
   */
  LinkedList();

  /**
   * @brief Copy constructor
   */
  LinkedList(const LinkedList& other);

  /**
   * @brief Assignment Operator
   */
  LinkedList& operator=(const LinkedList& other);

  /**
   * @brief Destructor
   */
  ~LinkedList();

  /**
   * @brief Print contents of list to cout
   */
  void print() const;

  /**
   * @brief Inserts given value at head of the list
   * @param value Value to insert
   */
  void insertStart(const T& value);

  /**
   * @brief Inserts given value at end of the list
   * @param value Value to insert
   */
  void insertEnd(const T& value);

  /**
   * @brief Remove first item from list
   * @throw out_of_range if list is empty
   */
  void removeStart();

  /**
   * @brief Removes all values from list
   */
  void clear();

  /**
   * @brief Make a deep copy of another lists nodes
   */
  void copyFrom(const LinkedList& other);

  /**
   * @brief Insert given value into list at given location
   * @param index Location to insert value
   * @throw out_of_range if index is invalid
   * @param value Value to insert
   */
  void insertAt(int index, const T& value);

  /**
   * @brief Remove item at given index from list
   * @param index Location of item to remove
   * @throw out_of_range if index is invalid
   */
  void removeAt(int index);

  /**
   * @brief Get the length of the list
   * @return int representing number of values (nodes) in list
   */
  int listSize() const;

  /**
   * @brief Gets value stored at specified index
   * @param index Location we want to retrieve from
   * @throw out_of_range if index is invalid
   * @return value
   */
  T retrieveAt(int index) const;

  /**
   * @brief Splice the nodes of another list onto the end of this list.
   *  After this operation, other list should be empty.
   * @param other List to splice onto end of this one
   */
  void splice(LinkedList& other);

  /**
   * @brief Split this list into two halves. The first half should remain in
   * this list, and the second half should be returned as a new list. If there
   * are an odd number of nodes, the extra node should go in the second half.
   * @return LinkedList containing second half of original list
   */
  LinkedList sliceInHalf();
};

//-------------------Provided Functions-------------------------

template<typename T>
LinkedList<T>::LinkedList() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}

template<typename T>
void LinkedList<T>::insertStart(const T& value) {
  ListNode<T>* temp = new ListNode<T>(value);

  temp->next = head; // old head is what new node points to
  head = temp;       // new node is now head

  // if this is the first node, it is tail and head
  if (size == 0)
    tail = head;

  size++;
}

template<typename T>
int LinkedList<T>::listSize() const {
  return size;
}

template<typename T>
void LinkedList<T>::print() const {
  // current will point to each element in turn
  ListNode<T>* current = head;

  while (current != nullptr) {
    cout << current->data << " "; // print current item
    current = current->next;      // advance to next
  }
  cout << endl;

  // Print out some extra info to help with debugging...
  cout << "Length is: " << size << endl;
  if (tail)
    cout << "Tail points at: " << tail->data << endl;
  else
    cout << "Tail has a nullptr" << endl;
}

template<typename T>
T LinkedList<T>::retrieveAt(int index) const {
  if (index < 0 || index >= size)
    throw out_of_range("Bad index in retrieveAt");

  ListNode<T>* current = head;
  for (int i = 0; i < index; i++) {
    current = current->next;
    // No need to check for nullptr here
  }

  return current->data;
}

template<typename T>
void LinkedList<T>::removeAt(int index) {
  if (index < 0 || index >= size)
    throw out_of_range("Bad index in removeAt");

  if (index == 0) {
    // First item is special case... use removeStart for it
    removeStart();
    return;
  }

  // Find node BEFORE one we want to delete
  ListNode<T>* current = head;
  for (int i = 0; i < index - 1; i++) {
    current = current->next;
  }
  ListNode<T>* nodeToRemove = current->next;

  // Cut node out of list
  current->next = nodeToRemove->next;

  delete nodeToRemove; // Delete it from heap

  // Is there nothing left after current node? Then it is the new tail
  if (current->next == nullptr)
    tail = current;

  size--;
}

template<typename T>
LinkedList<T>::~LinkedList() {
  clear();
}

//-------------------To be implemented-------------------------

template<typename T>
void LinkedList<T>::insertEnd(const T& value) {
    // TODO - fixme
    ListNode<T>* newNode = new ListNode<T>(value);
    if (size == 0) {
      // node is both head and tail
    } else {
      // attach to end of list and update tail
    }
    size++;
}

template<typename T>
void LinkedList<T>::removeStart() {
  if (head == nullptr)
    throw out_of_range("Can't remove from empty list");

  // TODO - Remove first item in list
}

template<typename T>
void LinkedList<T>::insertAt(int index, const T& value) {
  if (index < 0 || index > size)
    throw out_of_range("Bad insert index");
  // TODO - Insert value at given location of list
  // index 0 or size are special cases for insertStart/insertEnd
}

template<typename T>
void LinkedList<T>::clear() {
  // TODO - delete all nodes and make this into a valid empty list
}

template<typename T>
void LinkedList<T>::copyFrom(const LinkedList<T>& other) {
  // TODO - copy all values from other into this list. Assume this is
  // a valid empty list
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
  head = nullptr;
  tail = nullptr;
  size = 0;
  copyFrom(other);
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
  if (this == &other) {
    return *this; // Handle self-assignment
  }
  clear(); // remove existing nodes, reset head, tail, size
  copyFrom(other);
  return *this;
}


#endif
