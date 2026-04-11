// Bring in unit testing code and tell it to build a main function
// If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "SimpleLinkedList.h"

using namespace std;

// Add test data to list.
// Built to take existing list to avoid using copy ctor or assignment
void buildTestIntList(SimpleLinkedList<int>& list) {
  list.insertStart(3);
  list.insertStart(2);
  list.insertStart(1);
}

TEST_CASE("LL/removeStart") {
  SimpleLinkedList<int> test_list;
  buildTestIntList(test_list); // 1, 2, 3

  int startNodeCount = ListNode<int>::nodeCount;

  test_list.removeStart();
  REQUIRE(startNodeCount - ListNode<int>::nodeCount == 1);

  test_list.removeStart();
  REQUIRE(test_list.retrieveAt(0) == 3);
  REQUIRE(startNodeCount - ListNode<int>::nodeCount == 2);

  test_list.removeStart();
  REQUIRE(test_list.head == nullptr);
  REQUIRE(startNodeCount - ListNode<int>::nodeCount == 3);
}

TEST_CASE("LL/InsertAt") {
  SimpleLinkedList<int> test_list;
  buildTestIntList(test_list); // 1, 2, 3

  test_list.insertAt(2, 10);
  REQUIRE(test_list.retrieveAt(2) == 10);
  REQUIRE(test_list.retrieveAt(3) == 3);

  test_list.insertAt(1, 20);
  REQUIRE(test_list.retrieveAt(1) == 20);
  REQUIRE(test_list.retrieveAt(2) == 2);
  REQUIRE(test_list.retrieveAt(3) == 10);
}

TEST_CASE("LL/InsertAtSpecialCases") {
  SimpleLinkedList<int> test_list;
  buildTestIntList(test_list); // 1, 2, 3

  // Inserting at the start with insertAt
  test_list.insertAt(0, 10);
  REQUIRE(test_list.retrieveAt(0) == 10);
  REQUIRE(test_list.retrieveAt(1) == 1);

  // Inserting at the end with insertAt
  test_list.insertAt(4, 20);
  REQUIRE(test_list.retrieveAt(3) == 3);
  REQUIRE(test_list.retrieveAt(4) == 20);
  // Make sure tail was updated
}
