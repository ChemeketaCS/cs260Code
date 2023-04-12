#include <iostream>

template<typename T>
class Node {
public:
    //Value stored in this node
    T element;
    //Next node in list (nullptr == end of list)
    Node* next = nullptr;

    //Node must be constructed with a value - stored as element
    Node(T value) : element(value) {}
};

using namespace std;

int main()
{
    Node<int>* node1 = new Node<int>(10);
    Node<int>* node2 = new Node<int>(15);
    Node<int>* node3 = new Node<int>(20);

    node1->next = node2;
    node2->next = node3;

    cout << node1->element << endl;
    cout << node1->next->element << endl;
    cout << node1->next->next->element << endl;

    //Clean up all the nodes
    delete node3;
    delete node2;
    delete node1;
}
