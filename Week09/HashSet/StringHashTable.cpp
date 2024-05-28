#include "StringHashTable.h"

#include <cassert>
#include <algorithm>
#include <stdexcept>

using namespace std;

StringHashTable::StringHashTable(int numBuckets)
{
    currentSize = 0;
    tableCapacity = numBuckets;
    buckets = new string[numBuckets];

    //We can count on strings bein initialized to "" which is our EMPTY_CELL value
    //If some other value was EMPTY_CELL we would need:
    //    for(int i = 0; i < tableSize; i++)
    //        buckets[i] = EMPTY_CELL;
}

StringHashTable::~StringHashTable()
{
    delete [] buckets;
}


ostream& operator<<(ostream& os, const StringHashTable& theSet)
{
    os << "Buckets[ ";
    for(int i = 0; i < theSet.tableCapacity; i++) {
        if(theSet.buckets[i] == theSet.EMPTY_CELL)
            cout << "_ ";
        else if(theSet.buckets[i] == theSet.PREVIOUS_USED_CELL)
            cout << "# ";
        else
            cout << theSet.buckets[i] << " ";
    }
    os << "]";
    return os;
}

int StringHashTable::size() const {
    return currentSize;
}



unsigned int StringHashTable::getBucket(const std::string& key) const {
    std::hash<string> hasher;
    //std::hash returns size_t - we will store in unsigned int
    unsigned int hashValue = static_cast<unsigned int>(hasher(key));

    //return that mapped onto table
    return hashValue % tableCapacity;
}



bool StringHashTable::contains(const std::string& key) const {
    if(key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
        throw invalid_argument("Invalid key");

    int bucketNumber = getBucket(key);

    //TODO - Fix me
    //Search starting at bucketNumber until find item or empty

    return false;
}

void StringHashTable::insert(const std::string& key) {
    if(key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
        throw invalid_argument("Invalid key");

    //grow if needed
    if(currentSize > MAX_LOAD * tableCapacity)
        grow();

    //TODO - Fix me
    //Find first available location after getBucket(key)
    //  Insert item and update size
}

void StringHashTable::remove(const std::string& key) {
    if(key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
        throw invalid_argument("Invalid value");

    //TODO - Fix me
    //Attempt to find item
    //  If found, replace with tombstone and update size
}

void StringHashTable::grow() {
    //TODO - Fix me
    //Allocate new storage that is oldCapacity * 2 + 1 in size
    //Rehash all non-empty/tombstone value from old array back into table
}
