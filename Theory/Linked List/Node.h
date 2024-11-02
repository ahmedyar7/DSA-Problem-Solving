#ifndef NODE_H
#define NODE_h

#include <iostream>
using namespace std;

class Node {
 private:
  int data;
  Node* next;
  Node* prev;

 public:
  Node(int data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }

  void insert_at_head(Node*& head, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      new_node->next = new_node;
      new_node->prev = new_node;
      head = new_node;
      head = new_node;
      return;
    } else {
      Node* last = head->prev;
      last->next = new_node;
      new_node->next = head;
      new_node->prev = last;
      head = new_node;
      return;
    }
  }

  void insert_at_tail(Node*& head, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      new_node->next = new_node;
      new_node->prev = new_node;
      head = new_node;
      head = new_node;
      return;
    } else {
      Node* last = head->prev;
      last->next = new_node;
      new_node->prev = last;
      new_node->next = head;
      head->prev = new_node;
    }
  }

  void insert_at_position(Node*& head, int pos, int value) {
    if (pos <= 0) {
      cout << "Invalide Position\n";
      return;
    }
    if (pos == 1) {
      insert_at_head(head, value);
      return;
    }
  }

  void display(Node* head) {
    if (head == nullptr) {
      cout << "empty\n";
      return;
    }

    Node* temp = head;
    do {
      cout << "[" << temp->data << "] <-> ";
      temp = temp->next;
    } while (temp != head);

    // Print the head again to indicate that it's a circular list
    cout << "(back to HEAD [" << head->data << "])\n";
  }

  void delete_head(Node*& head) {
    // code
  }

  void delete_at_position(Node*& head, int pos) {
    // code
  }
};

#endif