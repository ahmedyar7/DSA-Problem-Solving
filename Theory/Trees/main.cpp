#include <iostream>

#include "practice.cpp"
using namespace std;

int main() {
  BinaryTree tree;

  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  tree.insert(7);
  tree.insert(8);

  cout << "Preorder Traversal\n";
  tree.preorder();

  cout << "\nInorder Traversal\n";
  tree.inorder();

  cout << "\nPostorder Traversal\n";
  tree.postorder();

  cout << "\nLevel order Traversal\n";
  tree.levelorder();
}