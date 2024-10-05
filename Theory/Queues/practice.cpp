#include <iostream>
using namespace std;

class CircularQueue {
 private:
  int size;
  int front;
  int rear;
  int *queue;

 public:
  CircularQueue(int capacity) {
    size = capacity;
    front = rear = -1;
    queue = new int[size];
  }

  bool full() { return (front == (rear + 1) % size); }
  bool empty() { return (front == -1); }

  void enqueue(int value) {
    if (full()) return;
    if (empty()) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % size;
    }
    queue[rear] = value;
    return;
  }

  int dequeue() {
    if (empty()) return -1;
    int value = queue[front];
    if (full()) {
      front = (front + 1) % size;
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

  ~CircularQueue() { delete[] queue; }
};

int main() {
  CircularQueue q(5);  // Initialize queue with a capacity of 5

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);

  q.display();

  q.dequeue();
  q.dequeue();

  q.display();

  q.enqueue(60);
  q.enqueue(70);

  q.display();

  return 0;
}
