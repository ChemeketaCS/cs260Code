#ifndef SIMPLELINKEDLIST_H
#define SIMPLELINKEDLIST_H

#include <string>

struct ListNode {
    ListNode(int value);
    ~ListNode();

    ListNode* next = nullptr;
    int data = 0;

    //Maintain a count of active nodes for testing
    // Not normally a part of the struct.
    // You should NOT modify or even use this value in your code.
    static int nodeCount;
};


class SimpleLinkedList
{
public:
    //Provided:
    void insertStart(int value);
    void removeLast();
    int retrieveAt(int index);
    int getTotal();
    std::string toString();

    //To implement:
    std::string reverseToString();
    int getMaxValue();
    ~SimpleLinkedList();

private:
    ListNode* head = nullptr;
};

#endif // SIMPLELINKEDLIST_H
