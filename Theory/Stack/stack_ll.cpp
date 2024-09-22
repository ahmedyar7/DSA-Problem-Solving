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

// This function also work when entering the first node
void push(Node*& top, int value) {
  Node* new_node = new Node(value);
  new_node->next = top;
  top = new_node;
  return;
}

int pop(Node*& top) {
  int x = -1;
  if (top == nullptr) {
    cout << "Stack is Empty!\n";
    return -1;  // Stack is empty
  }
  Node* p = top;
  top = top->next;
  x = p->data;
  delete p;
  return x;
}

int peek(Node* top, int position) {
  Node* p = top;
  for (int i = 1; i <= position && p != nullptr; i++) p = p->next;
  if (p != nullptr) return p->data;
  return -1;
}

int stack_top(Node* top) {
  if (top) return top->data;
  return -1;
}

int is_empty(Node* top) {
  if (top == nullptr) return 1;
  return 0;
}

void display(Node* top) {
  Node* p = top;
  while (p != nullptr) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << "\n";
}

int main() {
  Node* top = nullptr;

  // Push Element to stack
  push(top, 10);
  push(top, 20);
  push(top, 30);

  cout << "Stack Element\n";
  display(top);

  // Peek to top element
  cout << "Top Element: " << stack_top(top) << "\n";

  // Pop element
  cout << "Pop Element: " << pop(top) << "\n";

  display(top);
  cout << "Peek Element: " << peek(top, 0);
}
