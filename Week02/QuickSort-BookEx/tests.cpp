#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

// Bring in unit testing code and tell it to build a main function
// If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

// Debugging helper (implementation below)
template<typename T>
string vectorToString(const vector<T>& vec, size_t start = 0, size_t end = -1);

int descendingPartition(vector<int>& vec, int start, int end) {
  // Todo: fixme
}

void descendingQuickSort(vector<int>& vec, int start, int end) {
  // Todo: fixme
}

TEST_CASE("descendingPartition") {
  {
    vector<int> test1 = {4, 7, 3, 9, 1, 6, 2, 8, 5};
    int pivotLoc = descendingPartition(test1, 0, 8);
    CHECK(pivotLoc == 5);
    for (int i = 0; i < pivotLoc; ++i) {
      CHECK(test1.at(i) >= test1.at(pivotLoc));
    }
    for (int i = pivotLoc + 1; i <= 8; ++i) {
      CHECK(test1.at(i) <= test1.at(pivotLoc));
    }
  }
  {
    vector<int> test2 = {8, 6, 7, 5, 3, 9, 2, 1, 4};
    int pivotLoc = descendingPartition(test2, 0, 8);
    CHECK(pivotLoc == 1);

    for (int i = 0; i < pivotLoc; ++i) {
      CHECK(test2.at(i) >= test2.at(pivotLoc));
    }
    for (int i = pivotLoc + 1; i <= 8; ++i) {
      CHECK(test2.at(i) <= test2.at(pivotLoc));
    }
  }
}

TEST_CASE("descendingPartitionPartial") {
  vector<int> test = {0, 0, 4, 7, 3, 9, 1, 6, 2, 8, 5, 0, 0};
  int pivotLoc = descendingPartition(test, 2, 10);
  CHECK(pivotLoc == 7);
  for (int i = 2; i < pivotLoc; ++i) {
    CHECK(test.at(i) >= test.at(pivotLoc));
  }
  for (int i = pivotLoc + 1; i <= 10; ++i) {
    CHECK(test.at(i) <= test.at(pivotLoc));
  }
}

TEST_CASE("descendingQuickSort") {
  vector<int> test = {1, 3, 2, 5, 4, 8, 7, 6};
  vector<int> temp(test.size());

  descendingQuickSort(test, 0, 7);
  string debug1 = "After sort: " + vectorToString(test);
  vector<int> expected1 = {8, 7, 6, 5, 4, 3, 2, 1};
  INFO(debug1);
  INFO("Expected: ", vectorToString(expected1));
  CHECK(test == expected1);
}

TEST_CASE("descendingQuickSortPartial") {
  vector<int> test = {0, 0, 7, 5, 4, 3, 2, 1, 8, 6, 0, 0};
  vector<int> temp(test.size());

  descendingQuickSort(test, 2, 9);
  string debug1 = "After sort: " + vectorToString(test);
  vector<int> expected1 = {0, 0, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0};
  INFO(debug1);
  INFO("Expected: ", vectorToString(expected1));
  CHECK(test == expected1);
}

// Converts the vector to a string representation
// if start and end are provided, only that range is displayed,
//   values outside that range are replaced with '_'
template<typename T>
std::string vectorToString(const std::vector<T>& vec, size_t start,
                           size_t end) {
  if (vec.empty()) {
    return "[]";
  }
  if (static_cast<int>(end) == -1) {
    end = vec.size() - 1;
  }
  std::string result = "[";
  for (size_t i = 0; i < vec.size(); ++i) {
    if (i >= start && i <= end) {
      result += std::to_string(vec[i]);
    } else {
      result += "_";
    }
    if (i < vec.size() - 1)
      result += ", ";
  }
  result += "]";
  return result;
}