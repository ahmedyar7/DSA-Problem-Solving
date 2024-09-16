#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* prev;
  Node* next;

  Node(int value) {
    data = value;
    prev = nullptr;
    next = nullptr;
  }
};

void insert_at_end(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == NULL) {
    head = new_node;
    head->next = head;
    head->prev = head;
  }
  while (head != NULL) {
    head = head->next;
  }

  Node* last = head->prev;
  last->next = new_node;
  new_node->prev = last;
}