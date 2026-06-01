#ifndef BSTNODE_H
#define BSTNODE_H

struct BSTNode {
  // Store a value and two child pointers
  char value;
  BSTNode* left;
  BSTNode* right;

  ///-------------------------------------------------------
  ///  Everything else just to provide tracking of nodes
  ///-------------------------------------------------------

  // Constructor - left/right set to null
  BSTNode(char val);

  // Disable copy/assignment
  BSTNode(const BSTNode& val) = delete;
  BSTNode& operator=(const BSTNode& val) = delete;

  // Destructor - decrement counter
  ~BSTNode();

  // Debugging purposes only - Not a normal feature
  //   Used for tracking memory allocation, updated in constructor/destructor
  static int nodeCount;
};

#endif // BSTNODE_H
