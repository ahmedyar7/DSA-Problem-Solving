#ifndef QUEUE_H
#define QUEUE_h

#include <iostream>
using namespace std;

template <class T>
class Queue {
 private:
  int front;
  int rear;
  int size;
  T* arr;

 public:
  Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    arr = new T[size];
  }

  bool full() { return (rear == size - 1); }

  bool empty() { return (front == -1); }

  void enqueue(T value) {
    if (full()) {
      cout << "Queue is full\n";
      return;
    } else if (front == -1 && rear == -1) {
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
      cout << "Queue is empty\n";
      return T();
    }
    int value = arr[front];
    front++;
    if (front > rear) {
      front = -1;
      rear = -1;
    }
    return value;
  }

  T get_front() {
    if (empty()) {
      cout << "Queue is empty\n";
      return T();
    }
    return arr[front];
  }

  void display() {
    if (empty()) {
      cout << "Queue is empty\n";
      return;
    }
    for (int i = front; i <= rear; i++) {
      cout << arr[i] << " ";
    }
    cout << "queueend\n";
  }
};

#endif
