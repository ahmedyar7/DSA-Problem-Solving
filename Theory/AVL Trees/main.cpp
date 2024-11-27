#include <iostream>

#include "avl.cpp"
using namespace std;

int main() {
  AVLTree tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  tree.insert(25);

  cout << "In-order traversal of the AVL tree: ";
  tree.inOrderTraversal();

  tree.remove(40);

  cout << "In-order traversal after deletion: ";
  tree.inOrderTraversal();

  return 0;
}