#include <iostream>
using namespace std;

class DoublyEndedQueue {
 private:
  int size;
  int front;
  int rear;
  int* arr;

 public:
  DoublyEndedQueue(int size) {
    this->size = size;
    front = -1;
    rear = 0;
    arr = new int[size];
  }

  bool full() { return (front == 0 && rear == size - 1); }
  bool empty() { return front == -1; }

  void insert_front(int value) {
    if (full()) {
      cout << "Queue is full\n";
      return;
    } else if (front == -1) {
      front = rear = 0;
    } else if (front == 0) {
      front = size - 1;
    } else {
      front = front - 1;
    }
    arr[front] = value;
    return;
  }

  void insert_rear(int value) {
    if (full()) {
      cout << "Queue is full\n";

      return;

    } else if (front == -1) {
      front = rear = 0;

    } else if (rear == size - 1) {
      rear = 0;

    } else {
      rear = rear + 1;
    }

    arr[rear] = value;
    return;
  }

  int delete_front() {
    if (empty()) {
      cout << "The queue is empty\n";
      return -1;
    }
    int value = arr[front];
    if (front == rear) {
      front = rear = -1;
    } else if (front == size - 1) {
      front = 0;
    } else {
      front = (front + 1);
    }
    return value;
  }

  int delete_rear() {
    if (empty()) {
      cout << "The Queue is empty\n";
      return -1;
    }
    int value = arr[rear];
    if (front == rear) {
      front = rear = -1;
    } else if (rear == 0) {
      rear = size - 1;
    } else {
      rear = rear - 1;
    }
    return value;
  }

  void display() {
    if (empty()) {
      cout << "Deque is empty." << endl;
      return;
    }
    int i = front;
    cout << "Deque elements: ";
    while (true) {
      cout << arr[i] << " ";
      if (i == rear) break;
      i = (i + 1) % size;
    }
    cout << endl;
  }

  ~DoublyEndedQueue() { delete[] arr; }
};

int main() {
  DoublyEndedQueue deque(5);

  // Inserting elements from both ends
  deque.insert_rear(10);
  deque.insert_rear(20);
  deque.insert_front(5);
  deque.insert_front(3);
  deque.display();  // Should print: 3 5 10 20

  // Deleting elements from both ends
  cout << "Deleted from front: " << deque.delete_front() << endl;
  cout << "Deleted from rear: " << deque.delete_rear() << endl;
  deque.display();  // Should print the updated deque contents

  return 0;
}