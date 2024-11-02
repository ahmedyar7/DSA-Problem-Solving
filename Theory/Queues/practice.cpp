#include <iostream>
using namespace std;

class DEQueue {
 private:
  int front;
  int rear;
  int size;
  int *arr;

 public:
  // Constructor to initialize the deque
  DEQueue(int size) {
    this->size = size;
    front = -1, rear = -1;
    arr = new int[size];
  }

  // Destructor to release memory
  ~DEQueue() { delete[] arr; }

  // Check if deque is full
  bool full() {
    return (front == 0 && rear == size - 1) || (front == rear + 1);
  }

  // Check if deque is empty
  bool empty() { return front == -1; }

  // Insert element at the front
  void push_front(int value) {
    if (full()) {
      cout << "Dequeue is Full\n";
      return;
    }
    if (empty()) {
      front = 0;
      rear = 0;
    } else if (front == 0) {
      front = size - 1;
    } else {
      front = front - 1;
    }
    arr[front] = value;
  }

  // Insert element at the rear
  void push_rear(int value) {
    if (full()) {
      cout << "Dequeue is Full\n";
      return;
    }
    if (empty()) {
      front = 0;
      rear = 0;
    } else if (rear == size - 1) {
      rear = 0;
    } else {
      rear = (rear + 1) % size;
    }
    arr[rear] = value;
  }

  // Display elements in the deque
  void display() {
    if (empty()) {
      cout << "Doubly ended queue is empty\n";
      return;
    }
    int i = front;
    cout << "Deque elements: ";
    while (true) {
      cout << "[" << arr[i] << "] -> ";
      if (i == rear) break;
      i = (i + 1) % size;
    }
    cout << "QUEUE_END\n";
  }

  // Delete element from the front
  int delete_front() {
    if (empty()) {
      cout << "Doubly ended queue is empty\n";
      return -1;
    }
    int value = arr[front];
    if (front == rear) {  // Only one element left
      front = -1;
      rear = -1;
    } else if (front == size - 1) {  // Wrap around
      front = 0;
    } else {
      front = front + 1;
    }
    return value;
  }

  // Delete element from the rear
  int delete_rear() {
    if (empty()) {
      cout << "Doubly ended queue is empty\n";
      return -1;
    }
    int value = arr[rear];
    if (front == rear) {  // Only one element left
      front = -1;
      rear = -1;
    } else if (rear == 0) {  // Wrap around
      rear = size - 1;
    } else {
      rear = rear - 1;
    }
    return value;
  }
};

int main() {
  DEQueue q(5);

  q.push_front(5);
  q.push_front(10);
  q.push_front(15);

  q.display();

  cout << "Deleted from front: " << q.delete_front() << endl;

  q.push_rear(55);
  q.display();

  return 0;
}
