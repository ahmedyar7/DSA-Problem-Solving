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

  void insert_at_head(Node*& head, int value) {
    Node* new_node = new Node(value);

    if (head == nullptr) {
      head = new_node;
      new_node->next = new_node;
      new_node->prev = new_node;
      return;
    }

    Node* temp = head;
    Node* last = head->prev;

    new_node->next = head;
    head->prev = new_node;
    last->next = new_node;
    new_node->prev = last;

    head = new_node;
  }

  void insert_at_tail(Node*& head, int value) {
    Node* new_node = new Node(value);

    if (head == nullptr) {
      head = new_node;
      new_node->next = new_node;
      new_node->prev = new_node;
      return;
    }

    Node* temp = head;
    Node* last = head->prev;

    last->next = new_node;
    new_node->prev = last;
    new_node->next = head;
    head->prev = new_node;
  }

  void insert_at_position(Node*& head, int value, int pos) {
    if (head == nullptr || pos <= 0) return;
    if (pos == 1) {
      insert_at_head(head, value);
    }

    Node* new_node = new Node(value);
    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = new_node;
    new_node->next = temp->next->next;
  }

  void delete_at_head(Node*& head) {
    if (head == nullptr) {
      return;
    }

    Node* last = head->prev;
    Node* temp = head;

    last->next = head->next;
    head->next->prev = last;

    head = head->next;
    return;
  }

  void display(Node* head) {
    Node* temp = head;
    do {
      cout << temp->data << " <-> ";
      temp = temp->next;
    } while (temp != head);
    cout << "HEAD\n";
  }

  void delete_at_position(Node*& head, int pos) {
    if (head == nullptr || pos <= 0) return;
    Node* temp = head;
    for (int i = 1; i < pos && temp->next != head; i++) {
      temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
  }
};

int main() {
  Node* head = nullptr;
  Node cdll(0);

  cdll.insert_at_head(head, 10);
  cdll.insert_at_head(head, 20);
  cdll.insert_at_head(head, 30);

  cdll.insert_at_tail(head, 30);
  cdll.insert_at_tail(head, 40);
  cdll.insert_at_tail(head, 50);

  cdll.insert_at_position(head, 3, 3);

  cdll.display(head);

  cdll.delete_at_head(head);
  cdll.delete_at_position(head, 3);

  cdll.display(head);
}