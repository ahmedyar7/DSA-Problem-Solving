#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node* prev;

  Node(int value) {
    data = value;
    next = nullptr;
    prev = nullptr;
  }
};

void insert_at_tail(Node*& head, int value) {
  Node* new_node = new Node(value);

  if (head == nullptr) {
    head = new_node;
    new_node->next = new_node;
    new_node->prev = new_node;
  }

  Node* tail = head->prev;
  new_node->next = head;
  new_node->prev = tail;
  tail->next = new_node;
  head->prev = new_node;
}

void insert_at_head(Node*& head, int value) {
  Node* new_node = new Node(value);

  if (head == nullptr) {
    head = new_node;
    new_node->next = new_node;
    new_node->prev = new_node;
  }

  Node* tail = head->prev;
  new_node->next = head;
  new_node->prev = tail;
  tail->next = new_node;
  head->prev = new_node;

  head = new_node;
}

void display(Node* head) {
  Node* temp = head;
  do {
    cout << temp->data << " -> ";
    temp = temp->next;
  } while (temp != head);
  cout << "HEAD\n";
}

int main() {
  Node* node = nullptr;
  insert_at_head(node, 1);
  insert_at_tail(node, 2);
  insert_at_tail(node, 3);
  display(node);
}