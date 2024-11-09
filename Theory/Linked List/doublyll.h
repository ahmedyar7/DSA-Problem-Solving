#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H
#include <iostream>
using namespace std;

class node {
 public:
  int data;
  node* next;
  node* prev;

  node(int data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }
};

class Doublyll {
 private:
 public:
  node* head;

  Doublyll() { head = nullptr; }

  void insert_at_head(int value) {
    node* new_node = new node(value);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    return;
  }

  void insert_at_tail(int value) {
    node* new_node = new node(value);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    return;
  }

  void display() {
    if (head == nullptr) {
      cout << "Doubly Linked List is emptn\n";
      return;
    }
    node* temp = head;
    while (temp->next != nullptr) {
      cout << "[" << temp->data << "] <->";
      temp = temp->next;
    }
    cout << "end\n";
  }

  void insert_at_position(int value, int position) {
    if (position <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (position == 1) {
      insert_at_head(value);
      return;
    }
  }
};

#endif  // DOUBLY_LL_H
