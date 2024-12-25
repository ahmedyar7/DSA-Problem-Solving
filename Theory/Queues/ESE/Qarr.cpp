#include <iostream>
using namespace std;

class Queue {
 private:
  int front;
  int rear;
  int* arr;
  int size;

 public:
  Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    arr = new int[size];
  }

  bool full() { return rear == size - 1; }
  bool empty() { return front == -1; }

  void push(int data) {
    if (full()) {
      cout << "Queue is full\n";
      return;
    }
    if (front == -1 && rear == -1) {
      front = 0;
      rear = 0;
      arr[rear] = data;
    } else {
      arr[++rear] = data;
    }
    return;
  }

  int pop() {
    if (empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    int value = arr[++front];
    if (front > rear) {
      front = -1;
      rear = -1;
    }
    return value;
  }

  int top() {
    if (empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    return arr[front];
  }

  void display() {
    for (int i = front; i <= rear; i++) {
      cout << arr[i] << " ";
    }
    cout << "Queue end\n";
  }

  ~Queue() { delete[] arr; }
};

int main() {
  Queue q(5);  // Create a Queue of size 5

  // Testing push operation
  cout << "Pushing elements into the queue:\n";
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  // Display the current state of the queue
  cout << "Queue contents: ";
  q.display();

  // Attempt to push into a full queue
  cout << "Attempting to push into a full queue:\n";
  q.push(60);

  // Testing top operation
  cout << "Element at the front of the queue: " << q.top() << endl;

  // Testing pop operation
  cout << "Popping elements from the queue:\n";
  cout << "Popped: " << q.pop() << endl;
  cout << "Popped: " << q.pop() << endl;

  // Display the current state of the queue
  cout << "Queue contents after popping two elements: ";
  q.display();

  // Testing top operation after some pops
  cout << "Element at the front of the queue: " << q.top() << endl;

  // Testing pop until the queue is empty
  cout << "Emptying the queue:\n";
  while (!q.empty()) {
    cout << "Popped: " << q.pop() << endl;
  }

  // Attempt to pop from an empty queue
  cout << "Attempting to pop from an empty queue:\n";
  cout << "Popped: " << q.pop() << endl;

  return 0;
}
