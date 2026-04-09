#include <iostream>

struct ListNode {
  // Value stored in this node
  int data = 0;

  // Next node in list (nullptr == end of list)
  ListNode* next = nullptr;

  // Constructor
  ListNode(int value) {
    data = value;
  }
};

using namespace std;

int main() {
  ListNode* node1 = new ListNode(12);
  ListNode* node2 = new ListNode(6);
  ListNode* node3 = new ListNode(10);

  node1->next = node2;
  node2->next = node3;

  cout << node1->data << endl;
  cout << node1->next->data << endl;
  cout << node1->next->next->data << endl;

  ListNode* current = node1;
  while (current != nullptr) {
    cout << current->data << endl;
    current = current->next;
  }

  // Clean up all the nodes
  delete node3;
  delete node2;
  delete node1;
}
