#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class Stack {
 private:
  Node* top_element;

 public:
  Stack() { top_element = nullptr; }

  bool empty() { return top_element == nullptr; }

  void push(int value) {
    Node* new_node = new Node(value);
    new_node->next = top_element;
    top_element = new_node;
  }

  int pop() {
    if (empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    Node* temp = top_element;
    int value = temp->data;
    top_element = top_element->next;
    delete temp;
    return value;
  }

  int top() {
    if (empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    return top_element->data;
  }
};

class Queue {
 private:
  Stack* st1;
  Stack* st2;

 public:
  Queue() {
    st1 = new Stack();
    st2 = new Stack();
  }

  void enqueue(int value) { st1->push(value); }

  int dequeue() {
    if (st1->empty() && st2->empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    if (st2->empty()) {
      while (!st1->empty()) {
        st2->push(st1->pop());
      }
    }
    return st2->pop();
  }

  int front() {
    if (st1->empty() && st2->empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    if (st2->empty()) {
      while (!st1->empty()) {
        st2->push(st1->pop());
      }
    }
    return st2->top();
  }

  ~Queue() { delete st1, st2; }
};

int main() {
  Queue q;

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
}
