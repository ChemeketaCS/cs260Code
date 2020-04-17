#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

#include "ListNode.h"
#include "LinkedListIterator.h"

template <class T>
class LinkedList
{
    //These would normally be private. They are public to enable simpler unit tests.
public:
    ListNode<T>* head;
    ListNode<T>* tail;

public:

    ///New Functions:
    //Get an iterator that points to head
    LinkedListIterator<T> begin();
    //Get an iterator that points to null (one step past tail)
    LinkedListIterator<T> end();

    //Inserts a value after the given iterator
    void insertAfter(const LinkedListIterator<T>& location, const T& value);


    //-----------Other functions------------------------
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T>& otherList);

    //declared but not implemented:
    LinkedList<T>& operator=(const LinkedList<T>& otherList);

    void insertEnd(T value);
    T removeStart();
    T retrieveAt(int index) const;

    template <class R>
    friend ostream& operator <<(ostream& os, const LinkedList<R>& theList);
};

///-----------------------------ITERATOR RELATED-----------------------

template <class T>
LinkedListIterator<T> LinkedList<T>::begin() {
    return LinkedListIterator<T>(head);
}

template <class T>
LinkedListIterator<T> LinkedList<T>::end() {
    return LinkedListIterator<T>(nullptr);
}


template <class T>
void LinkedList<T>::insertAfter(const LinkedListIterator<T>& location, const T& val) {
    //TODO: Write me
    //Need to make a new node and correctly insert it after the node that location
    // is keeping track of
}

///-----------------------------OTHER LINKED LIST FUNCTIONS-----------------------

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}


template <class T>
LinkedList<T>::~LinkedList() {
    while(head) {
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}


template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherList) {
    head = nullptr;
    tail = nullptr;

    ListNode<T>* currentInOther = otherList.head;
    while( currentInOther != nullptr ) {
        this->insertEnd(currentInOther->data);
    }
}

template <class R>
ostream& operator <<(ostream& os, const LinkedList<R>& theList) {
    os << "Size: " << theList.length << " List: ";
    ListNode<R>* current = theList.head;
    while(current != nullptr) {
        os << current->data;
        if(current->next != nullptr)
            os << ", ";
        current = current->next;
    }
    os << "\t\t(Tail points to: " << (theList.tail ? to_string(theList.tail->data) : "nullptr") << ")";
    os << endl;
    return os;
}


template <class T>
void LinkedList<T>::insertEnd(T value) {
    ListNode<T>* current = new ListNode<T>(value);
    if(head == nullptr) {
        head = current;
    } else {
        tail->next = current;
    }
    tail = current;
}

#endif
