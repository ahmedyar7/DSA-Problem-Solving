#include <iostream>
using namespace std;

// Doubly Linked List
class Node {
 public:
  Node* prev;
  int data;
  Node* next;

  Node(int value) {
    prev = nullptr;
    data = value;
    next = nullptr;
  }
};

void insert_at_head(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == nullptr) {
    head = new_node;
    return;
  }
  new_node->next = head;
  head->prev = new_node;
  head = new_node;
}

void insert_at_tail(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == NULL) {
    head = new_node;
    return;
  }

  Node* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = new_node;
  new_node->prev = temp;
}

void insert_at_position(Node*& head, int position, int value) {
  Node* new_node = new Node(value);
  Node* temp = head;

  for (int i = 1; i < position - 1; i++) {
    temp = temp->next;
  }
  new_node->next = temp->next;
  new_node->prev = temp;

  temp->next = new_node;
  temp->next->prev = new_node;
}

void display(Node* head) {
  if (head == nullptr) return;
  while (head != NULL) {
    cout << head->data << " <-> ";
    head = head->next;
  }
  cout << "NULL\n";
}

void delete_head_node(Node*& head) {
  Node* current = head;
  head = head->next;
  delete current;
  if (head != NULL) head->prev = NULL;
}

void delete_at_given_position(Node*& head, int position) {
  if (position == 1) {
    delete_head_node(head);
    return;
  }
  Node* p = head;

  for (int i = 0; i < position; i++) {
    p = p->next;
  }

  p->prev->next = p->next;
  p->next->prev = p->prev;
  delete p;
}

void reversing_dll(Node*& head) {
  Node* current = head;
  Node* temp = nullptr;

  while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;

    current = current->prev;
  }

  if (temp != NULL) head = temp->prev;
}

int main() {
  Node* node = NULL;

  insert_at_tail(node, 1);
  insert_at_tail(node, 2);
  insert_at_tail(node, 3);
  insert_at_tail(node, 4);
  insert_at_position(node, 2, 2);
  display(node);
  // delete_head_node(node);
  // delete_at_given_position(node, 1);
  reversing_dll(node);
  display(node);
}
