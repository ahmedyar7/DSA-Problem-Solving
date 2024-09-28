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

  ~Node() {}

  void push(Node*& head, int value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
      head = new_node;
      return;
    }
    Node* temp = head;
    while (temp->next != next) {
      temp = temp->next;
    }
    temp->next = new_node;
    return;
  }

  int pop(Node*& head) {
    if (head == nullptr) {
      cout << "empty list\n";
      return 0;
    }
    Node* temp = head;
    int value = temp->data;
    head = head->next;
    delete temp;

    cout << value << " \n";
  }

  int peek(Node* head, int position) {
    if (head == nullptr) {
      cout << "Empty List\n";
      return 0;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
      temp = temp->next;
    }
    cout << temp->data << " \n";
  }

  void display(Node* head) {
    if (head == nullptr) {
      cout << "Empty Stack\n";
      return;
    }
    while (head != nullptr) {
      cout << head->data << " ";
      head = head->next;
    }
    cout << "NULL\n";
  }
};

int main() {
  Node* head = nullptr;
  Node stack(0);

  stack.push(head, 10);
  stack.push(head, 20);
  stack.push(head, 30);
  stack.push(head, 40);
  stack.push(head, 50);

  stack.display(head);

  stack.pop(head);
  stack.pop(head);

  stack.display(head);
}
