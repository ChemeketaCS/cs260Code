#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H

#include "ListNode.h"

template <typename T>
class ListIterator {
private:
    ListNode<T>* currentNode;
public:
    // Constructor to initialize the iterator that starts at a given node
    ListIterator(ListNode<T>* startNode) {
        currentNode = startNode;
    }

    // Returns a reference to the element at the current position
    T& operator*() {
        return currentNode->element;
    }

    // Advances the iterator to the next position
    ListIterator& operator++() {
        currentNode = currentNode->next;
        return *this;
    }

    // Compare two iterators for equality/inequality
    bool operator==(const ListIterator& other) const {
        return currentNode == other.currentNode;
    }

    bool operator!=(const ListIterator& other) const {
        return currentNode != other.currentNode;
    }
};

#endif // LINKEDLISTITERATOR_H
