#ifndef ARRAYLISTITERATOR_H
#define ARRAYLISTITERATOR_H

template <class T>
class ArrayListIterator {
private:
    T* currentLoc;

public:
    //Constructor - takes pointer to location
    ArrayListIterator(T* const location) {
        currentLoc = location;
    }

    //Compare two iterators with ==
    bool operator==(const ArrayListIterator& other) const {
        return currentLoc == other.currentLoc;
    }

    //Compare two iterators with !=
    bool operator!=(const ArrayListIterator& other) const {
        return currentLoc != other.currentLoc;
    }

    //Dereference iterator to retrieve current value
    // return reference to allow modification
    T& operator*() {
        return *currentLoc;
    }

    //Preincrement: Advance iterator one position
    ArrayListIterator<T> operator++() {
        ++currentLoc;         //++ the pointer moves it forward size of one T
        return *this;
    }
};

#endif // ARRAYLISTITERATOR_H
