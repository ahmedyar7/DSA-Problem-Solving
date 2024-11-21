#include <iostream>

#include "practice.cpp"

using namespace std;

int main() {
  BinaryTree btree;
  btree.insert(10);
  btree.insert(5);
  btree.insert(15);
  btree.insert(2);
  btree.insert(7);
  btree.insert(12);
  btree.insert(17);

  btree.display();
}