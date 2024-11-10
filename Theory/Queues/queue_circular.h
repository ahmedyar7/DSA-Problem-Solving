#ifndef QUEUE_CIRCULAR_H
#define QUEUE_CIRCULAR_H

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

  void enqueue(int value) {
    // code
  }

  int dequeue() {
    // code
  }

  int get_front() {
    // code
  }

  void display() {
    // code
  }
}

#endif  // QUEUE_CIRCULAR_H