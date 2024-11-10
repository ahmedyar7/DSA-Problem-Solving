#ifndef QUEUE_CIRCULAR_H
#define QUEUE_CIRCULAR_H

#include <iostream>
using namespace std;

class CircularQueue {
 private:
  int front;
  int rear;
  int size;
  int *arr;

 public:
  CircularQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    arr = new int[size];
  }

  ~CircularQueue() { delete[] arr; }

  bool full() { return (front == (rear + 1) % size); }

  bool empty() { return front == -1; }

  void enqueue(int value) {
    if (full()) {
      cout << "QUeue is full\n";
      return;
    } else if (front == -1 && rear == -1) {
      front = 0;
      rear = 0;
    } else {
      rear = (rear + 1) % size;
    }
    arr[rear] = value;
    return;
  }

  int dequeue() {
    if (empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    int value = arr[front];
    front = (front + 1) % size;
    if (front == rear) {
      front = -1;
      rear = -1;
    }
    return value;
  }

  int get_front() { return arr[front]; }

  void display() {
    int i = front;
    while (true) {
      cout << arr[i] << " ";
      if (i == rear) break;
      i = (i + 1) % size;
    }
    cout << endl;
  }
};

#endif  // QUEUE_CIRCULAR_H