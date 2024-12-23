#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class CircularLL {
 public:
  CircularLL() { head = nullptr; }

  void insert_at_head(int data) { _insert_at_head_(head, data); }
  void insert_at_tail(int data) { insert_at_tail_(head, data); }
  void insert_at_position(int data, int pos) {
    insert_at_position_(head, data, pos);
  }
  void display() { display_(head); }
  void delete_head() { delete_head_(head); }
  void delete_at_position(int pos) { delete_at_position_(head, pos); }

 private:
  Node* head;
  void _insert_at_head_(Node*& head, int data) {
    Node* newnode = new Node(data);
    if (head == nullptr) {
      head = newnode;
      head->next = head;
      return;
    }

    Node* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
  }

  void insert_at_tail_(Node*& head, int data) {
    Node* newnode = new Node(data);
    if (head == nullptr) {
      head = newnode;
      head->next = head;
      return;
    }

    Node* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
  }

  void insert_at_position_(Node*& head, int data, int pos) {
    if (pos <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (pos == 1) {
      _insert_at_head_(head, data);
      return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
      temp = temp->next;
    }
    Node* newnode = new Node(data);
    newnode->next = temp->next;
    temp->next = newnode;
  }

  void delete_head_(Node*& head) {
    if (head == nullptr) {
      cout << "List is empty" << endl;
      return;
    }
    if (head->next == head) {  // Single node case
      delete head;
      head = nullptr;
      return;
    }

    Node* temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    Node* temp_head = head;
    head = head->next;
    temp->next = head;
    delete temp_head;
  }

  void delete_at_position_(Node*& head, int pos) {
    if (pos <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (pos == 1) {
      delete_head_(head);
      return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
      temp = temp->next;
    }
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
  }

  void display_(Node* head) {
    if (head == nullptr) {
      cout << "List is empty\n";
      return;
    }
    Node* temp = head;
    do {
      cout << temp->data << " ";
      temp = temp->next;
    } while (temp != head);
    cout << endl;
  }
};
