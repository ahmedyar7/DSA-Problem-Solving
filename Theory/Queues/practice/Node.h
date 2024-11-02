#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
 private:
 public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};
#endif