#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int value) {
    data = value;
    next = nullptr;
  }
};

void push(Node*& head, int value) {
  Node* new_node = new Node(value);
  new_node->next = head;
  head = new_node;
}

int pop(Node*& head) {
  if (head == nullptr) {
    cout << "Stack is Empty\n";
    return 0;
  }
  Node* current = head;
  head = head->next;
  int value = current->data;
  delete current;
  return value;
}

void display(Node* head) {
  if (head == nullptr) {
    cout << "Stack is Empty!\n";
    return;
  }
  while (head->next != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n";
}

int peek(Node* head, int position) {
  if (head == nullptr) {
    cout << "Stack is Empty\n";
    return 0;
  }
  Node* current = head;
  for (int i = 0; i < position - 1 && current->next != nullptr; i++) {
    current = current->next;
  }
  return current->data;
}

int top_element(Node* head) {
  if (head == nullptr) {
    cout << "The stack is empty\n";
    return 0;
  }
  return head->data;
}

int main() {
  Node* stack = nullptr;
  push(stack, 10);
  push(stack, 20);
  push(stack, 30);
  push(stack, 40);
  push(stack, 50);

  cout << "Displaying the Stack: \n";
  display(stack);

  cout << "Display the Popping Function\n";
  cout << pop(stack) << "\n";

  cout << "Checking The Peek Function\n";
  cout << peek(stack, 2) << endl;
  cout << top_element(stack) << endl;
}