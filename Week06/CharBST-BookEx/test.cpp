// Bring in unit testing code and tell it to build a main function
// If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "CharBST.h"

// Declare helper functions from the .cpp file so that we can directly test them
char smallestValueFrom(BSTNode* curNode);
BSTNode* removeSmallestHelper(BSTNode* startNode);
void deleteSubTree(BSTNode* curNode);
BSTNode* copySubTree(BSTNode* currentNode);

using namespace std;

/* Adds test data to produce this tree:
 *         _G_
 *        /   \
 *       C     P
 *        \   / \
 *         F J   Y
 */

void insertTestData(CharBST& c) {
  c.root = nullptr; // remove (and leak!!!) any existing nodes

  c.root = new BSTNode('G');
  c.root->left = new BSTNode('C');
  c.root->left->right = new BSTNode('F');
  c.root->right = new BSTNode('P');
  c.root->right->right = new BSTNode('Y');
  c.root->right->left = new BSTNode('J');
}

TEST_CASE("ContainsIterative") {
  CharBST bst;
  insertTestData (bst);

  REQUIRE(bst.containsIterative('G'));
  REQUIRE(bst.containsIterative('C'));
  REQUIRE(bst.containsIterative('F'));
  REQUIRE(bst.containsIterative('P'));
  REQUIRE(bst.containsIterative('Y'));
  REQUIRE(bst.containsIterative('J'));
  REQUIRE_FALSE(bst.containsIterative('A'));
  REQUIRE_FALSE(bst.containsIterative('Q'));
}

TEST_CASE("ContainsRecursive") {
  CharBST bst;
  insertTestData(bst);

  REQUIRE(bst.containsRecursive('G'));
  REQUIRE(bst.containsRecursive('C'));
  REQUIRE(bst.containsRecursive('F'));
  REQUIRE(bst.containsRecursive('P'));
  REQUIRE(bst.containsRecursive('Y'));
  REQUIRE(bst.containsRecursive('J'));
  REQUIRE_FALSE(bst.containsRecursive('A'));
  REQUIRE_FALSE(bst.containsRecursive('Q'));
}

TEST_CASE("InsertIterative") {
  CharBST bst;
  insertTestData(bst);

  bst.insertIterative('A');
  REQUIRE(bst.root->left->left != nullptr);
  REQUIRE(bst.root->left->left->value == 'A');

  bst.insertIterative('D');
  REQUIRE(bst.root->left->right->left != nullptr);
  REQUIRE(bst.root->left->right->left->value == 'D');

  bst.insertIterative('K');
  REQUIRE(bst.root->right->left->right != nullptr);
  REQUIRE(bst.root->right->left->right->value == 'K');
}

TEST_CASE("InsertIterativeRoot") {
  CharBST bst;

  bst.insertIterative('A');
  REQUIRE(bst.root != nullptr);
  REQUIRE(bst.root->value == 'A');
}

TEST_CASE("InsertRecursive") {
  CharBST bst;
  insertTestData(bst);

  bst.insertRecursive('A');
  REQUIRE(bst.root->left->left != nullptr);
  REQUIRE(bst.root->left->left->value == 'A');

  bst.insertRecursive('D');
  REQUIRE(bst.root->left->right->left != nullptr);
  REQUIRE(bst.root->left->right->left->value == 'D');

  bst.insertRecursive('K');
  REQUIRE(bst.root->right->left->right != nullptr);
  REQUIRE(bst.root->right->left->right->value == 'K');
}

TEST_CASE("InsertRecursiveRoot") {
  CharBST bst;

  bst.insertRecursive('A');
  REQUIRE(bst.root != nullptr);
  REQUIRE(bst.root->value == 'A');
}



/* Adds test data to produce this tree:
 *         _G_
 *        /   \
 *       C     P
 *      / \   / \
 *     B   F J   Y
 *            \
 *             M
 */

void insertTestData2(CharBST& c) {
  c.root = nullptr; // remove (and leak!!!) any existing nodes

  c.root = new BSTNode('G');

  c.root->left = new BSTNode('C');
  c.root->left->left = new BSTNode('B');
  c.root->left->right = new BSTNode('F');

  c.root->right = new BSTNode('P');
  c.root->right->right = new BSTNode('Y');
  c.root->right->left = new BSTNode('J');
  c.root->right->left->right = new BSTNode('M');
}

TEST_CASE("DeleteSubTree") {
  {
    CharBST bst;
    insertTestData2(bst); // 8 nodes

    // remove left 3 nodes
    deleteSubTree(bst.root->left);
    bst.root->left = nullptr;
    REQUIRE(BSTNode::nodeCount == 5);

    // remove 2 more nodes
    deleteSubTree(bst.root->right->left);
    bst.root->right->left = nullptr;
    REQUIRE(BSTNode::nodeCount == 3);

    // Correctly does nothing with null?
    deleteSubTree(nullptr);

    // Destructor called here - deletes rest of nodes
  }
  REQUIRE(BSTNode::nodeCount == 0);
}

TEST_CASE("CopySubTreeSingle") {
  CharBST bst;
  insertTestData2(bst); // 8 nodes

  // Copy one node
  BSTNode* copyOfB = copySubTree(bst.root->left->left);
  // Should new node with same value, but NOT be the same node
  REQUIRE(copyOfB->value == 'B');
  REQUIRE(copyOfB != bst.root->left->left);
  deleteSubTree(copyOfB);
}

TEST_CASE("CopySubTree") {
  CharBST bst;
  insertTestData2(bst); // 8 nodes

  // Copy three nodes
  int startNodeCount = BSTNode::nodeCount;
  BSTNode* copyOfC = copySubTree(bst.root->left);
  REQUIRE(copyOfC->value == 'C');
  REQUIRE(copyOfC->left->value == 'B');
  REQUIRE(copyOfC->right->value == 'F');
  int newNodeCount = BSTNode::nodeCount;
  REQUIRE(newNodeCount - startNodeCount == 3);
  deleteSubTree(copyOfC);
}

TEST_CASE("Copy") {
  CharBST bst;
  insertTestData2(bst); // 8 nodes

  int startNodeCount = BSTNode::nodeCount;

  CharBST copy = bst; // calls copy constructor

  int newNodeCount = BSTNode::nodeCount;
  REQUIRE(newNodeCount - startNodeCount == 8);

  // Check a few nodes
  REQUIRE(copy.root != nullptr);
  REQUIRE(copy.root != bst.root);
  REQUIRE(copy.root->value == 'G');

  REQUIRE(copy.root->right != nullptr);
  REQUIRE(copy.root->right->value == 'P');

  REQUIRE(copy.root->right->left != nullptr);
  REQUIRE(copy.root->right->left->value == 'J');

  REQUIRE(copy.root->right->left->right != nullptr);
  REQUIRE(copy.root->right->left->right->value == 'M');
}

TEST_CASE("FindSmallest") {
  CharBST bst;
  insertTestData2(bst); // 8 nodes

  char fromB = smallestValueFrom(bst.root);
  REQUIRE(fromB == 'B');

  char fromP = smallestValueFrom(bst.root->right);
  REQUIRE(fromP == 'J');

  char fromY = smallestValueFrom(bst.root->right->right);
  REQUIRE(fromY == 'Y');
}

TEST_CASE("RemoveSmallest") {
  CharBST bst;
  insertTestData2(bst); // 8 nodes

  // Remove B
  int startNodeCount = BSTNode::nodeCount;
  bst.removeSmallest();
  REQUIRE(bst.root->left->left == nullptr);
  int newNodeCount = BSTNode::nodeCount;
  REQUIRE(newNodeCount - startNodeCount == -1);

  // Then remove C
  startNodeCount = BSTNode::nodeCount;
  bst.removeSmallest();
  REQUIRE(bst.root->left->value == 'F');
  newNodeCount = BSTNode::nodeCount;
  REQUIRE(newNodeCount - startNodeCount == -1);

  // Then remove F
  startNodeCount = BSTNode::nodeCount;
  bst.removeSmallest();
  REQUIRE(bst.root->left == nullptr);
  newNodeCount = BSTNode::nodeCount;
  REQUIRE(newNodeCount - startNodeCount == -1);

  // Then remove G - the root
  startNodeCount = BSTNode::nodeCount;
  bst.removeSmallest();
  REQUIRE(bst.root->value == 'P');
  newNodeCount = BSTNode::nodeCount;
  REQUIRE(newNodeCount - startNodeCount == -1);
}

TEST_CASE("RemoveNoChildren") {
  CharBST bst;
  insertTestData2(bst); // 8 nodes

  // Remove B
  int startNodeCount = BSTNode::nodeCount;
  bst.remove('B');
  REQUIRE(bst.root->left->left == nullptr);
  int newNodeCount = BSTNode::nodeCount;
  REQUIRE(newNodeCount - startNodeCount == -1);
}

TEST_CASE("RemoveNoLeftChild") {
  CharBST bst;
  insertTestData2(bst); // 8 nodes

  // Remove J
  int startNodeCount = BSTNode::nodeCount;
  bst.remove('J');
  REQUIRE(bst.root->right->left != nullptr);
  REQUIRE(bst.root->right->left->value == 'M');
  int newNodeCount = BSTNode::nodeCount;
  REQUIRE(newNodeCount - startNodeCount == -1);
}

TEST_CASE("RemoveNoRightChild") {
  CharBST bst;
  insertTestData2(bst); // 8 nodes

  // Add left child to 'F'
  bst.root->left->right->left = new BSTNode('E');

  // Remove F
  int startNodeCount = BSTNode::nodeCount;
  bst.remove('F');
  REQUIRE(bst.root->left->right != nullptr);
  REQUIRE(bst.root->left->right->value == 'E');
  int newNodeCount = BSTNode::nodeCount;
  REQUIRE(newNodeCount - startNodeCount == -1);
}

TEST_CASE("RemoveTwoChildrenOne") {
  CharBST bst;
  insertTestData2(bst); // 8 nodes

  // Remove P
  int startNodeCount = BSTNode::nodeCount;
  bst.remove('P');
  REQUIRE(bst.root->right->value == 'Y');
  REQUIRE(bst.root->right->right == nullptr);
  int newNodeCount = BSTNode::nodeCount;
  REQUIRE(newNodeCount - startNodeCount == -1);
}

TEST_CASE("RemoveTwoChildrenTwo") {
  CharBST bst;
  insertTestData2(bst); // 8 nodes

  // Remove G
  int startNodeCount = BSTNode::nodeCount;
  bst.remove('G');
  REQUIRE(bst.root->value == 'J');
  REQUIRE(bst.root->right->left != nullptr);
  REQUIRE(bst.root->right->left->value == 'M');
  int newNodeCount = BSTNode::nodeCount;
  REQUIRE(newNodeCount - startNodeCount == -1);
}
