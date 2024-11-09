#ifndef DOUBLYCIRCULARLL_H
#define DOUBLYCIRCULARLL_H
#include <iostream>
using namespace std;

class node_ {
 public:
  int data;
  node_* next;
  node_* prev;
  node_(int data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }
};

class doublycircularll {
 public:
  node_* head;
  doublycircularll() { head = nullptr; }

  void insert_at_head(int value) {
    node_* new_node = new node_(value);
    if (head == nullptr) {
      head = new_node;
      new_node->next = head;
      new_node->prev = head;
      return;
    }
    node_* temp = head;
    node_* last = head->prev;

    last->next = new_node;
    new_node->next = head;
    new_node->prev = last;
    head->prev = new_node;
    head = new_node;
    return;
  }

  void display() {
    if (head == nullptr) return;
    node_* temp = head;
    do {
      cout << "[" << temp->data << "] <-> ";
      temp = temp->next;
    } while (temp != head);
    cout << "[" << head->data << "] (back to head)" << endl;
  }

  void insert_at_tail(int value) {
    node_* new_node = new node_(value);
    if (head == nullptr) {
      head = new_node;
      new_node->next = head;
      new_node->prev = head;
      return;
    }
    node_* last = head->prev;
    last->next = new_node;
    new_node->prev = last;
    new_node->next = head;
    head->prev = new_node;
    last = new_node;
  }

  void insert_at_position(int value, int position) {
    if (position <= 0) {
      cout << "Invalid Postion\n";
      return;
    }
    if (position == 1) {
      insert_at_head(value);
      return;
    }
    node_* new_node = new node_(value);
    node_* temp = head;
    for (int i = 2; i <= position - 1 && temp->next != head; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;
    new_node->prev = temp;
    return;
  }

  void delete_head() {
    if (head == nullptr) {
      return;
    }
    node_* temp = head;
    node_* last = head->prev;
    last->next = head->next;
    head = head->next;
    head->prev = last;
    delete temp;
    return;
  }

  void delete_at_position(int position) {
    if (position <= 0) {
      cout << "Invalid position\n";
      return;
    }
    if (position == 1) {
      delete_head();
      return;
    }
    node_* temp = head;
    for (int i = 2; i <= position && temp->next != head; i++) {
      temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    return;
  }
};

#endif
