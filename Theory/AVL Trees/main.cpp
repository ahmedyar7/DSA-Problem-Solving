#include <iostream>

#include "avl_practice.cpp"
using namespace std;

int main() {
  AVLTrees tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(25);
  tree.insert(5);
  tree.insert(35);

  cout << "Inorder traversal of AVL tree:" << endl;
  tree.inorder();

  tree.delete_value(10);
  cout << "Inorder after deleting 10:" << endl;
  tree.inorder();

  return 0;
}
