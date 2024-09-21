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

Node* concate(Node*& node1, Node*& node2) {
  Node* first = node1;
  Node* second = node2;

  if (first == nullptr) return second;
  if (second == nullptr) return first;

  while (first->next != nullptr) {
    first = first->next;
  }
  first->next = second;
  second = nullptr;
  return node1;
}

Node* merge_dll(Node*& node1, Node*& node2) {
  Node* first = node1;
  Node* second = node2;
  Node* last = nullptr;
  Node* third = nullptr;

  if (first == nullptr) return second;
  if (second == nullptr) return first;

  // Initialize third and last pointers to the smaller head node
  if (first->data < second->data) {
    third = last = first;
    first = first->next;
  } else {
    third = last = second;
    second = second->next;
  }

  // Merge the two lists
  while (first != nullptr && second != nullptr) {
    if (first->data < second->data) {
      last->next = first;   // Link the smaller node to the merged list
      last = first;         // Move the last pointer forward
      first = first->next;  // Advance the first list
    } else {
      last->next = second;
      last = second;
      second = second->next;
    }
  }

  // Attach the remaining part of whichever list is not yet finished
  if (first == nullptr) {
    last->next = second;
  } else {
    last->next = first;
  }

  return third;  // Return the merged list's head
}

void remove_duplicates(Node*& head) {
  Node* prev = head;
  Node* current = prev->next;

  while (current != nullptr) {
    if (prev->data != current->data) {
      prev = current;
      current = current->next;
    } else {
      prev->next = current->next;
      delete current;
      current = prev->next;
    }
  }
}

int main() {
  Node* node1 = nullptr;
  Node* node2 = nullptr;

  insert_at_tail(node1, 1);
  insert_at_tail(node1, 3);
  insert_at_tail(node1, 5);
  insert_at_tail(node1, 7);

  insert_at_tail(node2, 9);
  insert_at_tail(node2, 2);
  insert_at_tail(node2, 3);
  insert_at_tail(node2, 2);
  insert_at_tail(node2, 9);

  Node* merged = merge_dll(node1, node2);

  display(merged);
}