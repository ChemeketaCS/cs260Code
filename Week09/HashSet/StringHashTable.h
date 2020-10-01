#ifndef HASHSET_H
#define HASHSET_H

#include <string>
#include <iostream>

class StringHashTable {
//Normally private, made public to allow intrusive unit tests
public:
    int tableCapacity;              //size of buckets array
    int currentSize;                //items in set
    std::string* buckets;
    const double MAX_LOAD = 0.7;

    //value used to indicate a cell is empty - cannot be stored in set
    const std::string EMPTY_CELL = "";
    //value used to indicate a cell is empty but once had a value
    const std::string PREVIOUS_USED_CELL = "#";

    //reallocate new storage array
    void grow();

    //Determine bucket given items should be in
    unsigned int getBucket(const std::string& key) const;

public:
    StringHashTable(int numBuckets = 8);

    bool contains(const std::string& key) const;
    void insert(const std::string& key);
    void remove(const std::string& key);
    int size() const;

    //Memory management
    virtual ~StringHashTable();
    //Copy ctor and assignment operator declared but not defined to prevent default versions
    StringHashTable(const StringHashTable& other);
    StringHashTable& operator=(const StringHashTable& other);

    //Printing
    friend std::ostream& operator<<(std::ostream& os, const StringHashTable& theSet);
};

#endif // HASHSET_H
