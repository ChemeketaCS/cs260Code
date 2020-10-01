#include <iostream>
#include <algorithm>
#include <numeric>

#include "ArrayList.h"
#include "ArrayListIterator.h"

using namespace std;

template <class T>
void print(const T& value) {
    cout << value << " ";
}

bool isOdd(int x) {
    return x % 2 == 0;
}

int main()
{
    ArrayList<int> myList;
    for(int i = 1; i <= 20; i++)
        myList.insertEnd(i);

    cout << "Iterator based loop:" << endl;
    for( ArrayListIterator<int> it = myList.begin();
         it != myList.end();
         ++it )
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "ArrayList printed with std::for_each:" << endl;
    std::for_each(myList.begin(), myList.end(), print<int>);
    cout << endl;

    cout << "---------Use some other std::algorithms with ArrayListIterator---------" << endl;
    cout << "Max value: " << *std::max_element(myList.begin(), myList.end()) << endl;
    cout << "Sum is: " << std::accumulate(myList.begin(), myList.end(), 0) << endl;

    cout << "Replacing all odd values with 0" << endl;
    std::replace_if(myList.begin(), myList.end(), isOdd, 0);
    std::for_each(myList.begin(), myList.end(), print<int>);
    cout << endl;

}
