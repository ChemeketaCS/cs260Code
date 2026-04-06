#ifndef CHARBST_H
#define CHARBST_H

#include <string>

#include "BSTNode.h"

class CharBST {
  // Would normally be private.
  // Made public to allow intrusive unit tests.
public:
  BSTNode* root;

public:
  /// Constructor - root inited to null
  CharBST();
  /// Destructor - deletes any child nodes
  ~CharBST();

  // copy/assignment
  CharBST(const CharBST& val);
  CharBST& operator=(const CharBST& val);

  /// return true if no values in tree
  bool isEmpty();

  /// Produce an in order string representation
  std::string toString() const;

  /// check if value is present
  bool containsRecursive(char val) const;
  bool containsIterative(char val) const;

  /// add (a possibly duplicate) value to tree
  void insertRecursive(char val);
  void insertIterative(char val);

  /// remove indicated char from tree
  void remove(char val);
  /// remove the smallest value from the tree
  void removeSmallest();

};

#endif // CHARBST_H
