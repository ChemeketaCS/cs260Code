#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H

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
class SimpleLinkedList {
  // Would normally be private. Public to enable simpler unit tests.
public:
  ListNode<T>* head;

public:
  /**
   * @brief Construct empty linked list
   */
  SimpleLinkedList();

  /**
   * @brief Copy constructor
   */
  SimpleLinkedList(const SimpleLinkedList& other);

  /**
   * @brief Assignment Operator
   */
  SimpleLinkedList& operator=(const SimpleLinkedList& other);

  /**
   * @brief Destructor
   */
  ~SimpleLinkedList();

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
   * @throw out_of_range if empty
   */
  void removeFirst();

  /**
   * @brief Removes all values from list
   */
  void clear();

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
};

//-------------------Provided Functions-------------------------

template<typename T>
SimpleLinkedList<T>::SimpleLinkedList() {
  head = nullptr;
}

template<typename T>
void SimpleLinkedList<T>::insertStart(const T& value) {
  ListNode<T>* temp = new ListNode<T>(value);

  temp->next = head; // old head is what new node points to
  head = temp;       // new node is now head
}

template<typename T>
int SimpleLinkedList<T>::listSize() const {
  // Todo - loop though list and count the number of nodes
  return 0; // fixme
}

template<typename T>
void SimpleLinkedList<T>::print() const {
  // current will point to each element in turn
  ListNode<T>* current = head;

  while (current != nullptr) {
    cout << current->data << " "; // print current item
    current = current->next;      // advance to next
  }
  cout << endl;
}

template<typename T>
T SimpleLinkedList<T>::retrieveAt(int index) const {
  if (index < 0)
    throw out_of_range("Index out of range");

  ListNode<T>* current = head;
  for (int i = 0; i < index; i++) {
    current = current->next;
    if (current == nullptr) {
      throw std::out_of_range("Index out of range");
    }
  }
  return current->data;
}

template<typename T>
void SimpleLinkedList<T>::removeAt(int index) {
    // No bounds checking!

    // First item is special case... use removeFirst for it
    if(index == 0) {
        removeFirst();
        return;
    }
    ListNode<T>* current = head;
    // Move current to the node before the desired index
    for(int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    ListNode<T>* toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;
}

//-------------------To be implemented-------------------------

template<typename T>
void SimpleLinkedList<T>::insertEnd(const T& value) {
  // TODO - Fixme
}

template<typename T>
void SimpleLinkedList<T>::removeFirst() {
  if (head == nullptr)
    throw out_of_range("Can't remove from empty list");

  // TODO - Remove first item in list
  ListNode<T>* toDelete = head;
  head = head->next;
  delete toDelete;
}

template<typename T>
void SimpleLinkedList<T>::insertAt(int index, const T& value) {
  // TODO - Insert value at given location of list
  // index 0 is a special case for insertStart
}

template<typename T>
void SimpleLinkedList<T>::clear() {
  // TODO - delete all nodes and make this into a valid empty list
}

template<typename T>
SimpleLinkedList<T>::~SimpleLinkedList() {
  clear();
}

template<typename T>
SimpleLinkedList<T>::SimpleLinkedList(const SimpleLinkedList<T>& other) {
  // TODO - Write copy constructor...
  // Don't forget to initialize head/tail/length

  assert(0); // blow up for now - remove this
}

template<typename T>
SimpleLinkedList<T>&
SimpleLinkedList<T>::operator=(const SimpleLinkedList<T>& other) {
  // TODO - Write assignment operator...
  // Don't forget to avoid self assignment

  assert(0); // blow up for now - remove this
}

#endif
