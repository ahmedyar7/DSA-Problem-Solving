#include <climits>
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

void insert_at_tail(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == NULL) {
    head = new_node;
    return;
  }

  Node* current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
}

bool check_sorted(Node* head) {
  int x = INT_MIN;
  while (head != NULL) {
    if (head->data < x) {
      return false;
    }
    x = head->data;
    head = head->next;
  }
  return true;
}

void remove_duplicates(Node* head) {
  if (head == NULL) return;

  Node* prev = head;
  Node* current = prev->next;

  while (current != NULL) {
    if (prev->data != current->data) {
      prev = current;
    } else {
      prev->next = current->next;
      delete current;
    }
    current = prev->next;
  }
}

Node* search_node(Node* head, int key) {
  Node* current = head;
  Node* prev = NULL;

  while (current != NULL) {
    if (current->data == key) {
      if (prev != NULL) {
        prev->next = current->next;
        current->next = head;
        head = current;
      }
      return current;
    }
    prev = current;
    current = current->next;
  }
  return NULL;
}

void insert_at_sorted(Node*& head, int value) {
  Node* current = head;
  Node* prev = NULL;
  Node* new_node = new Node(value);

  if (head == NULL || head->data > value) {
    head->next = new_node;
    head = new_node;
    return;
  }

  while (current != NULL && current->data < value) {
    prev = current;
    current = current->next;
  }
  prev->next = new_node;
  new_node->next = current;
}

void display(Node* head) {
  if (head == NULL) return;
  while (head != NULL) {
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << "NULL\n";
}

int main() {
  Node* node = NULL;
  for (int i = 0; i <= 10; i++) insert_at_tail(node, i * 2);
  insert_at_tail(node, 20);
  remove_duplicates(node);
  insert_at_sorted(node, 21);
  display(node);
  cout << search_node(node, 4);

  // cout << check_sorted(node) << endl;
}