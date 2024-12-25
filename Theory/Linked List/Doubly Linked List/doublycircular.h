#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node* prev;

  Node(int data) {
    next = nullptr;
    prev = nullptr;
    this->data = data;
  }
};

class DoublyCircular {
 private:
  Node* head;

 public:
  DoublyCircular() { head = nullptr; }

  void insert_at_head(int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      head = new_node;
      head->next = head;
      head->prev = head;
    } else {
      Node* last = head->prev;
      new_node->next = head;
      new_node->prev = last;
      last->next =
          new_node;  // Fix: Update the last node's next to the new node
      head->prev = new_node;  // Fix: Update the old head's prev to the new node
      head = new_node;        // Move head to the new node
    }
  }

  void insert_at_tail(int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      head = new_node;
      head->next = head;
      head->prev = head;
    } else {
      Node* temp = head;

      while (temp->next != head) {
        temp = temp->next;
      }

      temp->next = new_node;
      new_node->prev = temp;
      new_node->next = head;
      head->prev = new_node;
    }
  }

  void insert_at_position(int position, int value) {
    if (position <= 0) {
      cout << "Invalid Postion\n";
      return;
    }
    if (position == 1) {
      insert_at_head(value);
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
      temp = temp->next;
    }
    Node* newnode = new Node(value);
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
  }

  void display() {
    if (head == nullptr) {
      cout << "List is empty\n";
      return;
    }

    Node* temp = head;
    do {
      cout << temp->data << " ";
      temp = temp->next;
    } while (temp != head);  // Corrected the condition to check temp != head

    cout << endl;
  }
};