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
      rear = front = new_node;
    } else {
      rear->next = new_node;
      rear = new_node;
      return;
    }
  }

  int dequeue() {
    if (empty()) {
      cout << "The Queue is empty\n";
      return -1;
    }
    int value = rear->data;
    rear = rear->next;
    return value;
  }

  void display() {
    Node* temp = front;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "end\n";
  }

  int peek() { return rear->data; }
};

int main() {
  Queue q;

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  q.display();

  q.dequeue();
  q.display();

  q.enqueue(40);
  q.display();

  cout << "Front element is: " << q.peek() << endl;

  return 0;
}
