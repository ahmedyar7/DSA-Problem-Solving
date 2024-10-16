#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
 private:
  int data;
  Node* next;
  Node* prev;

 public:
  Node(int data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }

  void set_next(Node* address) { next = address; }
  void set_prev(Node* address) { prev = address; }

  Node* get_next() { return next; }
  Node* get_prev() { return prev; }
  int get_data() { return data; }
};

#endif
