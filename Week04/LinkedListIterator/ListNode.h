#ifndef LISTNODE_H
#define LISTNODE_H

template <class T>
struct ListNode
{
    T data;
    ListNode* next;

    ListNode(T value) {
        data = value;
        next = nullptr;
    }
};

#endif // LISTNODE_H
