//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//Hide some false warnings - this is supposed to look commented out
// clazy:skip

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "CharBST.h"

using namespace std;


/* Adds test data to produce this tree:
 *         _G_
 *        /   \
 *       C     P
 *        \   / \
 *         F J   Y
 */

void insertTestData(CharBST& c) {
    c.root = nullptr;   //remove (and leak!!!) any existing nodes

    c.root = new BSTNode<char>('G');
    c.root->left = new BSTNode<char>('C');
    c.root->left->right = new BSTNode<char>('F');
    c.root->right = new BSTNode<char>('P');
    c.root->right->right = new BSTNode<char>('Y');
    c.root->right->left = new BSTNode<char>('J');
}


TEST_CASE( "ContainsIterative" ) {
    CharBST bst;
    insertTestData(bst);

    REQUIRE( bst.containsIterative('G') );
    REQUIRE( bst.containsIterative('C') );
    REQUIRE( bst.containsIterative('F') );
    REQUIRE( bst.containsIterative('P') );
    REQUIRE( bst.containsIterative('Y') );
    REQUIRE( bst.containsIterative('J') );
    REQUIRE_FALSE( bst.containsIterative('A') );
    REQUIRE_FALSE( bst.containsIterative('Q') );
}

TEST_CASE( "ContainsRecursive" ) {
    CharBST bst;
    insertTestData(bst);

    REQUIRE( bst.containsRecursive('G') );
    REQUIRE( bst.containsRecursive('C') );
    REQUIRE( bst.containsRecursive('F') );
    REQUIRE( bst.containsRecursive('P') );
    REQUIRE( bst.containsRecursive('Y') );
    REQUIRE( bst.containsRecursive('J') );
    REQUIRE_FALSE( bst.containsRecursive('A') );
    REQUIRE_FALSE( bst.containsRecursive('Q') );
}

TEST_CASE( "InsertIterative" ) {
    CharBST bst;
    insertTestData(bst);

    bst.insertIterative('A');
    REQUIRE( bst.root->left->left != nullptr );
    REQUIRE( bst.root->left->left->value == 'A' );

    bst.insertIterative('D');
    REQUIRE( bst.root->left->right->left != nullptr );
    REQUIRE( bst.root->left->right->left->value == 'D' );

    bst.insertIterative('K');
    REQUIRE( bst.root->right->left->right != nullptr );
    REQUIRE( bst.root->right->left->right->value == 'K' );
}

TEST_CASE( "InsertIterativeRoot" ) {
    CharBST bst;

    bst.insertIterative('A');
    REQUIRE( bst.root != nullptr );
    REQUIRE( bst.root->value == 'A' );
}


TEST_CASE( "InsertRecursive" ) {
    CharBST bst;
    insertTestData(bst);

    bst.insertRecursive('A');
    REQUIRE( bst.root->left->left != nullptr );
    REQUIRE( bst.root->left->left->value == 'A' );

    bst.insertRecursive('D');
    REQUIRE( bst.root->left->right->left != nullptr );
    REQUIRE( bst.root->left->right->left->value == 'D' );

    bst.insertRecursive('K');
    REQUIRE( bst.root->right->left->right != nullptr );
    REQUIRE( bst.root->right->left->right->value == 'K' );
}

TEST_CASE( "InsertRecursiveRoot" ) {
    CharBST bst;

    bst.insertRecursive('A');
    REQUIRE( bst.root != nullptr );
    REQUIRE( bst.root->value == 'A' );
}


