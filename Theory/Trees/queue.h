
#include <iostream>
using namespace std;

template <class T>
class QueueNode {
 public:
  T data;
  QueueNode* next;
  QueueNode(T data) {
    this->data = data;
    next = nullptr;
  }
};

template <class T>
class Queue {
 private:
  QueueNode<T>* rear;
  QueueNode<T>* front;

 public:
  Queue() {
    front = nullptr;
    rear = nullptr;
  }

  bool empty() { return front == nullptr; }

  void enqueue(T value) {
    QueueNode<T>* new_QueueNode = new QueueNode<T>*(value);
    if (rear == nullptr && front == nullptr) {
      front = new_QueueNode;
      rear = new_QueueNode;
    } else {
      rear->next = new_QueueNode;
      rear = new_QueueNode;
    }
    return;
  }

  T dequeue() {
    if (empty()) {
      return T();
    }
    QueueNode<T>* temp = front;
    T value = temp->data;
    front = front->next;
    delete temp;
    return value;
  }

  T get_front() {
    if (empty()) return T();
    return front->data;
  }

  ~Queue() {
    delete front;
    delete rear;
  }
};