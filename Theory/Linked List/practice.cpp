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

void insert_at_head(Node*& head, int value) {
  Node* new_node = new Node(value);

  if (head == nullptr) {
    head = new_node;
    return;
  }

  new_node->next = head;
  head->prev = new_node;
  head = new_node;

  return;
}

void insert_at_tail(Node*& head, int value) {
  Node* new_node = new Node(value);
  Node* current = head;

  if (head == nullptr) {
    head = new_node;
    return;
  }

  while (current->next != nullptr) current = current->next;

  current->next = new_node;
  new_node->prev = current;
  new_node->next = nullptr;

  return;
}

void insert_at_position(Node*& head, int value, int position) {
  Node* new_node = new Node(value);
  Node* current = head;

  for (int i = 1; i < position - 1 && current->next != head; i++)
    current = current->next;

  new_node->next = current->next;
  new_node->prev = current;
  current->next = new_node;
  current->next->prev = new_node;

  return;
}

void display(Node* head) {
  Node* current = head;
  while (current != nullptr) {
    cout << current->data << " <-> ";
    current = current->next;
  }
  cout << "NULL\n";

  return;
}

void delete_head_node(Node*& head) {
  if (head == nullptr) return;

  Node* current = head;
  head = head->next;
  delete current;
  head->prev = nullptr;

  return;
}

void delete_at_position(Node*& head, int position) {
  if (head == nullptr) return;

  if (position < 1) return;
  if (position == 1) {
    delete_head_node(head);
    return;
  }

  Node* current = head;
  for (int i = 1; i < position && current->next != nullptr; i++)
    current = current->next;

  current->prev->next = current->next;
  current->next->prev = current->prev;

  delete current;
  return;
}

void reverse_dll(Node*& head) {
  if (head == nullptr) return;
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

Node* concatenation(Node*& node1, Node*& node2) {
  Node* first = node1;
  Node* second = node2;

  while (first->next != nullptr) {
    first = first->next;
  }
  first->next = second;
  second = nullptr;
  return node1;
}

Node* merge_doubly_LL(Node*& node1, Node*& node2) {
  Node* first = node1;
  Node* second = node2;
  Node* last = nullptr;
  Node* third = nullptr;

  if (first == nullptr) return second;
  if (second == nullptr) return first;

  if (first->data < second->data) {
    third = last = first;
    first = first->next;
  } else {
    third = last = second;
    second = second->next;
  }

  while (first != nullptr && second != nullptr) {
    if (first->data < second->data) {
      last->next = first;
      last = first;
      first = first->next;
    } else {
      last->next = second;
      last = second;
      second = second->next;
    }
  }

  if (first == nullptr)
    last->next = second;
  else
    last->next = first;

  return third;
}

int main() {
  Node* node1 = nullptr;
  Node* node2 = nullptr;

  insert_at_tail(node1, 1);
  insert_at_tail(node1, 3);
  insert_at_tail(node1, 5);
  insert_at_tail(node1, 7);
  insert_at_tail(node1, 9);

  insert_at_tail(node2, 2);
  insert_at_tail(node2, 4);
  insert_at_tail(node2, 6);
  insert_at_tail(node2, 8);
  insert_at_tail(node2, 10);

  display(node2);
  display(node1);

  Node* merged = merge_doubly_LL(node1, node2);
  display(merged);

  return 0;
}