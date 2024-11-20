#include <iostream>
using namespace std;

class PriorityQueue {
 private:
  int front;
  int rear;
  int size;
  int *arr;

 public:
  PriorityQueue(int size) {
    front = -1;
    rear = -1;
    this->size = size;
    arr = new int[size];
  }

  ~PriorityQueue() { delete[] arr; }

  bool empty() { return front == -1; }
  bool full() { return rear == size - 1; }

  void enqueue(int data) {
    if (full()) {
      cout << "Queue is full\n";
      return;
    }
    if (front == -1 && rear == -1) {
      front = 0;
      rear = 0;
      arr[rear] = data;
    }

    // sorting
    int i = rear;
    while (i >= front && arr[i] < data) {
      arr[i + 1] = arr[i];  // Shift elements to the right
      i--;
    }

    // Insert the new element at the correct position
    arr[i + 1] = data;
    rear++;  // Update the rear index
  }

  int dequeue() {
    if (empty()) {
      cout << "Prioroity Queue is empty\n";
      return -1;
    }
    int value = arr[front];
    front++;
    if (front > rear) {
      front = -1;
      rear = -1;
    }
    return value;
  }
};

int main() {
  PriorityQueue pq(5);
  pq.enqueue(10);
  pq.enqueue(30);
  pq.enqueue(20);
  pq.enqueue(40);
  pq.enqueue(50);

  cout << pq.dequeue() << endl;
}