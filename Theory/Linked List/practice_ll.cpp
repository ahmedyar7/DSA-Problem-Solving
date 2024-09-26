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
}

void insert_at_position(Node*& head, int value, int position) {
  Node* new_node = new Node(value);

  // Edge cases
  if (position < 1) {
    cout << "Invalid Position\n";
    return;
  }

  if (position == 1) {
    insert_at_head(head, value);
    return;
  }

  Node* current = head;
  for (int i = 1; i < position - 1 && current->next != head; i++) {
    current = current->next;
  }

  new_node->next = current->next;
  current->next = new_node;
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
  if (head == nullptr) {
    cout << "List is empty.\n";
    return;
  }

  if (head->next == head) {  // Only one node in the list
    delete head;
    head = nullptr;
    return;
  }

  Node* temp = head;
  Node* last = head;

  // Find the last node in the circular list
  while (last->next != head) {
    last = last->next;
  }

  // Point the last node to the second node
  last->next = head->next;
  head = head->next;

  delete temp;
}

void delete_at_position(Node*& head, int position) {
  if (head == nullptr || position < 1) {
    cout << "Invalid Position\n";
    return;
  }

  // Case when deleting the first node (position == 1)
  if (position == 1) {
    delete_node(head);
    return;
  }

  // Traverse to the node just before the position
  Node* temp = head;
  for (int i = 1; i < position - 1 && temp->next != head; i++) {
    temp = temp->next;
  }

  // If temp->next is head, the position is out of range
  if (temp->next == head || temp->next == nullptr) {
    cout << "Position out of range\n";
    return;
  }

  // Delete the node at the desired position
  Node* node_to_delete = temp->next;
  temp->next = node_to_delete->next;
  delete node_to_delete;
}

int main() {
  Node* node = nullptr;

  // Insert at tail
  for (int i = 0; i < 10; i++) {
    insert_at_tail(node, i);
  }

  // Insert at a specific position
  insert_at_position(node, 22, 2);

  // Display list
  display(node);

  // Delete first node
  delete_node(node);

  // Display list after deletion
  display(node);
}
