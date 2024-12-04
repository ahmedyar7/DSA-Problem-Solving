#include <iostream>

#include "avl_practice.cpp"
using namespace std;

// Assuming the TreeNode and AVLTrees classes are already defined as you
// provided.

int main() {
  AVLTrees tree;

  // Inserting values into the AVL Tree
  cout << "Inserting values: 10, 20, 30, 25, 5, 4, 15" << endl;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(25);
  tree.insert(5);
  tree.insert(4);
  tree.insert(15);

  // Print inorder traversal after insertions
  cout << "Inorder traversal after insertions: ";
  tree.inorder();
  cout << endl;

  // Deleting some values from the AVL Tree
  cout << "Deleting values: 25, 5, 30" << endl;
  tree.remove(25);
  tree.remove(5);
  tree.remove(30);

  // Print inorder traversal after deletions
  cout << "Inorder traversal after deletions: ";
  tree.inorder();
  cout << endl;

  // Insert more values to test balancing
  cout << "Inserting more values: 35, 3, 8" << endl;
  tree.insert(35);
  tree.insert(3);
  tree.insert(8);

  // Print final inorder traversal
  cout << "Final inorder traversal: ";
  tree.inorder();
  cout << endl;

  return 0;
}
