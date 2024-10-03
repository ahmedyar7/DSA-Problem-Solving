#include <iostream>
using namespace std;

class Node {
 private:
 public:
  int data;
  Node* next;
  Node* prev;

  Node(int value) {
    data = value;
    next = nullptr;
    prev = nullptr;
  }
  ~Node() { delete next, prev; }

  void insert_at_tail(Node*& head, int value) {
    Node* new_node = new Node(value);

    if (head == nullptr) {
      head = new_node;
      new_node->next = new_node;
      new_node->prev = new_node;
      return;
    }

    Node* last = head->prev;
    Node* temp = head;

    last->next = new_node;
    new_node->prev = last;
    new_node->next = head;
    head->prev = new_node;
    return;
  }

  Node* insert_at_head(Node*& head, int value) {
    Node* new_node = new Node(value);

    if (head == nullptr) {
      head = new_node;
      new_node->next = new_node;
      new_node->prev = new_node;
    }

    Node* temp = head;
    Node* last = head->prev;

    new_node->next = head;
    head->prev = new_node;
    new_node->prev = last;
    last->next = new_node;

    head = new_node;
  }

  void insert_at_position(Node*& head, int value, int pos) {
    if (head == nullptr || pos <= 0) return;
    if (pos == 1) {
      insert_at_head(head, value);
      return;
    }

    Node* new_node = new Node(value);

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    temp->next->next->prev = new_node;
  }

  void delete_head(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    Node* last = head->prev;
    last->next = head->next;
    head->next->prev = last;
    head = head->next;
  }

  void delete_at_position(Node*& head, int pos) {
    if (head == nullptr || pos <= 0) return;
    if (pos == 1) {
      delete_head(head);
      return;
    }

    Node* temp = head;
    for (int i = 1; i < pos && temp->next != nullptr; i++) {
      temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
  }

  void display(Node* head) {
    Node* temp = head;
    do {
      cout << temp->data << " <-> ";
      temp = temp->next;
    } while (temp != head);
    cout << "HEAD\n";
  }
};

int main() {
  Node* head = nullptr;
  Node cll(0);

  for (int i = 0; i < 5; i++) {
    cll.insert_at_tail(head, i);
  }
  cll.display(head);

  for (int i = 5; i < 10; i++) cll.insert_at_head(head, i);

  cll.insert_at_position(head, 33, 5);
  cll.display(head);

  cll.delete_head(head);
  cll.display(head);
  cll.delete_at_position(head, 3);
  cll.display(head);
}