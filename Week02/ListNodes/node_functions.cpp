#include <iostream>

#include "Node.h"

using namespace std;


Node<int>* buildList() {
    Node<int>* start = new Node<int>(10);

    //TODO - Make a chain of nodes containing 10, 20, 30, 40
    //       that begins at start

    return start;
}

int getSecondValue(Node<int>* head) {
    //TODO - Return value contained in the second node
    //       in the chain starting at head
    return 0; //fixme
}

int countNodes(Node<int>* head) {
    //TODO - Return the number of nodes
    //       in the chain starting at head
    return 0; //fixme
}

void removeSecondValue(Node<int>* head) {
    //TODO - Remove the node after head
    //       head should end up pointing to what was the 3rd value
    //       removed node should be deleted
}

//Deletes an entire list of nodes
void deleteList(Node<int>* head) {
    while(head != nullptr) {
        Node<int>* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

//Prints an entire list
void printList(Node<int>* head) {
    Node<int>* temp = head;
    while(temp != nullptr) {
        cout << temp->element << " ";
        temp = temp->next;
    }
    cout << endl;
}
