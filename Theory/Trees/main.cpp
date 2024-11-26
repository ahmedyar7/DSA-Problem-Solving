#include <iostream>

#include "practice.cpp"

using namespace std;

int main() {
  BinaryTree tree;
  tree.insert(10);  // root
  tree.insert(5);
  tree.insert(15);
  tree.insert(3);
  tree.insert(7);
  tree.insert(12);
  tree.insert(8);

  tree.display();
  cout << endl;

  cout << tree.count() << endl;
  cout << tree.height() << endl;
  cout << tree.leaf_nodes() << endl;
  cout << tree.node_deg2() << endl;

  return 0;
}
