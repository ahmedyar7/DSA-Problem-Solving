#include <iostream>
using namespace std;

template <typename T>
class Node {
 public:
  T data;
  Node* next;

  Node(T data) {
    this->data = data;
    next = nullptr;
  }
};

template <typename T>
class Queue {
 private:
  Node<T>* front;
  Node<T>* rear;

 public:
  Queue() {
    front = nullptr;
    rear = nullptr;
  }

  bool empty() { return front == nullptr; }

  void push(T data) {
    Node<T>* newnode = new Node<T>(data);
    if (empty()) {
      front = newnode;
      rear = newnode;
    } else {
      rear->next = newnode;
      rear = newnode;
    }
    return;
  }

  T pop() {
    if (empty()) {
      cout << "Queue is empty\n";
      return T();
    }
    Node<T>* temp = front;
    T value = front->data;
    front = front->next;
    if (front == nullptr) {
      rear = nullptr;
    }
    delete temp;
    return value;
  }

  T peek() {
    if (empty()) {
      cout << "Queue is empty\n";
      return T();
    } else {
      return front->data;
    }
    return T();
  }

  ~Queue() {
    while (!empty()) {
      pop();
    }
  }
};