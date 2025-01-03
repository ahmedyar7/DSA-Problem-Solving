#include <iostream>
using namespace std;

class stack {
 private:
  int top;
  int size;
  int *arr;

 public:
  stack(int size) {
    this->size = size;
    top = -1;
    arr = new int[size];
  }

  bool full() { return top == size - 1; }

  bool empty() { return top == -1; }  // Corrected to return a value

  void push(int value) {
    if (full()) {
      cout << "Stack is full\n";
      return;
    }
    top++;
    arr[top] = value;
  }

  int pop() {
    if (empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    int value = arr[top];
    top--;
    return value;
  }

  int peek() {
    if (empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    return arr[top];
  }
};

class queue {
 private:
  stack *st1;
  stack *st2;

 public:
  queue(int size) {
    st1 = new stack(size);
    st2 = new stack(size);
  }

  void enqueue(int value) { st1->push(value); }

  int dequeue() {
    if (st1->empty() && st2->empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    while (!st1->empty()) {
      st2->push(st1->pop());
    }
    return st2->pop();
  }

  int front() {
    if (st1->empty() && st2->empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    while (!st1->empty()) {
      st2->push(st1->pop());
    }
    return st2->peek();
  }
};
