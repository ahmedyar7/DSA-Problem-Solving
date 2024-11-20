#include <iostream>

#include "binarytree.h"
int main() {
  BinaryTree tree;

  // Insert values into the binary tree
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(20);
  tree.insert(40);
  tree.insert(60);
  tree.insert(80);

  // Display the tree in-order
  std::cout << "In-order Traversal: ";
  tree.display_inorder_traversal();

  return 0;
}
