// Practice quue using the grid structure// Practice qesuiotngit a

#include <iostream>
using namespace std;

class node {
 public:
  int data;
  node* next;
  node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class stack {
 private:
  node* top;

 public:
  stack() { top = nullptr; }

  bool empty() { return top == nullptr; }

  void push(int value) {
    node* new_node = new node(value);
    if (empty()) {
      top = new_node;
      return;
    }
    new_node->next = top;
    top = new_node;
    return;
  }

  int pop() {
    if (empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    node* temp = top;
    int value = temp->data;
    top = top->next;
    delete temp;
    return value;
  }

  int peek() {
    if (empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    return top->data;
  }
};

class queue {
 private:
  stack* st1;
  stack* st2;

 public:
  queue() {
    st1 = new stack();
    st2 = new stack();
  }

  void enqueue(int value) { st1->push(value); }

  int dequeue() {
    if (st1->empty() && st2->empty()) {
      cout << "stack is empty\n";
      return -1;
    }
    while (!st1->empty()) {
      st2->push(st1->pop());
    }
    return st2->pop();
  }

  int get_front() {
    if (st1->empty() && st2->empty()) {
      cout << "stack is empty\n";
      return -1;
    }
    while (!st1->empty()) {
      st2->push(st1->pop());
    }
    return st2->peek();
  }
};