#include <iostream>
using namespace std;

class CircularQueue {
 private:
 public:
  int front;
  int rear;
  int size;
  int* queue;
  CircularQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    queue = new int[size];
  }

  bool full() { return (front == (rear + 1) % size); }
  bool empty() { return front == -1; }

  void enqueue(int value) {
    if (full()) return;
    if (empty()) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % size;
    }
    queue[rear] = value;
  }

  int dequeue() {
    if (empty()) return -1;
    int value = queue[front];
    front = (front + 1) % size;
    if (front == rear) {
      front = rear = -1;
    }
    return value;
  }

  int peek() {
    if (empty()) return -1;
    return queue[front];
  }

  void display() {
    int i = front;
    while (true) {
      cout << queue[i] << " ";
      if (i == rear) break;
      i = (i + 1) % size;
    }
    cout << endl;
  }
};

int main() {
  CircularQueue cq(5);

  cq.enqueue(5);
  cq.enqueue(15);
  cq.enqueue(25);
  cq.enqueue(35);

  cq.display();

  cq.dequeue();
  cq.display();

  cq.enqueue(5);
  cq.enqueue(5);
  cq.enqueue(5);
  cq.enqueue(5);
  cq.enqueue(5);
  cq.display();
}