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

    Node* last = head->prev;
    last->next = new_node;
    new_node->next = head;
    head->prev = new_node;
    new_node->prev = last;
    head = new_node;

    return;
  }

  void insert_at_tail(Node*& head, int value) {
    Node* new_node = new Node(value);

    Node* last = head->prev;

    last->next = new_node;
    new_node->prev = last;
    new_node->next = head;
    head->prev = new_node;
  }

  void insert_at_position(Node*& head, int position, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr || position <= 0) {
      return;
    }

    if (position == 1) {
      insert_at_head(head, value);
      return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
      temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;
    new_node->prev = temp;
  }

  void delete_head(Node*& head) {
    if (head == nullptr) return;
    Node* last = head->prev;
    last->next = head->next;
    head->next->prev = last;
    head = head->next;
  }

  void delete_at_position(Node*& head, int position) {
    if (head == nullptr || position <= 0) {
      return;
    }

    if (position == 1) {
      delete_head(head);
      return;
    }

    Node* temp = head;
    for (int i = 1; i < position && temp->next != head; i++) {
      temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
  }

  void display(Node* head) {
    if (head == nullptr) return;
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
    cll.insert_at_head(head, i);
  }
  for (int i = 5; i < 10; i++) {
    cll.insert_at_tail(head, i);
  }
  cll.display(head);

  cout << "\n";

  cll.insert_at_position(head, 2, 333);
  cll.display(head);

  cout << "\n";

  cll.delete_head(head);
  cll.display(head);
  cout << "\n";

  cll.delete_at_position(head, 5);
  cll.display(head);
}