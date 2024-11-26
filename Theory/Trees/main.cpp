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
  tree.insert(6);

  tree.display();

  cout << endl;

  cout << "Total Nodes: " << tree.count() << endl;
  cout << "Height of Trees: " << tree.height() << endl;
  cout << "Nodes with degree 2: " << tree.node_deg2() << endl;
  cout << "Count Leaf Nodes: " << tree.leaf_nodes() << endl;

  return 0;
}
