#include <iostream>

#include "practice.cpp"
using namespace std;

int main() {
  BinaryTree tree;

  // Insert nodes into the tree
  tree.insert(15);
  tree.insert(10);
  tree.insert(20);
  tree.insert(8);
  tree.insert(12);
  tree.insert(17);
  tree.insert(25);
  tree.insert(6);
  tree.insert(9);
  tree.insert(11);
  tree.insert(13);
  tree.insert(16);
  tree.insert(18);
  tree.insert(22);
  tree.insert(27);

  // Preorder traversal
  cout << "Preorder traversal: ";
  tree.preorder();
  cout << endl;

  // Inorder traversal
  cout << "Inorder traversal: ";
  tree.inorder();
  cout << endl;

  // Postorder traversal
  cout << "Postorder traversal: ";
  tree.postorder();
  cout << endl;

  // Levelorder traversal
  cout << "Levelorder traversal: ";
  tree.levelorder();
  cout << endl;

  // Count the total number of nodes
  cout << "Total number of nodes: ";
  tree.count();
  cout << endl;

  // Count the number of leaf nodes
  cout << "Number of leaf nodes: ";
  tree.count_leafs();
  cout << endl;

  // Height of the tree
  cout << "Height of the tree: ";
  tree.height();
  cout << endl;

  // Count nodes with degree 2 (nodes having both left and right children)
  cout << "Number of nodes with degree 2: ";
  tree.deg2();
  cout << endl;

  // Count nodes with degree 1 (nodes having only one child)
  cout << "Number of nodes with degree 1: ";
  tree.deg1();
  cout << endl;

  // Example of constructing a tree using preorder and inorder
  int preorder[] = {15, 10, 8, 6, 9, 12, 11, 13, 20, 17, 16, 18, 25, 22, 27};
  int inorder[] = {6, 8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 20, 22, 25, 27};
  int preorder_index = 0;
  int n = sizeof(preorder) / sizeof(preorder[0]);

  BinaryTree tree2;
  tree2.root =
      tree2.construct_tree(preorder, inorder, preorder_index, 0, n - 1);

  cout << "Inorder traversal of the constructed tree: ";
  tree2.inorder();
  cout << endl;

  return 0;
}