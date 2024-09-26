#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node* previous;
  Node(int value) {
    data = value;
    next = nullptr;
    previous = nullptr;
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
  new_node->previous = temp;
}

void display(Node* head) {
  if (head == nullptr) {
    cout << "Empty List\n";
    return;
  }
  while (head != nullptr) {
    cout << head->data << " <-> ";
    head = head->next;
  }
  cout << "NULL\n";
}

void insert_at_head(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == nullptr) {
    head = new_node;
    return;
  }
  new_node->next = head;
  head->previous = new_node;
  head = new_node;
}

void insert_at_position(Node*& head, int value, int position) {
  Node* new_node = new Node(value);
  if (head == nullptr || position < 0) {
    cout << "Invalid Position\n";
    return;
  }
  if (position == 1) {
    insert_at_head(head, value);
    return;
  }
  Node* temp = head;
  for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
    temp = temp->next;
  }
  new_node->next = temp->next;
  temp->next = new_node;
  temp->next->previous = new_node;
  new_node->previous = temp;

  return;
}

void delete_head(Node*& head) {
  if (head == nullptr) {
    cout << "Empty Linked List\n";
    return;
  }
  Node* temp = head;
  head = head->next;
  delete temp;
}

void delete_at_position(Node*& head, int position) {
  if (head == nullptr || position < 0) {
    cout << "Invalid Position\n";
    return;
  }
  if (position == 1) {
    delete_head(head);
    return;
  }
  Node* temp = head;
  for (int i = 1; i < position && temp->next != nullptr; i++) {
    temp = temp->next;
  }
  temp->previous->next = temp->next;
  temp->next->previous = temp->previous;
  delete temp;
}

Node* concatenate(Node*& node1, Node*& node2) {
  Node* first = node1;
  Node* second = node2;

  if (first == nullptr) return second;
  if (second == nullptr) return first;

  while (first->next != nullptr) {
    first = first->next;
  }
  first->next = second;
  return node1;
}

Node* merge_dll(Node*& node1, Node*& node2) {
  Node* first = node1;
  Node* second = node2;
  Node* third = nullptr;
  Node* last = nullptr;

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

  if (first == nullptr) {
    last->next = second;
  }
  if (second == nullptr) {
    last->next = first;
  }
  return third;
}

void remove_duplicate(Node*& head) {
  Node* prev = head;
  Node* current = prev->next;
  if (head == nullptr) {
    cout << "List Is Empty\n";
    return;
  }
  while (current != nullptr) {
    if (current->data != prev->data) {
      prev = current;
      current = current->next;
    } else {
      prev->next = current->next;
      delete current;
      current = prev->next;
      current->previous = current;
    }
  }
}

void insert_at_sorted_position(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == nullptr) {
    head = new_node;
    return;
  }
  Node* temp = head;
  while (temp->next != nullptr) {
    if (temp->data > value) {
      insert_at_head(head, value);
    } else {
      new_node->next = temp->next;
      temp->next = new_node;
      temp->next->previous = new_node;
      new_node->previous = temp;
    }
  }
  return;
}

int main() {
  Node* node1 = nullptr;
  Node* node2 = nullptr;
  for (int i = 0; i < 10; i++) {
    insert_at_tail(node1, i);
    insert_at_tail(node2, i - 2);
  }
  display(node1);
  display(node2);

  // Node* concat = concatenate(node1, node2);
  Node* merged = merge_dll(node1, node2);

  display(merged);
  remove_duplicate(merged);
  insert_at_sorted_position(merged, 5);
  display(merged);
}