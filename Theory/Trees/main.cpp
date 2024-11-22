#include <iostream>

#include "practice.cpp"

using namespace std;

int main() {
  BinaryTree tree;

  // Insert nodes to form a large, complete binary tree
  tree.insert(50);  // Root
  tree.insert(30);
  tree.insert(70);
  tree.insert(20);
  tree.insert(40);
  tree.insert(60);
  tree.insert(80);
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

  // Visualize tree using ASCII art
  cout << "\nTree Visualization (ASCII Art):\n";
  print_ascii_tree(tree.get_root());

  return 0;
}
