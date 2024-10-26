#include <iostream>
using namespace std;

#ifndef NODE_H
#define NODE_h
class Node {
 public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }

  ~Node() { delete next; }

  void insert_at_head(Node*& head, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    new_node->next = head;
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
    return;
  }

  void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
      cout << "[" << temp->data << "] -> ";
      temp = temp->next;
    }
    cout << "NULL\n";
  }

  void max_n_min(Node* head) {
    Node* temp = head;
    int max = INT_MIN;
    int min = INT_MAX;
    while (temp != nullptr) {
      if (temp->data > max) {
        max = temp->data;
      } else if (temp->data < min) {
        min = temp->data;
      }
      temp = temp->next;
    }
    cout << "Maximum Value: " << max << endl;
    cout << "Minimum Value: " << min << endl;
  }

  void count_nodes(Node* head) {
    Node* temp = head;
    int counter = 0;

    while (temp != nullptr) {
      counter++;
      temp = temp->next;
    }
    cout << "Counter: " << counter << endl;
  }

  Node* reverse_nodes(Node*& head) {
    Node* p = head;
    Node* q = nullptr;
    Node* r = nullptr;

    while (p != nullptr) {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
    }
    return q;
  }

  bool search_node(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
      if (temp->data == value) {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }

  Node* concatenate_linked_list(Node*& head1, Node* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    Node* first = head1;
    Node* second = head2;

    while (first->next != nullptr) {
      first = first->next;
    }
    first->next = second;
    second = nullptr;
    return head1;
  }

  Node* merged_linked_list(Node*& head1, Node*& head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    Node* first = head1;
    Node* second = head2;
    Node* last = nullptr;
    Node* third = nullptr;

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

  Node* find_middle_element(Node* head) {}

  Node* sort_ll(Node*& head) {}
};

#endif