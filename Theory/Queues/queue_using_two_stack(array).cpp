#include <iostream>
using namespace std;

class Stack {
 public:
  int size;
  int top_element;
  int* arr;

  Stack(int size) {
    this->size = size;
    top_element = -1;
    arr = new int[size];
  }

  bool empty() { return top_element == -1; }
  bool full() { return (top_element == size - 1); }

  void push(int value) {
    if (full()) {
      cout << "Stack is full\n";
      return;
    }
    arr[++top_element] = value;
  }

  int pop() {
    if (empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    return arr[top_element--];
  }

  int top() {
    if (empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    return arr[top_element];
  }

  ~Stack() { delete[] arr; }
};

class Queue {
 private:
  Stack* st1;
  Stack* st2;

 public:
  Queue(int size) {
    st1 = new Stack(size);
    st2 = new Stack(size);
  }

  void enqueue(int value) { st1->push(value); }

  int dequeue() {
    if (st1->empty() && st2->empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    if (st2->empty()) {
      while (!st1->empty()) st2->push(st1->pop());
    }
    return st2->pop();
  }

  int front() {
    if (st1->empty() && st2->empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    if (st2->empty()) {
      while (!st1->empty()) st2->push(st1->pop());
    }
    return st2->top();
  }

  ~Queue() {
    delete st1;
    delete st2;
  }
};

int main() {
  Queue q(10);

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);

  cout << "Front element: " << q.front() << endl;  // Output: 1
  cout << "Dequeue: " << q.dequeue() << endl;      // Output: 1
  cout << "Dequeue: " << q.dequeue() << endl;      // Output: 2

  q.enqueue(4);
  cout << "Front element: " << q.front() << endl;  // Output: 3
  cout << "Dequeue: " << q.dequeue() << endl;      // Output: 3
  cout << "Dequeue: " << q.dequeue() << endl;      // Output: 4

  return 0;
}
