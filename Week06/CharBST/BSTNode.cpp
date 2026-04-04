#include "CharBST.h"

int BSTNode::nodeCount = 0;

BSTNode::BSTNode(char val) {
  value = val;
  left = nullptr;
  right = nullptr;
  nodeCount++;
}

BSTNode::~BSTNode() {
  nodeCount--;
}