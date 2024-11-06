#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include <iostream>
using namespace std;

struct Plane {
  string flight_number;
  int priority;
};

class Priority_Queue {
 private:
  Plane* arr;
  int front;
  int rear;
  int size;

 public:
  Priority_Queue(int size) {
    this->size = size;
    front = -1, rear = -1;
    arr = new Plane[size];
  }

  bool full() {
    // code
  }
  bool empty() {
    // code
  }

  void enqueue(string flight_id, int priority) {
    // code
  }

  void dequeue() {
    // code
  }
};

#endif  // PRIORITY_QUEUE