#include <iostream>
using namespace std;

class CircularQueue {
 private:
  int *arr;
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
      cout << "Queue is full\n";
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
    } else {
      front = (front + 1) % size;
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
    int i = front;
    while (true) {
      cout << arr[i] << " ";
      if (i == rear) {
        break;
      }
      i = (i + 1) % size;
    }
    cout << endl;
  }
};

int main() {
  CircularQueue cq(5);

  cq.push(10);
  cq.push(20);
  cq.push(30);
  cq.display();  // Output: 10 20 30

  std::cout << "Front: " << cq.top() << std::endl;  // Output: Front: 10

  std::cout << "Popped: " << cq.pop() << std::endl;  // Output: Popped: 10
  cq.display();                                      // Output: 20 30

  cq.push(40);
  cq.push(50);
  cq.display();  // Output: 20 30 40 50

  std::cout << "Front: " << cq.top() << std::endl;  // Output: Front: 20

  cq.push(60);   // Queue is full
  cq.display();  // Output: 20 30 40 50

  return 0;
}