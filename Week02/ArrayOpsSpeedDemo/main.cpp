#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

// Test adding items to end of a vector
void addNItemsToEnd(int n) {
  cout << "Adding " << n << " items to end of a vector..." << endl;

  vector<int> v;
  clock_t start = clock(); // get elapsed clock ticks since program started

  // Repeat n times
  for (int i = 0; i < n; i++) {
    v.push_back(i); // push_back is O(1) - constant
  }

  clock_t end = clock(); // get elapsed clock ticks since program started

  // Difference of end and start is elapsed clock ticks
  // Use const CLOCKS_PER_SEC to convert to seconds
  cout << fixed << "Took: " << static_cast<double>(end - start) / CLOCKS_PER_SEC
       << endl;
  cout << "---------------------" << endl;
}

// Test adding items to end of a vector
void addNItemsToStart(int n) {
  cout << "Adding " << n << " items to start of a vector..." << endl;

  vector<int> v;
  clock_t start = clock();

  // Repeat n times
  for (int i = 0; i < n; i++) {
    v.insert(v.begin(), i); // Insert at begining is O(n) - linear
  }
  clock_t end = clock();

  cout << fixed << "Took: " << static_cast<double>(end - start) / CLOCKS_PER_SEC
       << endl;
  cout << "---------------------" << endl;
}

void addOneItem(int n, int loc) {
  cout << "Adding at " << loc << " in vector of size " << n << "..." << endl;

  vector<int> v(n - 1); // start with n-1 things
  v.push_back(0);       // add one more ... now have n things

  clock_t start = clock();

  v.insert(v.begin() + loc, 1); // Insert one item at given location

  clock_t end = clock();

  cout << fixed << "Took: " << static_cast<double>(end - start) / CLOCKS_PER_SEC
       << endl;
  cout << "---------------------" << endl;
}

int main() {
  for (int size = 10000; size < 1000000000; size *= 2) {
    // You probably want to run just ONE of these tests at a time
    addOneItem(size, size); // add at end          - O(1)
    //        addOneItem(size, size / 2);         //add at middle       - O(n)
    //        addOneItem(size, 0);                //add at start        - O(n)
    //        addNItemsToEnd(size);               //add n items at end  - O(n)
    //        addNItemsToStart(size);             //add n items at start- O(n^2)
  }
}
