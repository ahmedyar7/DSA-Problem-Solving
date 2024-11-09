#ifndef NODE_H
#define NODE_H

#include <climits>
#include <iostream>
using namespace std;

class Node {
 private:
 public:
  int data;
  Node* next;
  Node* head = nullptr;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class LinkedList {
 private:
 public:
  Node* head;
  LinkedList() { head = nullptr; }

  void insert_at_head(int value) {
    Node* new_node = new Node(value);

    if (head == nullptr) {
      head = new_node;
      return;
    }
    new_node->next = head;
    head = new_node;
  }

  void insert_at_tail(int value) {
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

  void insert_at_position(int value, int position) {
    Node* new_node = new Node(value);

    if (position <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (position == 1) {
      insert_at_head(value);
      return;
    }
    Node* temp = head;
    for (int i = 1; i < (position && temp->next != nullptr); i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return;
  }

  void display() {
    if (head == nullptr) {
      cout << "Linked List is empty\n";
      return;
    }
    Node* temp = head;
    while (temp != nullptr) {
      cout << "[" << temp->data << "]-> ";
      temp = temp->next;
    }
    cout << "nullptr\n";
  }

  int delete_at_head() {
    if (head == nullptr) {
      cout << "Linked List is empty\n";
      return -1;
    }
    Node* temp = head;
    int value = temp->data;
    head = head->next;
    delete temp;
    return value;
  }

  int delete_at_position(int position) {
    if (head == nullptr) {
      cout << "The Linked List is empty\n";
      return -1;
    }

    if (position <= 0) {
      cout << "Invalid Position\n";
      return -1;
    }

    if (position == 1) {
      delete_at_head();
      return -1;
    }

    Node* temp = head;
    for (int i = 0; i < (position - 1 && temp->next != nullptr); i++) {
      temp = temp->next;
    }
    temp->next = temp->next->next;
    return -1;
  }

  Node* reverse_nodes() {
    Node* p = head;
    Node* q = nullptr;
    Node* r = nullptr;

    while (p != nullptr) {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
    }
    head = q;
    return q;
  }

  Node* concatenation(LinkedList& otherlist) {
    if (head == nullptr) return otherlist.head;
    if (otherlist.head == nullptr) return head;

    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = otherlist.head;
    otherlist.head = nullptr;
    return head;
  }

  Node* merged_ll(LinkedList& otherlist) {
    if (head == nullptr) return otherlist.head;
    if (otherlist.head == nullptr) return head;

    Node* first = head;
    Node* second = otherlist.head;
    Node* third = nullptr;
    Node* last = nullptr;

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

  Node* find_middle_element() {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  Node* sorting() {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    Node* right = head;
    Node* left = find_middle_element()->next;
    find_middle_element()->next = nullptr;

    LinkedList left_list;
    LinkedList right_list;

    left_list.head = left;
    right_list.head = right;

    Node* sorted_left = left_list.sorting();
    Node* sorted_right = right_list.sorting();

    LinkedList sortedlist;
    sortedlist.head = sorted_left;
    sortedlist.head = sortedlist.merged_ll(right_list);
    return sortedlist.head;
  }

  bool searching(int value) {
    Node* temp = head;
    while (temp->next != nullptr) {
      if (temp->data == value) {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }

  void min_n_max() {
    if (head == nullptr) {
      return;
    }
    int min = INT_MAX;
    int max = INT_MIN;
    Node* temp = head;
    while (temp->next != nullptr) {
      if (temp->data < min) {
        min = temp->data;
      }
      if (temp->data > max) {
        max = temp->data;
      }
      temp = temp->next;
    }
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;

    return;
  }

  void count_nodes() {
    if (head == nullptr) {
      return;
    }
    int counter = 0;
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
      counter++;
    }
    cout << "Total Nodes: " << counter << endl;
  }
};

#endif
