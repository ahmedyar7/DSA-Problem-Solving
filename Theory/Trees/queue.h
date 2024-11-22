#include <iostream>
using namespace std;

template <class T>
class Node {
 public:
  T data;
  Node* next;
  Node(T data) {
    this->data = data;
    next = nullptr;
  }
};

template <class T>
class Queue {
 private:
  Node<T>* rear;
  Node<T>* front;

 public:
  Queue() {
    front = nullptr;
    rear = nullptr;
  }

  bool empty() { return front == nullptr; }

  void enqueue(T value) {
    Node<T>* new_node = new Node<T>*(value);
    if (rear == nullptr && front == nullptr) {
      front = new_node;
      rear = new_node;
    }
  }

  ~Queue() {
    delete front;
    delete rear;
  }
};