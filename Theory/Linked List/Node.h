#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <class T>
class Node {
 private:
  T data;
  Node* next;
  Node* prev;

 public:
  Node(T data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }

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
    new_node->prev = temp;
    return;
  }

  void insert_at_head(Node*& head, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  }

  void display(Node* head) {
    if (head == nullptr) {
      cout << "Doubly Linked List is empty\n";
      return;
    }

    while (head != nullptr) {
      cout << "[" << head->data << "] <-> ";
      head = head->next;
    }
    cout << "LISTEND\n";
  }

  void insert_at_position(Node*& head, int value, int pos) {
    Node* new_node = new Node(value);
    if (pos <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (pos == 1) {
      insert_at_head(head, value);
      return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;
    new_node->prev = temp;
    return;
  }

  T delete_at_head(Node*& head) {
    if (head == nullptr) {
      cout << "Doubly Linked List is empty\n";
      return T();
    }
    Node* temp = head;
    T value = temp->data;
    head = head->next;
    delete temp;
    return value;
  }

  T delete_at_position(Node* head, int pos) {
    if (pos <= 0) {
      cout << "Invalid Position\n";
      return T();
    }
    if (pos == 1) {
      delete_at_head(head);
      return T();
    }
    Node* temp = head;
    for (int i = 1; i < pos && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    return T();
  }

  void reverse_dll(Node*& head) {
    if (head == nullptr) {
      cout << "Doubly Linked List is empty\n";
      return;
    }
    Node* current = head;
    Node* temp = nullptr;
    while (current != nullptr) {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
    }
    if (temp != nullptr) {
      head = temp->prev;
    }
  }
};

#endif  // NODE_H