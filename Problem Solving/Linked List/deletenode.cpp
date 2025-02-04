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

  void deleteNode(Node* node) {
    node->data = node->next->data;
    node->next = node->next->next;
  }
};

/*
- This first line would copy the value from the next node to the current node
- The next line would make the point point toward the next node ensuring that
the original value get skipped.

*/
