// Bring in unit testing code and tell it to build a main function
// If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"



// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "Queue.h"
// #include "code.cpp"     //Your code in cpplab

using namespace std;

// Add test data to list.
// Built to take existing list to avoid using copy ctor or assignment
void addTestData(Queue<char>& q) {
  for (int i = 0; i < 6; i++)
    q.enqueue(static_cast<char>('A' + i));
}

TEST_CASE("Enqueue3") {
  Queue<char> q;

  q.enqueue('A');
  q.enqueue('B');
  q.enqueue('C');

  INFO(q.toString());
  REQUIRE(q.start == 0);
  REQUIRE(q.end == 3);
  REQUIRE(q.list[q.start] == 'A');
  REQUIRE(q.list[q.end - 1] == 'C');
}

TEST_CASE("WrapEnd") {
  Queue<char> q;

  // Cheat a little...
  q.start = 3;
  q.end = 3;
  q.enqueue('C');
  q.enqueue('D');
  q.enqueue('E');

  q.enqueue('G');
  q.enqueue('H');
  INFO(q.toString());
  REQUIRE(q.end == 0);
  q.enqueue('I');
  REQUIRE(q.end == 1);

  INFO(q.toString());
  REQUIRE(q.list[0] == 'I');
}

TEST_CASE("Dequeue1") {
  Queue<char> q;

  // cheat a little
  q.list[0] = 'A';
  q.list[1] = 'B';
  q.list[2] = 'C';
  q.end = 3;

  char x = q.dequeue();

  INFO(q.toString());
  REQUIRE(q.start == 1);
  REQUIRE(q.end == 3);
  REQUIRE(x == 'A');
}

TEST_CASE("DequeueMultiple") {
  Queue<char> q;

  // cheat a little
  q.list[0] = 'A';
  q.list[1] = 'B';
  q.list[2] = 'C';
  q.end = 3;

  char x = q.dequeue();
  char y = q.dequeue();
  char z = q.dequeue();

  INFO(q.toString());
  REQUIRE(x == 'A');
  REQUIRE(y == 'B');
  REQUIRE(z == 'C');
}

TEST_CASE("WrapStart") {
  Queue<char> q;
  
  // cheat a little
  q.list[6] = 'A';
  q.list[7] = 'B';
  q.list[0] = 'C';
  q.list[1] = 'D';
  q.start = 6;
  q.end = 2;

  q.dequeue();
  q.dequeue();
  q.dequeue();
  INFO(q.toString());
  REQUIRE(q.start == 1);
  REQUIRE(q.end == 2);

  q.dequeue();
  INFO(q.toString());
  REQUIRE(q.start == 2);
  REQUIRE(q.end == 2);
}

TEST_CASE("Full") {
  Queue<char> q;
  addTestData(q); // A B C D E F

  INFO(q.toString());

  REQUIRE(q.full() == false);

  q.enqueue('G');
  REQUIRE(q.full() == true);

  q.dequeue();
  REQUIRE(q.full() == false);

  q.enqueue('H');
  REQUIRE(q.full() == true);
}

TEST_CASE("Grow") {
  Queue<char> q;
  addTestData(q); // A B C D E F
  q.grow();

  INFO(q.toString());
  REQUIRE(q.dequeue() == 'A');
  REQUIRE(q.dequeue() == 'B');
  REQUIRE(q.dequeue() == 'C');
  REQUIRE(q.dequeue() == 'D');
  REQUIRE(q.dequeue() == 'E');
  REQUIRE(q.dequeue() == 'F');
}

TEST_CASE("GrowAfterWrap") {
  Queue<char> q;
  addTestData(q); // A B C D E F
  for (int i = 0; i < 6; i++)
    q.dequeue();
  q.enqueue('G');
  q.enqueue('H');
  q.enqueue('I');
  q.enqueue('J');

  q.grow();

  INFO("After grow:" << q.toString());
  REQUIRE(q.dequeue() == 'G');
  REQUIRE(q.dequeue() == 'H');
  REQUIRE(q.dequeue() == 'I');
  REQUIRE(q.dequeue() == 'J');
}