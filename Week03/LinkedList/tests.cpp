//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//Hide some false warnings - this is supposed to look commented out
// clazy:skip

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "LinkedList.h"
//#include "code.cpp"     //Your code in cpplab

using namespace std;

//Add test data to list.
//Built to take existing list to avoid using copy ctor or assignment
void buildTestIntList(LinkedList<int>& list) {
    list.insertStart(3);
    list.insertStart(2);
    list.insertStart(1);
}

TEST_CASE( "LL/InsertEnd" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //1, 2, 3

    test_list.insertEnd(10);
    REQUIRE( test_list.length == 4 );
    REQUIRE( test_list.retrieveAt(3) == 10 );
    REQUIRE( test_list.tail->data == 10 );       //check tail pointer
    REQUIRE( test_list.tail->next == nullptr ); //check after tail

    test_list.insertEnd(20);
    REQUIRE( test_list.length == 5 );
    REQUIRE( test_list.retrieveAt(4) == 20 );
    REQUIRE( test_list.tail->data == 20 );       //check tail pointer
    REQUIRE( test_list.tail->next == nullptr ); //check after tail
}

TEST_CASE( "LL/InsertEndEmptyList" ) {
    LinkedList<int> test_list;

    test_list.insertEnd(10);
    REQUIRE( test_list.head != nullptr );       //check head pointer
    REQUIRE( test_list.length == 1 );
    REQUIRE( test_list.retrieveAt(0) == 10 );
    REQUIRE( test_list.head->data == 10 );       //check head pointer
    REQUIRE( test_list.tail->data == 10 );       //check tail pointer
    REQUIRE( test_list.tail->next == nullptr ); //check after tail
}


TEST_CASE( "LL/RemoveFirst" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //1, 2, 3

    int startNodeCount = ListNode<int>::nodeCount;

    test_list.removeFirst();
    REQUIRE( test_list.length == 2 );
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 1 );

    test_list.removeFirst();
    REQUIRE( test_list.length == 1 );
    REQUIRE( test_list.retrieveAt(0) == 3 );
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 2 );

    test_list.removeFirst();
    REQUIRE( test_list.length == 0 );
    REQUIRE( test_list.head == nullptr );
    REQUIRE( test_list.tail == nullptr );
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 3 );
}


TEST_CASE( "LL/InsertAt" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //1, 2, 3

    test_list.insertAt(2, 10);
    REQUIRE( test_list.length == 4 );
    REQUIRE( test_list.retrieveAt(2) == 10 );
    REQUIRE( test_list.retrieveAt(3) == 3 );

    test_list.insertAt(1, 20);
    REQUIRE( test_list.length == 5 );
    REQUIRE( test_list.retrieveAt(1) == 20 );
    REQUIRE( test_list.retrieveAt(2) == 2 );
    REQUIRE( test_list.retrieveAt(3) == 10 );
}


TEST_CASE( "LL/InsertAtSpecialCases" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //1, 2, 3

    //Inserting at the start with insertAt
    test_list.insertAt(0, 10);
    REQUIRE( test_list.length == 4 );
    REQUIRE( test_list.retrieveAt(0) == 10 );
    REQUIRE( test_list.retrieveAt(1) == 1 );

    //Inserting at the end with insertAt
    test_list.insertAt(4, 20);
    REQUIRE( test_list.length == 5 );
    REQUIRE( test_list.retrieveAt(3) == 3 );
    REQUIRE( test_list.retrieveAt(4) == 20 );
    //Make sure tail was updated
    REQUIRE( test_list.tail->data == 20 );
}

TEST_CASE( "LL/Clear" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //1, 2, 3

    int startNodeCount = ListNode<int>::nodeCount;

    test_list.clear();

    REQUIRE( test_list.head == nullptr );
    REQUIRE( test_list.tail == nullptr );
    REQUIRE( test_list.length == 0 );
    //Were they actually deleted???
    REQUIRE( startNodeCount - ListNode<int>::nodeCount == 3 );
}


TEST_CASE( "LL/CopyConstructor" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);  //1, 2, 3

    int startNodeCount = ListNode<int>::nodeCount;

    LinkedList<int> copy(test_list);

    REQUIRE( copy.retrieveAt(0) == 1 );
    REQUIRE( copy.retrieveAt(1) == 2 );
    REQUIRE( copy.retrieveAt(2) == 3 );
    REQUIRE( copy.length == 3 );
    REQUIRE( ListNode<int>::nodeCount - startNodeCount == 3 );

    //Make sure removal from one does not affect other
    test_list.removeAt(1);
    REQUIRE( copy.retrieveAt(0) == 1 );
    REQUIRE( copy.retrieveAt(1) == 2 );
    REQUIRE( copy.retrieveAt(2) == 3 );
    REQUIRE( copy.length == 3 );
}


TEST_CASE( "LL/AssignmentOperator" ) {
    LinkedList<int> test_list;
    buildTestIntList(test_list);    //1, 2, 3

    LinkedList<int> test_list2;
    test_list2.insertStart(10);
    test_list2.insertStart(20);     //10 20

    int startNodeCount = ListNode<int>::nodeCount;

    test_list2 = test_list;         //Overwrite existing test_list2

    REQUIRE( test_list2.retrieveAt(0) == 1 );
    REQUIRE( test_list2.retrieveAt(1) == 2 );
    REQUIRE( test_list2.retrieveAt(2) == 3 );
    REQUIRE( test_list2.length == 3 );
    REQUIRE( ListNode<int>::nodeCount - startNodeCount == 1 ); //created 3, deleted 2

    //Make sure removal from one does not affect other
    test_list.removeAt(1);
    REQUIRE( test_list2.retrieveAt(0) == 1 );
    REQUIRE( test_list2.retrieveAt(1) == 2 );
    REQUIRE( test_list2.retrieveAt(2) == 3 );
    REQUIRE( test_list2.length == 3 );
}
