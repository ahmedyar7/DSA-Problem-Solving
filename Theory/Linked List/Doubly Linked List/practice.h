#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node* prev;

  Node(int data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLinkedList {
 public:
  void insert_at_head(Node*& head, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    Node* temp = head;
    new_node->next = temp;
    temp->prev = new_node;
    head = new_node;
    return;
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

  void insert_at_position(Node*& head, int value, int position) {
    if (position <= 0) {
      cout << "Invalid Postion\n";
      return;
    }
    if (position == 1) {
      insert_at_head(head, value);
      return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; i++)
      temp = temp->next;
    Node* new_node = new Node(value);
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;
    new_node->prev = temp;
    return;
  }

  void display(Node* head) {
    if (head == nullptr) {
      cout << "The Linked List is empty\n";
      return;
    }
    Node* temp = head;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "endlist\n";
  }

  void delete_head(Node*& head) {
    if (head == nullptr) {
      cout << "The list is empty\n";
      return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  void delete_at_position(Node*& head, int position) {
    if (position <= 0) {
      cout << "Invalid Postiont\n";
      return;
    }
    if (position == 1) {
      delete_head(head);
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    Node* to_del = temp->next;
    temp->next = temp->next->next;
    temp->next->next->prev = temp;
  }
};