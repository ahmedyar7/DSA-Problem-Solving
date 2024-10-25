#include <iostream>
using namespace std;

class CircularQueue {
 private:
  int size;
  int front;
  int rear;
  int *arr;

 public:
  CircularQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    arr = new int[size];
  }

  bool empty() { return (front == -1); }
  bool full() { return (rear + 1) % size == front; }

  void enqueue(int value) {
    if (empty()) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % size;
    }
    arr[rear] = value;
  }

  int dequeue() {
    if (empty()) {
      return -1;
    }
    if (front == rear) {
      front = rear = -1;
    }
    int value = arr[front];
    front = (front + 1) % size;

    return value;
  }

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

int main() {
  CircularQueue q(5);  // Initialize queue with a size of 5

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);

  q.display();  // Display after initial enqueues

  q.dequeue();
  q.dequeue();

  q.dequeue();  // Display after two dequeues

  q.enqueue(60);
  q.enqueue(70);

  q.display();  // Display after more enqueues

  return 0;
}
