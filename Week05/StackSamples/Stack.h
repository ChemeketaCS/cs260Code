#ifndef IMPROVEDSTACK_H
#define IMPROVEDSTACK_H

template<typename T>
class Stack
{
private:
    T* elements;
    int size;
    int capacity;
    void ensureCapacity();

public:
    Stack();

    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    bool empty() const;
    T peek() const;
    void push(const T& value);
    T pop();
    int getSize() const;
};

template<typename T>
Stack<T>::Stack(): size(0), capacity(16)
{
    elements = new T[capacity];
}

template<typename T>
Stack<T>::Stack(const Stack& other)
{
    elements = new T[other.capacity];
    size = other.size;
    capacity = other.capacity;
    for (int i = 0; i < size; i++)
    {
        elements[i] = other.elements[i];
    }
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
    if(this == &other)
        return *this;

    elements = new T[other.capacity];
    size = other.size;
    capacity = other.capacity;
    for (int i = 0; i < size; i++)
    {
        elements[i] = other.elements[i];
    }
    return *this;
}

template<typename T>
Stack<T>::~Stack()
{
    delete [] elements;
}

template<typename T>
bool Stack<T>::empty() const
{
    return size == 0;
}

template<typename T>
T Stack<T>::peek() const
{
    return elements[size - 1];
}

template<typename T>
void Stack<T>::push(const T& value)
{
    ensureCapacity();
    elements[size++] = value;
}

template<typename T>
void Stack<T>::ensureCapacity()
{
    if (size == capacity)
    {
        T* old = elements;
        capacity = 2 * size;
        elements = new T[size * 2];

        for (int i = 0; i < size; i++)
            elements[i] = old[i];

        delete [] old;
    }
}

template<typename T>
T Stack<T>::pop()
{
    return elements[--size];
}

template<typename T>
int Stack<T>::getSize() const
{
    return size;
}

#endif
