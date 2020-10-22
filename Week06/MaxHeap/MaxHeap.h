#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <utility>

template<typename T>
class MaxHeap
{
//Would normally be private - public to allow intrusive unit tests
public:
    T* data;        //array containing the heap
    int capacity;   //maximum size
    int heapSize;   //current logical size

    //Double the size of the underlying array
    void grow();

    //Gets the index of the largest child of the specified location
    // Returns -1 if there are no children
    int largestChildIndex(int current) const;

public:
    //Get a copy of the top item
    T getMax();

    //Rmove the top item and return it
    T removeMax();

    //Add the given value to the heap
    void add(const T& value);

    //Construct a max heap with initial space for 32 items
    MaxHeap();

    //Destroy the max heap and release memory
    ~MaxHeap();


    //Copy ctor declared, not implemented unless needed
    MaxHeap(const MaxHeap& other);
    MaxHeap& operator=(const MaxHeap& other);

    //Convert to a string representation
    std::string toString() const;
};


template<typename T>
MaxHeap<T>::MaxHeap()
{
    heapSize = 0;
    capacity = 32;
    data = new T[capacity];
}

template<typename T>
MaxHeap<T>::~MaxHeap()
{
    delete [] data;
}

template<typename T>
void MaxHeap<T>::grow() {
    T* temp = data;
    capacity *= 2;
    data = new T[capacity * 2];
    for(int i = 0; i < heapSize; i++)
        data[i] = temp[i];

    delete [] temp;
}



template<typename T>
std::string MaxHeap<T>::toString() const {
    std::stringstream out;
    out << "[";
    for(int i = 0; i < heapSize - 1; ++i) {
        out << " " << data[i];
    }
    out << "]";
    return out.str();
}

template<typename T>
T MaxHeap<T>::getMax() {
    if(heapSize == 0)
        throw std::logic_error("getMax in empty heap");

    return data[0];
}


template<typename T>
int MaxHeap<T>::largestChildIndex(int current) const {
    ///TODO
    /// If there are no valid children, return -1
    /// If only a left child, return its index
    /// Otherwise, return index of the larger of the two children
    return -1; //remove this
}

template<typename T>
T MaxHeap<T>::removeMax() {
    if(heapSize == 0)
        throw std::logic_error("removeTop in empty heap");

    ///TODO
    /// Swap first and last elements and reduce size
    /// Until the promoted value is in valid location, swap it with largest child
    /// Return old first element
    
}


template<typename T>
void MaxHeap<T>::add(const T& value) {
    if(heapSize == capacity)
        grow();

    ///TODO - add to bottom of heap
    /// then swap our way up until current location is root
    /// and increase logical size of heap
}


#endif // MAXHEAP_H
