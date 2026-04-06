// Bring in unit testing code and tell it to build a main function
// If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

#include "CharBST.h"

BSTNode* rotateLeft(BSTNode* parent) {
  /// TODO - fixme
  return nullptr;
}

BSTNode* rotateRight(BSTNode* parent) {
  /// TODO - fixme
  return nullptr;
}

int getHeight(BSTNode* node) {
  // TODO - fixme
  return -1;
}

int getBalance(BSTNode* node) {
  // TODO - fixme
  return -1;
}

using namespace std;

/* Adds test data to produce this tree:
 *         _G_
 *        /   \
 *       C     P
 *      / \   / \
 *     B   F J   Y
 *            \
 *             M
 */

void insertTestData(CharBST& c) {
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

TEST_CASE("RotateRightAtC") {
  CharBST bst;
  insertTestData(bst);

  BSTNode* target = bst.root->left;

  BSTNode* newParent = rotateRight(target);

  REQUIRE(newParent->value == 'B');
  REQUIRE(newParent->right->value == 'C');
  REQUIRE(newParent->right->left == nullptr);
}

TEST_CASE("RotateRightAtG") {
  CharBST bst;
  insertTestData(bst);

  BSTNode* target = bst.root;

  BSTNode* newParent = rotateRight(target);

  REQUIRE(newParent->value == 'C');
  REQUIRE(newParent->right->value == 'G');
  REQUIRE(newParent->right->left->value == 'F');
}

TEST_CASE("RotateLeftAtC") {
  CharBST bst;
  insertTestData(bst);

  BSTNode* target = bst.root->left;

  BSTNode* newParent = rotateLeft(target);

  REQUIRE(newParent->value == 'F');
  REQUIRE(newParent->left->value == 'C');
  REQUIRE(newParent->left->right == nullptr);
}

TEST_CASE("RotateLeftAtG") {
  CharBST bst;
  insertTestData(bst);

  BSTNode* target = bst.root;

  BSTNode* newParent = rotateLeft(target);

  REQUIRE(newParent->value == 'P');
  REQUIRE(newParent->left->value == 'G');
  REQUIRE(newParent->left->right->value == 'J');
}

TEST_CASE("Height") {
  CharBST bst;
  insertTestData(bst);

  int FHeight = getHeight(bst.root->left->right);
  REQUIRE(FHeight == 0);

  int JHeight = getHeight(bst.root->right->left);
  REQUIRE(JHeight == 1);

  int fullHeight = getHeight(bst.root);
  REQUIRE(fullHeight == 3);
}

TEST_CASE("Balance") {
  CharBST bst;
  insertTestData(bst);

  int FBal = getBalance(bst.root->left->right);
  REQUIRE(FBal == 0);

  int JBal = getBalance(bst.root->right->left);
  REQUIRE(JBal == 1);

  int PBal = getBalance(bst.root->right);
  REQUIRE(PBal == -1);

  int fullBal = getBalance(bst.root);
  REQUIRE(fullBal == 1);
}
