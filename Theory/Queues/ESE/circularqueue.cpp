#include <iostream>
using namespace std;

class CircularQueue {
 private:
  int* arr;
  int front;
  int rear;
  int size;

 public:
  CircularQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    arr = new int[size];
  }

  bool full() { return (rear + 1) % size == front; }
  bool empty() { return front == -1; }

  void push(int data) {
    if (full()) {
      cout << "Queue is already full\n";
      return;
    }
    if (front == -1 && rear == -1) {
      front = 0;
      rear = 0;
      arr[rear] = data;
    } else {
      rear = (rear + 1) % size;
      arr[rear] = data;
    }
    return;
  }

  int pop() {
    if (empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    int value = arr[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } else
      front = (front + 1) % size;
    return value;
  }

  void display() {
    if (empty()) {
      cout << "Queue is empty\n";
      return;
    }
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
  CircularQueue queue(5);  // Create a queue of size 5

  queue.push(10);
  queue.push(20);
  queue.push(30);
  queue.push(40);
  queue.push(50);

  // Try pushing when the queue is full
  queue.push(60);  // Should display "Queue is already full"

  queue.display();  // Should display: 10 20 30 40 50

  cout << "Popped: " << queue.pop() << endl;  // Should display: Popped: 10
  cout << "Popped: " << queue.pop() << endl;  // Should display: Popped: 20

  queue.display();  // Should display: 30 40 50

  queue.push(60);
  queue.push(70);

  queue.display();  // Should display: 30 40 50 60 70

  while (!queue.empty()) {
    cout << "Popped: " << queue.pop() << endl;
  }

  queue.display();  // Should display "Queue is empty"

  return 0;
}
