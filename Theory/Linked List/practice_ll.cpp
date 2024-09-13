#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int value) {
    data = value;
    next = NULL;
  }
};

// Insert at head
void insert_at_head(Node*& head, int value) {
  Node* new_node = new Node(value);
  new_node->next = head;
  head = new_node;
}

// Insert at tail
void insert_at_tail(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == NULL) {
    head = new_node;
  }

  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = new_node;
}

void insert_at_sorted(Node*& head, int value) {
  Node* current = head;
  Node* prev = NULL;
  Node* new_node = new Node(value);

  if (head == NULL || head->data >= value) {
    head = new_node;
    return;
  }

  while (current != NULL && current->data < value) {
    prev = current;
    current = current->next;
  }

  new_node->next = current;
  prev->next = new_node;
}

// Delete Node
void delete_node(Node*& head, int position) {
  Node* current = head;
  Node* prev = NULL;

  if (position < 1 || head == NULL) return;

  for (int i = 1; i < position; i++) {
    if (current == NULL) return;
    prev = current;
    current = current->next;
  }

  if (prev == NULL) head = current->next;
  prev->next = current->next;
  delete current;
}

// Display Linked List
void display(Node* head) {
  while (head != NULL) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

int main() {
  Node* node = NULL;  // Initialize the linked list head to NULL

  // Build the list
  for (int i = 0; i <= 5; i++) {
    insert_at_head(node, i);  // Insert at head
    insert_at_tail(node, i);  // Insert at tail
  }

  // Insert an element in a sorted position
  insert_at_sorted(node, 99);

  // Delete a node at the second position
  delete_node(node, 2);

  // Display the list
  display(node);

  return 0;
}