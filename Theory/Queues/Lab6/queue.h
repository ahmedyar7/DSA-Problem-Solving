#ifndef QUEUE_H
#define QUEUE_h
#include <iostream>
using namespace std;
template <class T>
class Queue {
 private:
  int front;
  int rear;
  T *arr;
  int size;

 public:
  Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    arr = new T[size];
  }

  bool full() { return (rear == size - 1); }
  bool empty() { return front == rear; }

  void enqueue(T value) {
    if (full()) {
      cout << "Queue is full\n";
      return;
    }
    if (front == -1 && rear == -1) {
      front = 0;
      rear = 0;
    } else {
      rear++;
    }
    arr[rear] = value;
    return;
  }

  T dequeue() {
    if (empty()) {
      cout << "The Queue is empty\n";
      return T();
    }
    T value = arr[front];
    front++;
    if (front > rear) {
      front = -1;
      rear = -1;
    }
    return value;
  }

  T first_element() {
    if (empty()) {
      cout << "Queue is empty\n";
      return T();
    } else {
      return arr[front];
    }
  }

  void display() {
    if (empty()) {
      cout << "Queue is empty\n";
      return;
    }
    for (int i = front; i <= rear; i++) {
      cout << "[" << arr[i] << "] -> ";
    }
    cout << "ENDQUEUE\n";
    return;
  }

  ~Queue() { delete[] arr; }
};
#endif
