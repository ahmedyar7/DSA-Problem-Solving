#include <iostream>

#include "practice.cpp"

using namespace std;

int main() {
  BinaryTree tree;

  // Insert nodes to form a large, complete binary tree
  tree.insert(5);  // Root
  tree.insert(9);
  tree.insert(2);
  tree.insert(8);
  tree.insert(6);
  tree.insert(11);
  tree.insert(3);
  tree.insert(10);
  tree.insert(25);
  tree.insert(35);
  tree.insert(45);
  tree.insert(55);
  tree.insert(65);
  tree.insert(75);
  tree.insert(85);

  // Display traversals
  cout << "Tree Traversals:\n";
  tree.display_traversals();

  return 0;
}
