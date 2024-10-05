#include <iostream>
using namespace std;

class Node {
 private:
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
      return;
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
    int result = front->data;
    front = front->next;
    delete temp;
    return result;
  }

  int first() {
    if (empty()) {
      return -1;
    }
    return front->data;
  }

  void display() {
    if (empty()) return;
    Node* current = front;
    while (current != nullptr) {
      cout << "[" << current->data << "] <-> ";
      current = current->next;
    }
    cout << "null\n";
  }

  ~Queue() {
    if (!empty()) {
      dequeue();
    }
  }
};

int main() {
  Queue q;

  q.enqueue(5);
  q.enqueue(15);
  q.enqueue(52);
  q.enqueue(53);
  q.enqueue(54);
  q.enqueue(525);

  q.display();

  q.dequeue();
  q.dequeue();
  q.dequeue();

  q.display();
}