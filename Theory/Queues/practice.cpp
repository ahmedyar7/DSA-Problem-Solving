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
    front = nullptr;
    rear = nullptr;
  }

  bool empty() { return front == nullptr; }

  void enqueue(int value) {
    Node* new_node = new Node(value);
    if (rear == nullptr) {
      front = rear = new_node;
    } else {
      rear->next = new_node;
      rear = new_node;
    }
  }

  int dequeue() {
    if (empty()) {
      return -1;
    }
    Node* temp = front;
    int value = front->data;
    front = front->next;
    delete temp;
    return value;
  }

  int peek() {
    if (empty()) return -1;
    return front->data;
  }

  void display() {
    Node* temp = front;
    while (temp != nullptr) {
      cout << "[" << temp->data << "] -> ";
      temp = temp->next;
    }
    cout << "NULL\n";
  }

  ~Queue() { delete front, rear; }
};

int main() {
  Queue q;  // Create an empty queue

  q.enqueue(10);  // Insert 10
  q.enqueue(20);  // Insert 20
  q.enqueue(30);  // Insert 30

  q.display();  // Display the queue: 10 20 30

  q.dequeue();  // Remove front element (10)
  q.display();  // Display the queue: 20 30

  q.enqueue(40);  // Insert 40
  q.display();    // Display the queue: 20 30 40

  cout << "Front element is: " << q.peek() << endl;  // Peek at the front: 20

  return 0;
}
