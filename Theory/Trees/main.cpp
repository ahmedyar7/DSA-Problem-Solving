#include <iostream>

#include "practice.cpp"

using namespace std;

int main() {
  BinaryTree tree;
  tree.insert(10);  // root
  tree.insert(12);
  tree.insert(11);
  tree.insert(13);
  tree.insert(23);
  tree.insert(21);
  tree.insert(15);

  tree.display();

  cout << tree.count();

  return 0;
}
