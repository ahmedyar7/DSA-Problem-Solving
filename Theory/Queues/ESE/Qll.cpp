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

class Queue {
 private:
  Node* front;
  Node* rear;

 public:
  Queue() {
    front == nullptr;
    rear == nullptr;
  }

  bool empty() { return front == nullptr; }

  void push(int data) {
    Node* newnode = new Node(data);
    if (empty()) {
      front = newnode;
      rear = newnode;
    } else {
      rear->next = newnode;
      rear = newnode;
    }
    return;
  }

  int pop() {
    if (empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    Node* temp = front;
    int value = front->data;
    front = front->next;
    delete temp;
    return value;
  }

  int top() {
    if (empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    return front->data;
  }

  void display() {
    if (empty()) {
      cout << "Queue is empty\n";
      return;
    }
    Node* temp = front;
    while (temp->next != nullptr) {
      cout << temp->next << " ";
      temp = temp->next;
    }
    cout << "end \n";
  }
};

int main() {
  Queue q;

  // Testing push operation
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);

  // Display the current state of the queue
  cout << "Queue contents: ";
  q.display();

  // Testing top operation
  cout << "Front element: " << q.top() << endl;

  // Testing pop operation
  cout << "Popped: " << q.pop() << endl;
  cout << "Popped: " << q.pop() << endl;

  // Display the current state of the queue
  cout << "Queue contents after popping two elements: ";
  q.display();

  // Testing pop until the queue is empty
  cout << "Emptying the queue:\n";
  while (!q.empty()) {
    cout << "Popped: " << q.pop() << endl;
  }

  // Attempt to pop from an empty queue
  cout << "Attempting to pop from an empty queue:\n";
  cout << "Popped: " << q.pop() << endl;

  return 0;
}