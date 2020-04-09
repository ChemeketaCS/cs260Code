#include <iostream>
#include <stdexcept>

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

using namespace std;

///-----------------------------LIST NODE---------------------------------
template <class T>
struct ListNode
{
	T data;
	ListNode<T>* next;
	ListNode<T>* prev;


    //Maintain a count of active nodes for testing
    // Not normally a part of the struct.
    // You should NOT modify or even use this value in your code.
    static int nodeCount;

	ListNode() {
	    next = nullptr;
        prev = nullptr;
        //Call default constructor for type T
        //  produces 0 for primitive types
	    data = T();
        nodeCount++;
	}

	ListNode(T value) {
	    next = nullptr;
	    prev = nullptr;
	    data = value;
        nodeCount++;
	}

    ~ListNode() {
        nodeCount--;
    }
};


template <class T>
int ListNode<T>::nodeCount = 0;


///-----------------------------LINKED LIST---------------------------------

template <class T>
class DoublyLinkedList
{
    //These would normally be private. They are public to enable simpler unit tests.
public:
    ListNode<T>* head;
    ListNode<T>* tail;
    int length;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    ///Assignment Operator and Copy Ctor not implemented - declared to prevent
    /// use of default versions
    DoublyLinkedList(const DoublyLinkedList& other);
    DoublyLinkedList& operator=(const DoublyLinkedList& other);

    int listSize() const;

    void insertStart(const T& value);

    void insertAt(int index, const T& value);
    void removeAt(int index);
    T retrieveAt(int index) const;

    template <class R>
    friend ostream& operator <<(ostream& os, const DoublyLinkedList<R>& theList);
};

///-----------------------------LINKED LIST FUNCTIONS-----------------------
template <class R>
ostream& operator <<(ostream& os, const DoublyLinkedList<R>& theList) {
    cout << "List: ";
    ListNode<R>* current = theList.head->next;
    while(current != theList.tail) {
        cout << current->data;
        if(current->next != theList.tail)
            cout << ", ";
        current = current->next;
    }
    cout << endl;
    return os;
}


template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    //Delete all nodes, including dummies
    while(head != nullptr) {
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
int DoublyLinkedList<T>::listSize() const {
    return length;
}


template <class T>
void DoublyLinkedList<T>::insertStart(const T& value) {
    ListNode<T>* newNode = new ListNode<T>(value);
    newNode->prev = head;
    newNode->next = head->next;

    newNode->next->prev = newNode;
    head->next = newNode;

    length++;
}

template <class T>
T DoublyLinkedList<T>::retrieveAt(int index) const {
    if(index >= length || index < 0)
        throw out_of_range("Bad index in retrieveAt");

    //Start at node after dummy
    ListNode<T>* current = head->next;
    //Advance index times
    for(int i = 0; i < index; i++)
        current = current->next;

    return current->data;
}


///-----------------------------TODO-----------------------
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    //TODO - make dummy nodes, attach to each other
    ListNode<T>* sampleDummy = new ListNode<T>();

}


template <class T>
void DoublyLinkedList<T>::insertAt(int index, const T& value) {
    if(index > length || index < 0)
        throw out_of_range("Bad index in insertAt");
    //TODO - implement

}

template <class T>
void DoublyLinkedList<T>::removeAt(int index) {
    if(index >= length || index < 0)
        throw out_of_range("Bad index in removeAt");
    //TODO - implement

}


#endif // DOUBLYLINKEDLIST_H
