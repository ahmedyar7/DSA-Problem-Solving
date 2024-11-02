#ifndef NODE_H
#define NODE_H
#include <climits>
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
      cout << "Doubly linked list is empty\n";
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

  void max_n_min(Node* head) {
    int max = INT_MIN;
    int min = INT_MAX;

    Node* temp = head;
    while (temp != nullptr) {
      if (temp->data < min) {
        min = temp->data;
      }
      if (temp->data > max) {
        max = temp->data;
      }
      temp = temp->next;
    }

    cout << "Maximum Element: " << max << endl;
    cout << "Minimum Element: " << min << endl;
  }

  Node* concatenation(Node*& head1, Node*& head2) {
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

  Node* merge_doubly_ll(Node*& head1, Node*& head2) {
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
        last = last->next;
        last = first;
        first = first->next;
      } else {
        last = last->next;
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

  Node* find_middle_element(Node* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    Node* fast = head->next;
    Node* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  Node* sort_dll(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    Node* left = head;
    Node* middle = find_middle_element(head);
    Node* right = middle->next;
    middle->next = nullptr;

    left = sort_dll(left);
    right = sort_dll(right);

    return merge_doubly_ll(left, right);
  }

  void remove_duplicates(Node*& head) {
    if (head == nullptr) {
      return;
    }

    Node* current = head;
    while (current != nullptr) {
      Node* temp = current->next;

      while (temp != nullptr) {
        if (current->data == temp->data) {
          Node* duplicated = temp;
          temp = temp->next;

          if (duplicated->prev) duplicated->prev->next = duplicated->next;
          if (duplicated->next) duplicated->next->prev = duplicated->prev;

          delete duplicated;
        } else {
          temp = temp->next;
        }
      }
      current = current->next;
    }
  }
};

#endif  // NODE_H