#include <iostream>
using namespace std;

class Queue {
 private:
  int front;
  int rear;
  int size;
  int *queue;

 public:
  Queue(int capacity) {
    size = capacity;
    front = -1;
    rear = -1;
    queue = new int[size];
  }

  bool empty() {
    if (front == rear) return true;
    return false;
  }

  bool full() {
    if (rear == size - 1) return true;
    return false;
  }

  void enqueue(int value) {
    if (full()) {
      return;
    }
    rear++;
    queue[rear] = value;
    if (front == -1) {
      front = 0;
    }
    return;
  }

  int dequeue() {
    if (empty()) return -1;
    int value = queue[front];
    front++;
    if (front > rear) {
      front = rear = -1;
    }
    return value;
  }

  int peek() {
    if (empty()) {
      return -1;
    }
    return queue[front];
  }

  void display() {
    if (empty()) return;
    for (int i = front; i <= rear; i++) {
      cout << queue[i] << " ";
    }
    cout << "QUEUE_END\n";
  }

  ~Queue() { delete[] queue; }
};

int main() {
  Queue qu(5);

  qu.enqueue(2);
  qu.enqueue(3);
  qu.enqueue(4);
  qu.enqueue(5);
  qu.enqueue(6);

  qu.display();

  qu.dequeue();
  qu.display();
}
