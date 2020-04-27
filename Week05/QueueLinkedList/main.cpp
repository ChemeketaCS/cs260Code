#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Queue.h"

using namespace std;


char getChar() {
    static char nextChar = 'A' - 1;

    ++nextChar;
    if(nextChar > 'Z')
        nextChar = 'A';

    return nextChar;
}

int main() {
    Queue<char> q1;


////-----------------------TEST ENQUEUE---------------------------------
    cout << "Placing 6 items on queue..." << endl;
    for(int i = 0; i < 6; i++)
        q1.enqueue( getChar() );

    cout << q1;

////-----------------------TEST DEQUEUE---------------------------------
    cout << endl << "Removing 5 things..." << endl;
    for(int i = 0; i < 5; i++)
        cout << q1.dequeue() << endl;
    cout << q1;

    cout << endl << "Placing 4 things on queue..." << endl;
    for(int i = 0; i < 4; i++)
        q1.enqueue( getChar() );
    cout << q1;

    cout << endl << "Removing 4 things..." << endl;
    for(int i = 0; i < 4; i++)
        cout << q1.dequeue() << endl;
    cout << q1;

    cout << endl << "Adding one last thing..." << endl;
        q1.enqueue( getChar() );
    cout << q1;

    return 0;
}
