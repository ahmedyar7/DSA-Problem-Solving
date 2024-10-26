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

  Node* sort_ll(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    Node* middle = find_middle_element(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = nullptr;

    left = sort_ll(left);
    right = sort_ll(right);

    return merged_linked_list(left, right);
  }

  Node* segregate_into_odd_even(Node*& head) {
    Node* odd = head;
    Node* even = head->next;
    Node* even_head = even;

    while (odd && odd->next) {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }
    odd->next = even_head;
    return head;
  }

  void remove_duplicate(Node*& head) {
    Node* prev = head;
    Node* current = prev->next;

    while (current != nullptr) {
      if (prev->data != current->data) {
        prev = current;
        current = current->next;
      } else {
        prev->next = current->next;
        delete current;
        current = prev->next;
      }
    }
  }

  bool is_looped(Node*& head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) return true;
    }
    return false;
  }

  void insert_at_position(Node*& head, int value, int pos) {
    Node* new_node = new Node(value);
    if (pos <= 0 || head == nullptr) {
      return;
    }
    if (pos == 1) {
      insert_at_head(head, value);
      return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }

  void delete_head(Node*& head) {
    if (head == nullptr) {
      return;
    }

    Node* temp = head;
    head = head->next;
  }

  void delete_at_position(Node*& head, int pos) {
    if (pos <= 0) {
      return;
    }
    if (pos == 1) delete_head(head);
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
      temp = temp->next;
    }
    temp->next = temp->next->next;
  }
};

#endif