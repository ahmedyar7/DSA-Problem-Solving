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
    head = new_node;
    new_node->next = head;
  }

  Node* temp = head;
  while (temp->next != head) {
    temp = temp->next;
  }

  new_node->next = head;
  temp->next = new_node;
  new_node = head;
}

void insert_at_position(Node*& head, int value, int position) {
  Node* new_node = new Node(value);
  if (position < 1 || head == nullptr) {
    return;
  }
  if (position == 1) {
    if (head == nullptr) {
      insert_at_head(new_node, value);
    }
  }
  Node* temp = head;
  for (int i = 1; i < position; i++) temp = temp->next;
  new_node->next = temp->next;
  temp->next = new_node;
}

void delete_node(Node*& head, int position) {
  if (head == nullptr) return;

  if (position == 1) {
    if (head->next == head) {
      delete head;
      head = nullptr;
      return;
    }
  }

  Node* tail = head;
  while (tail->next != head) tail = tail->next;

  Node* temp = head;
  head = head->next;
  tail->next = head;
  delete temp;
  return;

  for (int i = 1; i < position && temp->next != head; i++) temp = temp->next;
  Node* p = temp->next;
  temp->next = p->next;
  delete p;
}

int main() {
  Node* node = nullptr;
  insert_at_head(node, 10);
  insert_at_position(node, 2, 2);
  delete_node(node, 2);
  insert_at_tail(node, 1);
  insert_at_tail(node, 2);
  insert_at_tail(node, 3);
  display(node);
}