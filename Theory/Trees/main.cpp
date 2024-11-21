#include <iostream>

#include "practice.cpp"

using namespace std;

int main() {
  BinaryTree btree;
  btree.insert(5);
  btree.insert(35);
  btree.insert(54);
  btree.insert(53);

  btree.display();
}