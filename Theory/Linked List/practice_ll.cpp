#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int value) {
    data = value;
    next = nullptr;
  }
};

void insert_at_tail(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == nullptr) {
    head = new_node;
    new_node->next = head;
  }
  Node* temp = head;
  while (temp->next != head) {
    temp = temp->next;
  }
  temp->next = new_node;
  new_node->next = head;
}

void display(Node* head) {
  if (head == nullptr) return;
  Node* temp = head;

  do {
    cout << temp->data << " -> ";
    temp = temp->next;
  } while (temp != head);
  cout << "HEAD\n";
}

void insert_at_head(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == nullptr) {
    new_node->next = head;
    head = new_node;
    return;
  }

  Node* temp = head;
  while (temp->next != head) temp = temp->next;
  temp->next = new_node;
  new_node->next = head;
  head = new_node;
}

void insert_at_position(Node*& head, int value, int position) {
  Node* new_node = new Node(value);
  if (head == nullptr || position == 1) insert_at_head(head, value);

  Node* temp = head;
  for (int i = 0; i < position - 1 && temp->next != head; i++) {
    temp = temp->next;
  }
  new_node->next = temp->next;
  temp->next = new_node;
  return;
}

void delete_head_node(Node*& head) {
  if (head == nullptr) {
    delete head;
    head->next = nullptr;
    return;
  }

  Node* temp = head;
  Node* last = head;

  while (last->next != head) {
    last = last->next;
  }

  head = head->next;
  last->next = head;
  delete temp;
}

void delete_any_node(Node*& head, int position) {
  if (head == nullptr) {
    delete head;
    head->next = nullptr;
    return;
  }

  Node* temp = head;
  Node* last = head;
  while (last->next != head) {
    last = last->next;
  }
  head = head->next;
  last->next = head;
  delete temp;
  return;

  Node* current = head;
  Node* previous = nullptr;

  for (int i = 1; i < position && current->next != head; i++) {
    previous = current;
    current = current->next;
  }

  previous->next = current->next;
  delete current;
  return;
}

int main() {
  Node* node = nullptr;

  insert_at_tail(node, 1);
  insert_at_head(node, 0);
  insert_at_tail(node, 2);
  insert_at_position(node, 22, 2);
  insert_at_tail(node, 3);
  display(node);

  // delete_head_node(node);
  delete_any_node(node, 3);
  display(node);
}