#ifndef CIRCULAR_LL_H
#define CIRCULAR_LL_H

#include <iostream>
using namespace std;

class Node_ {
 private:
 public:
  int data;
  Node_* next;

  Node_(int data) {
    this->data = data;
    next = nullptr;
  }
};

class CircularLinkedList {
 private:
 public:
  Node_* head;
  CircularLinkedList() { head = nullptr; }

  void insert_at_head(int value) {
    Node_* new_Node_ = new Node_(value);
    if (head == nullptr) {
      head = new_Node_;
      new_Node_->next = head;
      return;
    }
    Node_* temp = head;

    while (temp != head);
    temp = temp->next;

    temp->next = new_Node_;
    new_Node_->next = head;
    head = new_Node_;
    return;
  }

  void display() {
    if (head == nullptr) {
      cout << "The Circular Linked List is empty\n";
      return;
    }
    Node_* temp = head;
    do {
      cout << "[" << temp->data << "] ->";
      temp = temp->next;
    } while (temp != head);

    cout << "(" << temp->data << ") HEAD" << endl;
  }

  void insert_at_tail(int value) {
    Node_* new_node = new Node_(value);

    if (head == nullptr) {
      head = new_node;
      new_node->next = head;
      return;
    }

    Node_* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    return;
  }

  void insert_at_position(int value, int position) {
    Node_* new_node = new Node_(value);
    if (position <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (position == 1) {
      insert_at_head(value);
      return;
    }
    Node_* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return;
  }

  void delete_head() {
    if (head == nullptr) {
      cout << "Circular Linked List is empty\n";
      return;
    }
    if (head->next == head) {
      delete head;
      head = nullptr;
    }
    Node_* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = head->next;
    Node_* to_delete = head;
    head = head->next;
    return;
  }

  void delete_position(int position) {
    if (position <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (position == 1) {
      delete_head();
      return;
    }
    Node_* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
      temp = temp->next;
    }
    Node_* to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
  }
};

#endif  // CIRCULAR_LL_H