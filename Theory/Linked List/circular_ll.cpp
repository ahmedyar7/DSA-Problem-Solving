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

// . Insert at circular
void insert_at_tail(Node*& head, int value) {
  Node* new_node = new Node(value);
  if (head == NULL) {
    head = new_node;
    new_node->next = head;
    return;
  }

  Node* temp = head;
  while (temp->next != head) {
    temp = temp->next;
  }
  temp->next = new_node;
  new_node->next = head;
}

// . Printing the Head Node
void display(Node* head) {
  if (head == NULL) {
    return;
  }
  Node* temp = head;
  do {
    cout << temp->data << " -> ";
    temp = temp->next;
  } while (temp != head);
  cout << "HEAD\n";
}

// . Delete HEAD Node
void delete_head_node(Node*& head) {
  Node* p = head;
  while (p->next != head) p = p->next;
  p->next = head->next;
  delete head;
  head = p->next;
}

//. Delete Any Node;
void delete_any_node(Node*& head, int position) {
  if (position == 1) {
    delete_head_node(head);
    return;
  }
  Node* p = head;
  for (int i = 1; i < position - 1 && p->next != head; i++) {
    p = p->next;
  }
  Node* q = p->next;
  p->next = q->next;
  delete p;
}

int main() {
  Node* node = NULL;
  insert_at_tail(node, 1);
  insert_at_tail(node, 2);
  insert_at_tail(node, 3);
  insert_at_tail(node, 4);
  insert_at_tail(node, 5);
  delete_any_node(node, 1);
  // delete_head_node(node);

  display(node);
}