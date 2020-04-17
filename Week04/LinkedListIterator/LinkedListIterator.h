#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H

#include "ListNode.h"

//Forward declare LinkedList so we can make it a friend
template <class T>
class LinkedList;

template<class T>
class LinkedListIterator
{
    //Give LinkedList access to private information
    friend class LinkedList<T>;

private:
    ListNode<T>* currentNode;

public:
    //Constructor - takes pointer to ListNode
    LinkedListIterator(ListNode<T>* const location)
    {
        currentNode = location;
    }

    //Compare two iterators with ==
    bool operator==(const LinkedListIterator& other) const
    {
        return currentNode == other.currentNode;
    }

    //Compare two iterators with !=
    bool operator!=(const LinkedListIterator& other) const
    {
        return currentNode != other.currentNode;
    }

    //Return data from the current node
    // return reference to allow modification
    T& operator*();

    //Advance iterator position by one
    void operator++();
};



//Return data from the current node
// return reference to allow modification
template<class T>
T& LinkedListIterator<T>::operator*()
{
    ///TODO - return data from current node
}

//Advance iterator position by one
template<class T>
void LinkedListIterator<T>::operator++()
{
    ///TODO - advance the iterator to point at next node in list

    //Note: Operator ++ can also be implemented to return the current object by reference
    //      for use in a more complex expression. To do, return type would be "LinkedListIterator<T>&"
    //      and last line would be "return *this;"
}

#endif // LINKEDLISTITERATOR_H
