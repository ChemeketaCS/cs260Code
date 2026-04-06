#include <algorithm>
#include <iostream>
#include <numeric>

#include "LinkedList.h"
#include "LinkedListIterator.h"

using namespace std;

bool isOdd(int x) {
    return x % 2 == 1;
}

int main() {
    LinkedList<int> myList;
    myList.insertFront(10);
    myList.insertFront(20);
    myList.insertFront(15);
    myList.insertFront(6);

    // A range based loop will implicitly use our iterator
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl;

    // Use std::accumulate to add all the values
    cout << "Sum is: " << std::accumulate(myList.begin(), myList.end(), 0)
         << endl;

    // Use std::replace_if to modify the list
    cout << "Replacing all odd values with 0" << endl;
    std::replace_if(myList.begin(), myList.end(), isOdd, 0);
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl;
}
