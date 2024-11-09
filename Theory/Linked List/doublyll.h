#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H
#include <climits>
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
    while (temp != nullptr) {
      cout << "[" << temp->data << "] <->";
      temp = temp->next;
    }
    cout << "end\n";
  }

  void insert_at_position(int value, int position) {
    node* new_node = new node(value);
    if (position <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (position == 1) {
      insert_at_head(value);
      return;
    }
    node* temp = head;
    for (int i = 2; i <= position - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    // 1st binding
    new_node->next = temp->next;
    temp->next->prev = new_node;

    // 2nd binding
    temp->next = new_node;
    new_node->prev = temp;
    return;
  }

  void delete_head() {
    if (head == nullptr) {
      cout << "The Doubly Linked List is empty\n";
      return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
  }

  void delete_at_position(int position) {
    if (position <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (position == 1) {
      delete_head();
      return;
    }

    node* temp = head;
    for (int i = 2; i <= position && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    return;
  }

  void max_n_min() {
    int min = INT_MAX;
    int max = INT_MIN;

    node* temp = head;
    while (temp->next != nullptr) {
      if (temp->data > max) {
        max = temp->data;
      }
      if (temp->data < min) {
        min = temp->data;
      }
      temp = temp->next;
    }
    cout << "MIN: " << min << endl;
    cout << "MAX: " << max << endl;
  }

  void count_nodes() {
    int counter = 0;
    node* temp = head;
    while (temp->next != nullptr) {
      counter++;
      temp = temp->next;
    }
    cout << "TOTAL NODES: " << counter << endl;
  }

  node* find_middle_element() {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    node* slow = head;
    node* fast = slow->next;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  node* merging(Doublyll& otherlist) {
    if (head == nullptr) return otherlist.head;
    if (otherlist.head == nullptr) return head;

    node* first = head;
    node* second = otherlist.head;
    node* third = nullptr;
    node* last = nullptr;

    if (first->data < second->data) {
      third = last = first;
      first = first->next;
    } else {
      third = last = second;
      second = second->next;
    }

    while (first != nullptr && second != nullptr) {
      if (first->data < second->data) {
        last->next = first;
        last = first;
        first = first->next;
      } else {
        last->next = second;
        last = second;
        second = second->next;
      }
    }

    if (first == nullptr) {
      last->next = second;
    } else {
      last->next = first;
    }

    return third;
  }

  node* concatenation(Doublyll& otherlist) {
    if (head == nullptr) return otherlist.head;
    if (otherlist.head == nullptr) return head;

    node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = otherlist.head;
    otherlist.head = nullptr;
    return head;
  }
};

#endif  // DOUBLY_LL_H
