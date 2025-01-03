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
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
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
  }

  void insert_at_position(Node*& head, int value, int position) {
    if (position <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (position == 1) {
      insert_at_head(head, value);
      return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    Node* new_node = new Node(value);
    new_node->next = temp->next;
    if (temp->next != nullptr) {
      temp->next->prev = new_node;
    }
    temp->next = new_node;
    new_node->prev = temp;
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
    if (head != nullptr) {
      head->prev = nullptr;
    }
    delete temp;
  }

  void delete_at_position(Node*& head, int position) {
    if (position <= 0) {
      cout << "Invalid Position\n";
      return;
    }
    if (position == 1) {
      delete_head(head);
      return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    if (temp->next == nullptr) {
      cout << "Invalid position\n";
      return;
    }
    Node* to_del = temp->next;
    temp->next = temp->next->next;
    if (temp->next != nullptr) {
      temp->next->prev = temp;
    }
    delete to_del;
  }

  Node* concatenation(Node*& head1, Node*& head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    Node* temp = head1;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = head2;
    head2->prev = temp;
    return head1;
  }

  Node* merge_dll(Node*& head1, Node*& head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    Node* first = head1;
    Node* second = head2;
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
        first->prev = last;
        last = first;
        first = first->next;
      } else {
        last->next = second;
        second->prev = last;
        last = second;
        second = second->next;
      }
    }

    if (first != nullptr) {
      last->next = first;
      first->prev = last;
    } else if (second != nullptr) {
      last->next = second;
      second->prev = last;
    }

    return third;
  }

  Node* find_mid(Node* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  Node* sort(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    Node* mid = find_mid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;
    if (right != nullptr) {
      right->prev = nullptr;
    }

    left = sort(left);
    right = sort(right);

    return merge_dll(left, right);
  }
};