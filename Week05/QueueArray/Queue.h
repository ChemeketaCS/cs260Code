#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <exception>
#include <stdexcept>

using namespace std;

const int QUEUE_INIT_SIZE = 8;

template <class T>
class Queue {
//Normally would be private, public to enable intrusive unit tests
public:
    T *list;            //array to hold the list elements
    int arraySize;      //capacity of array used for storage

    int start;          //index of the front of the queue
    int end;            //index of next available location at back

    //Helper function to add additional space
    void grow();

public:
    void enqueue(const T& value);
    T dequeue();
    bool empty() const;
    bool full() const;

    Queue();
    ~Queue();

    //Disable copy ctor and assignment to avoid accidental use
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);

    string toString();
};


template <class T>
string Queue<T>::toString() {
    stringstream s;
    s << "Start: " << start << " End: " << end << " arraySize: " << arraySize << endl;

    int length = end - start;
    bool wrapped = false;       //does queue wrap wround back of array?
    if(length < 0)
        wrapped = true;

    for(int i = 0; i < arraySize; i++) {
        if( (wrapped && (i < end || i >= start)) ||
            (!wrapped && (i < end && i >= start)) )
            s << setw(4) << list[i];
        else
            s << setw(4) << "_";
    }
    return s.str();
}


template <class T>
Queue<T>::Queue() {
    arraySize = QUEUE_INIT_SIZE;
    start = 0;
    end = 0;
    list = new T[arraySize];
}

template <class T>
Queue<T>::~Queue() {
    delete [] list;
}

//-----------Functions to be built------------------

template <class T>
void Queue<T>::enqueue(const T& value) {
    if( full() ) {
        grow();
    }

    ///TODO - fixme
}

template <class T>
T Queue<T>::dequeue() {
    if( empty() ) {
        throw out_of_range("Dequeue on empty queue");
    }

    ///TODO - fixme
}

template <class T>
bool Queue<T>::empty() const {
    if(end == start)
        return true;
    else
        return false;
}

template <class T>
bool Queue<T>::full() const {
    ///TODO - fix this return true or false based on logic
    return false;  //replace me
}

template <class T>
void Queue<T>::grow() {
    ///TODO - allocate new storage, copy over values, update variables, clean up old storage
    throw logic_error("Not implemented");
}



#endif // QUEUE_H

