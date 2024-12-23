#include <iostream>
using namespace std;

class PriorityQueue {
 private:
  int* arr;
  int size;
  int front;
  int rear;

 public:
  PriorityQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    arr = new int[size];
  }

  ~PriorityQueue() { delete[] arr; }

  bool full() { return rear == size - 1; }
  bool empty() { return front == -1; }
};