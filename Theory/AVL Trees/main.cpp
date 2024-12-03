#include <iostream>

#include "avl_practice.cpp"
using namespace std;

int main() {
  AVLTrees avl;

  // Insert nodes
  avl.insert(10);
  avl.insert(20);
  avl.insert(30);
  avl.insert(40);
  avl.insert(50);
  avl.insert(25);

  cout << "Inorder Traversal after Insertions: ";
  avl.inorder();
  cout << endl;

  // Delete a node
  avl.remove(50);

  cout << "Inorder Traversal after Deletion of 50: ";
  avl.inorder();
  cout << endl;

  return 0;
}
