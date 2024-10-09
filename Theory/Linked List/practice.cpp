#include <iostream>
using namespace std;

class Node {
 private:
 public:
  int data;
  Node* next;
  Node* prev;

  Node(int data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }

  void insert_at_head(Node*& head, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      head = new_node;
      new_node->next = new_node;
      new_node->prev = new_node;
      return;
    }

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

    Node* last = head->prev;
    last->next = new_node;
    new_node->prev = last;
    new_node->next = head;
    head->prev = new_node;
  }

  void insert_at_position(Node*& head, int value, int pos) {
    Node* new_node = new Node(value);

    cout << "New node created\n";

    if (head == nullptr || pos <= 0) return;
    cout << "First if condition meet\n";

    if (pos == 1) {
      cout << "2nd if condition meet\n ";
      insert_at_head(head, value);
      return;
    }

    Node* temp = head;
    Node* last = head->prev;

    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
      temp = temp->next;
    }
    cout << "reached to desired node\n";
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    temp->next->next->prev = new_node;
    cout << "temp next points to newnode\n";
    cout << "newnnode next point to temp-.next next\n";
    cout << "newnode previous pointe the temp\n";
    cout << "final condition\n";

    return;
  }

  void delete_at_head(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    Node* last = head->prev;
    last->next = head->next;
    head = head->next;
    head->prev = last;

    delete temp;
  }

  void delete_at_position(Node*& head, int pos) {
    if (head == nullptr || pos <= 0) {
      return;
    }
    if (pos == 1) {
      delete_at_head(head);
      return;
    }
    Node* temp = head;
    for (int i = 1; i < pos && temp->next != head; i++) {
      temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
  }

  void display(Node* head) {
    Node* temp = head;
    do {
      cout << "[" << temp->data << "] <-> ";
      temp = temp->next;
    } while (temp != head);
    cout << "null\n";
  }
};

int main() {
  Node* head = nullptr;
  Node n(0);

  n.insert_at_head(head, 1);
  n.insert_at_head(head, 10);
  n.insert_at_head(head, 21);

  n.insert_at_tail(head, 23);
  n.insert_at_tail(head, 232);
  n.insert_at_tail(head, 2322);

  n.display(head);
  n.insert_at_position(head, 23, 3);
  n.display(head);
}