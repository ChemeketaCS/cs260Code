#ifndef IMPROVEDSTACK_H
#define IMPROVEDSTACK_H

#include <vector>

template<typename T>
class VectorStack
{
private:
    std::vector<T> store;

public:
    T peek() const;
    void push(const T& value);
    T pop();
    int getSize() const;
    bool empty() const;
};

template<typename T>
bool VectorStack<T>::empty() const
{
    return store.empty();
}

template<typename T>
T VectorStack<T>::peek() const
{
    return store[store.size - 1];
}

template<typename T>
T VectorStack<T>::pop()
{
    T temp = store[store.size - 1];
    store.pop_back();
    return temp;
}

template<typename T>
void VectorStack<T>::push(const T& value)
{
    store.push_back(value);
}

template<typename T>
int VectorStack<T>::getSize() const
{
    return store.size();
}

#endif
