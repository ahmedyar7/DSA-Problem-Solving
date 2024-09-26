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
    return;
  }
  Node* current = head;

  while (current->next != head) {
    current = current->next;
  }
  current->next = new_node;
  new_node->next = head;
}

void insert_at_head(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == nullptr) {
    head = new_node;
    new_node->next = head;
    return;
  }
  Node* current = head;
  while (current->next != head) {
    current = current->next;
  }
  new_node->next = head;
  current->next = new_node;
  head = new_node;

  return;
}

void insert_at_position(Node*& head, int value, int position) {
  Node* new_node = new Node(value);

  // Edge cases
  if (position < 0) {
    cout << "invalid Position\n";
    return;
  }

  if (position == 1) {
    insert_at_head(new_node, value);
  }
  Node* current = head;
  for (int i = 0; i < position - 1 && current->next != head; i++) {
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
  return;
}

void display(Node* head) {
  if (head == nullptr) {
    cout << "Empty Linked List\n";
    return;
  }
  Node* current = head;
  do {
    cout << current->data << " -> ";
    current = current->next;
  } while (current != head);
  cout << "HEAD\n";
}

void delete_node(Node*& head) {
  Node* temp = head;
  while (temp->next != head) {
    temp = temp->next;
  }
  temp->next = head->next;
  delete head;
  head = temp->next;
}

void delete_at_position(Node*& head, int position) {
  if (position < 0) {
    cout << "Invalid Postion\n";
    return;
  }
  if (position == 1) {
    delete_node(head);
  }
  Node* temp = head;
  for (int i = 1; i < position - 1 && temp->next != head; i++) {
    temp = temp->next;
  }
  temp->next = temp->next->next;
  delete temp;
  return;
}

int main() {
  Node* node = nullptr;
  for (int i = 0; i < 10; i++) insert_at_tail(node, i);
  // for (int i = 0; i < 10; i++) insert_at_head(node, i);

  insert_at_position(node, 22, 2);
  display(node);
  delete_node(node);
  display(node);
}