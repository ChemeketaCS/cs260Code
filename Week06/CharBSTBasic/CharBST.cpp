#include "CharBST.h"

#include <iostream>
using namespace std;

///----------------------CON/DE STRUCTORS----------------------------
CharBST::CharBST() {
  root = nullptr;
}

void deleteSubTree(BSTNode* curNode) {
  if (curNode != nullptr) {
    deleteSubTree(curNode->left);
    deleteSubTree(curNode->right);
    delete curNode;
  }
}

CharBST::~CharBST() {
  deleteSubTree(root);
  root = nullptr;
}

BSTNode* copySubTree(BSTNode* currentNode) {
  // TODO - FIXME
  return nullptr;
}

CharBST::CharBST(const CharBST& other) {
  root = copySubTree(other.root);
}

CharBST& CharBST::operator=(const CharBST& other) {
  if (this != &other) {
    // remove any existing nodes
    deleteSubTree(root);
    // copy nodes of other tree
    root = copySubTree(other.root);
  }
  return *this;
}

bool CharBST::isEmpty() {
  return root == nullptr;
}

///----------------------Print----------------------------
/// Nonmember helper function
string toStringHelper(BSTNode* curNode) {
  if (curNode == nullptr)
    return "";

  string result = toStringHelper(curNode->left);
  result += to_string(curNode->value) + " ";
  result += toStringHelper(curNode->right);

  return result;
}

string CharBST::toString() const {
  return toStringHelper(root);
}

///----------------------Search---------------------------

bool containsHelper(BSTNode* curNode, char valToFind) {
  // TODO - fixme
  return false;
}

/// recursive version
bool CharBST::containsRecursive(char valToFind) const {
  return containsHelper(root, valToFind);
}

/// iterative version
bool CharBST::containsIterative(char valToFind) const {
  // TODO - fixme
  return false;
}

///----------------------insert---------------------------

BSTNode* insertHelper(BSTNode* curNode, char insertVal) {
  // TODO - fixme
  return nullptr;
}

void CharBST::insertRecursive(char insertVal) {
  root = insertHelper(root, insertVal);
}

void CharBST::insertIterative(char insertVal) {
  // TODO - fixme
}


///----------------------RemoveSmallest---------------------------

// Recursive function to remove smallest value starting from indicated node
BSTNode* removeSmallestHelper(BSTNode* curNode) {
  // TODO - fixme
  return nullptr;
}

void CharBST::removeSmallest() {
  if (root != nullptr)
    root = removeSmallestHelper(root);
}

///----------------------Smallest---------------------------

// Recursive function to find the smallest value starting from indicated node
char smallestValueFrom(BSTNode* curNode) {
  // TODO - fixme
  return '?';
}

///----------------------Removal---------------------------
/// Helper function for remove - chains down, until it finds node to
/// remove. Removes that node and repairs pointers on way back up
BSTNode* removeHelper(BSTNode* curNode, char valToRemove) {
  if (curNode == nullptr) {
    return nullptr; // Value not in tree
  } else if (valToRemove < curNode->value) {
    curNode->left = removeHelper(curNode->left, valToRemove);
  } else if (curNode->value < valToRemove) {
    // set right child to the result of removing the value from the right
    // subtree
  } else { // Found the value to remove

    // TODO

    // Case 0: No children (subcase of 1)
    //           Delete & return nullptr

    // Case 1: No right child
    //           Delete current and return left child

    // Case 2: No left child
    //           Delete current and return right child

    // Case 3: Two children
    //           Replace current's value with smallest value in right subtree
    //           Then set right child to result of removing that value from
    //           right subtree
  }

  return curNode; // This node still exists. Return it back to caller.
}

void CharBST::remove(char value) {
  // new root is root that results from doing removeHelper
  root = removeHelper(root, value);
}
