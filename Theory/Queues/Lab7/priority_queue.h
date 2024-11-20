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

  bool full() { return (rear == size - 1); }
  bool empty() { return (rear == front); }

  void ARRIVE(string flight_id, int priority) {
    if (full()) {
      cout << "There is not Avaliable runway to land on!\n";
      return;
    } else if (front == -1 && rear == -1) {
      front = 0;
      rear = 0;
      arr[rear].flight_number = flight_id;
      arr[rear].priority = priority;
    } else {
      rear++;
    }

    int i = rear;
    while (i >= front && arr[i].priority < priority) {
      arr[i + 1] = arr[i];
      i--;
    }

    arr[i + 1].data = value;
    arr[i + 1].priority = priority;
    rear++;  // Update the rear index
  }

  void LAND() {
    if (empty()) {
      cout << "The Runway is empty!\n";
      return;
    } else {
      return arr[front];
    }
  }
};

#endif  // PRIORITY_QUEUE