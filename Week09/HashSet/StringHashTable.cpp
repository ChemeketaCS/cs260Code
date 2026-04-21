#include "StringHashTable.h"

#include <algorithm>
#include <cassert>
#include <stdexcept>

using namespace std;

StringHashTable::StringHashTable(int numBuckets) {
  currentSize = 0;
  tableCapacity = numBuckets;
  buckets = new string[numBuckets];

  // We can count on strings being initialized to "" which is our EMPTY_CELL
  // value If some other value was EMPTY_CELL we would need:
  //     for(int i = 0; i < tableSize; i++)
  //         buckets[i] = EMPTY_CELL;
}

StringHashTable::~StringHashTable() {
  delete[] buckets;
}

int StringHashTable::size() const {
  return currentSize;
}

string StringHashTable::toString() const {
  string result = "Buckets[ ";
  for (int i = 0; i < tableCapacity; i++) {
    if (buckets[i] == EMPTY_CELL)
      result += "_ ";
    else if (buckets[i] == PREVIOUS_USED_CELL)
      result += "# ";
    else
      result += buckets[i] + " ";
  }
  result += "]";
  return result;
}

unsigned int StringHashTable::getBucket(const std::string& key) const {
  std::hash<string> hasher;
  // std::hash returns size_t - we will store in unsigned int
  unsigned int hashValue = static_cast<unsigned int>(hasher(key));

  // return that mapped onto table
  return hashValue % tableCapacity;
}

bool StringHashTable::contains(const std::string& key) const {
  if (key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
    throw invalid_argument("Invalid key");

  int bucketNumber = getBucket(key);

  // TODO - Fix me

  return false;
}

void StringHashTable::insert(const std::string& key) {
  if (key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
    throw invalid_argument("Invalid key");

  // grow if needed
  if (currentSize > MAX_LOAD * tableCapacity)
    grow();

  // TODO - Fix me
  // Find first available location after getBucket(key)
  //   Insert item and update size
}

void StringHashTable::remove(const std::string& key) {
  if (key == EMPTY_CELL || key == PREVIOUS_USED_CELL)
    throw invalid_argument("Invalid value");

  // TODO - Fix me
  // Attempt to find item
  //   If found, replace with tombstone and update size
}

void StringHashTable::grow() {
  // TODO - Fix me
  // Allocate new storage that is oldCapacity * 2 in size
  // Rehash all non-empty/tombstone value from old array back into table
}
