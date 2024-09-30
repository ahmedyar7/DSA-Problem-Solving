#include <iostream>
using namespace std;

class Node {
 private:
 public:
  int data;
  Node* next;

  Node(int value) {
    data = value;
    next = nullptr;
  }

  ~Node() { delete next; }

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
    if (head == nullptr) {
      cout << "List Is Empty\n";
      return;
    }
    while (head != nullptr) {
      cout << head->data << " -> ";
      head = head->next;
    }
    cout << "NULL\n";
  }

  Node* middle_element(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  Node* merge_2_sorted_list(Node*& node1, Node*& node2) {
    if (node1 == nullptr) return node2;
    if (node2 == nullptr) return node1;

    Node* first = node1;
    Node* second = node2;
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
    if (first == nullptr)
      last->next = second;
    else
      last->next = first;
    return third;
  }

  Node* sort_ll(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* middle = middle_element(head);
    Node* left_side = head;
    Node* right_side = middle->next;
    middle->next = nullptr;

    left_side = sort_ll(left_side);
    right_side = sort_ll(right_side);

    return merge_2_sorted_list(left_side, right_side);
  }
};

int main() {
  Node* head1 = nullptr;
  Node ll(0);

  ll.insert_at_tail(head1, 2);
  ll.insert_at_tail(head1, 4);
  ll.insert_at_tail(head1, 1);
  ll.insert_at_tail(head1, 6);
  ll.insert_at_tail(head1, 3);
  ll.insert_at_tail(head1, 8);
  ll.insert_at_tail(head1, 5);
  ll.insert_at_tail(head1, 10);

  Node* sorted_ll = ll.sort_ll(head1);
  ll.display(sorted_ll);
}