#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

// Add test data to list.
// Built to take existing list to avoid using copy ctor or assignment
void buildTestIntList(SimpleLinkedList<int>& list) {
  list.insertStart(3);
  list.insertStart(2);
  list.insertStart(1);
}


int main() {
  SimpleLinkedList<int> list;

  buildTestIntList(list);
  cout << "List contents: ";
  list.print();

  int value = list.retrieveAt(1);
  cout << "Value at index 1 is " << value << endl;

  cout << "Removing item at index 2" << endl;
  list.removeAt(1);
  cout << "List contents: ";
  list.print();
}