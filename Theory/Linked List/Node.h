#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <class T>
class Node {
 private:
 public:
  T data;
  Node* next;

  Node(T data) {
    this->data = data;
    next = nullptr;
  }

  //. Insert at head
  void insert_at_head(Node*& head, T value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      new_node->next = new_node;
      head = new_node;
    }

    Node* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    head = new_node;
    return;
  }

  void insert_at_tail(Node*& head, T value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      new_node->next = new_node;
      head = new_node;
    }
    Node* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    return;
  }

  void insert_at_position(Node*& head, int pos, T value) {
    Node* new_node = new Node(value);
    if (pos <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (pos == 1) {
      insert_at_head(head, value);
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return;
  }

  void delete_head(Node*& head) {
    if (head == nullptr) {
      cout << "List is empty\n";
      return;
    }
    if (head->next == head) {
      delete head;
      head = nullptr;
    }
    Node* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    Node* old_head = head;
    temp->next = head->next;
    head = head->next;
    delete old_head;
  }

  void delete_at_position(Node*& head, int pos) {
    if (pos <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (pos == 1) {
      delete_head(head);
      return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
      temp = temp->next;
    }
    Node* to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
    return;
  }

  //. Display
  void display(Node* head) {
    if (head == nullptr) {
      cout << "The circular list is empty\n";
      return;
    }
    Node* temp = head;
    do {
      cout << "[" << temp->data << "] -> ";
      temp = temp->next;
    } while (temp != head);
    cout << "[" << temp->data << "]\n";
  }
};

#endif  // NODE_H