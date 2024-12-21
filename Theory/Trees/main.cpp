#include <iostream>

#include "practice.cpp"

using namespace std;

int main() {
  // Create Binary Tree
  BinaryTree<int> tree;

  // Insert nodes
  tree.insert(10);
  tree.insert(5);
  tree.insert(15);
  tree.insert(2);
  tree.insert(7);
  tree.insert(12);
  tree.insert(20);

  // Display traversals
  cout << "Inorder Traversal: ";
  tree.inorder();
  cout << endl;

  cout << "Preorder Traversal: ";
  tree.preorder();
  cout << endl;

  cout << "Postorder Traversal: ";
  tree.postorder();
  cout << endl;

  cout << "Levelorder Traversal: ";
  tree.levelorder();
  cout << endl;

  // Display tree properties
  cout << "Height of tree: " << tree.height() << endl;
  cout << "Is the tree balanced? " << (tree.is_balanced() ? "Yes" : "No")
       << endl;
  cout << "Diameter of tree: " << tree.diameter() << endl;
  cout << "Total node count: " << tree.count() << endl;

  // Remove node and display tree again
  tree.remove(7);
  cout << "Inorder Traversal after removing 7: ";
  tree.inorder();
  cout << endl;

  // Check the degree of nodes
  cout << "Degree 0 nodes: " << tree.deg0() << endl;
  cout << "Degree 1 nodes: " << tree.deg1() << endl;
  cout << "Degree 2 nodes: " << tree.deg2() << endl;

  // Check if trees are the same (same tree with itself)
  cout << "Is the tree same as itself? " << (tree.same_tree() ? "Yes" : "No")
       << endl;

  return 0;
}