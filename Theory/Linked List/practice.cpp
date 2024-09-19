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
    return;
  }

  Node* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = new_node;
  new_node->prev = temp;
  return;
}

void display(Node* head) {
  if (head == nullptr) return;

  Node* temp = head;
  while (temp != nullptr) {
    cout << temp->data << " <- -> ";
    temp = temp->next;
  }
  cout << "NULL\n";
}

void insert_at_head(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == nullptr) {
    head = new_node;
  }
  Node* temp = head;
  new_node->next = temp;
  temp->prev = new_node;
  head = new_node;
}

void insert_at_position(Node*& head, int value, int position) {
  Node* new_node = new Node(value);
  if (position < 1) return;
  if (head == nullptr || position == 1) {
    insert_at_head(head, value);
  }

  Node* temp = head;
  for (int i = 1; i < position - 1 && temp->next != head; i++) {
    temp = temp->next;
  }

  new_node->next = temp->next->next;
  temp->next = new_node;
  return;
}

void reverse_dll(Node*& head) {
  Node* current = head;
  Node* temp = nullptr;

  while (current != nullptr) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  if (temp != nullptr) head = temp->prev;
}

int main() {
  Node* node = nullptr;
  insert_at_tail(node, 1);
  // insert_at_head(node, 2222);
  insert_at_tail(node, 2);
  // insert_at_position(node, 2212, 1);
  insert_at_tail(node, 3);
  insert_at_tail(node, 3);
  insert_at_tail(node, 3);

  display(node);
  reverse_dll(node);
  display(node);
}