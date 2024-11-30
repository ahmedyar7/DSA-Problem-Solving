#include <iostream>

#include "avl_practice.cpp"
using namespace std;

int main() {
  AVLTrees avlTree;

  cout << "Inserting values into the AVL Tree..." << endl;
  avlTree.insert(10);
  avlTree.insert(20);
  avlTree.insert(30);
  avlTree.insert(40);
  avlTree.insert(50);
  avlTree.insert(25);

  cout << "In-order traversal of the AVL Tree after insertion:" << endl;
  avlTree.inorder();  // Expected: 10 20 25 30 40 50
  cout << endl;

  cout << "Deleting value 40 from the AVL Tree..." << endl;
  avlTree.delete_node(avlTree.root, 40);

  cout << "In-order traversal of the AVL Tree after deletion:" << endl;
  avlTree.inorder();  // Expected: 10 20 25 30 50
  cout << endl;

  return 0;
}
