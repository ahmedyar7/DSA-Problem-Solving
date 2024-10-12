#include <iostream>
using namespace std;

class Node {
 private:
 public:
  int data;
  Node* next;
  Node* prev;

  Node(int data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
  }
};

class Deque {
 private:
  Node* front;
  Node* rear;
  int size;

 public:
  Deque() {
    front = nullptr;
    rear = nullptr;
    size = 0;
  }

  bool empty() { return size == 0; }

  void front_insert(int value) {
    Node* new_node = new Node(value);
    if (empty()) {
      front = rear = new_node;
    } else {
      front->prev = new_node;
      new_node->next = front;
      new_node->prev = nullptr;
      front = front->prev;
    }
    size++;
  }

  void rear_insert(int value) {
    Node* new_node = new Node(value);
    if (empty()) {
      front = rear = new_node;
    } else {
      rear->next = new_node;
      new_node->prev = rear;
      new_node->next = nullptr;
      rear = rear->next;
    }
    size++;
  }

  int front_delete() {
    Node* temp = front;
    int value = temp->data;
    if (front == rear) {
      front = rear = nullptr;
    } else {
      front = front->next;
      front->prev = nullptr;
    }
    delete temp;
    size--;
    return value;
  }

  int rear_delete() {
    Node* temp = rear;
    int value = temp->data;
    if (front == rear) {
      front = rear = nullptr;
    } else {
      rear = rear->prev;
      rear->next = nullptr;
    }
    delete temp;
    size--;
    return value;
  }

  int get_front() { return front->data; }
  int get_rear() { return rear->data; }

  void display() {
    Node* temp = front;
    while (temp != nullptr) {
      cout << "[" << temp->data << "] <-> ";
      temp = temp->next;
    }
    cout << "NULLPTR\n";
  }
};

int main() {
  Deque dq;

  dq.rear_insert(10);

  dq.rear_insert(20);
  dq.front_insert(5);
  dq.display();  // Output: 5 10 20

  cout << "Front element: " << dq.get_front() << endl;  // Output: 5
  cout << "Rear element: " << dq.get_rear() << endl;    // Output: 20

  dq.front_delete();
  dq.display();  // Output: 10 20

  dq.rear_delete();
  dq.display();  // Output: 10

  dq.rear_delete();
  dq.display();  // Output: Deque is empty.

  return 0;
}