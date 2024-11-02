#include <iostream>
using namespace std;

template <class T>
class CircularQueue {
 private:
  int front;
  int rear;
  int size;
  T *arr;

 public:
  CircularQueue(int size) {
    front = -1;
    rear = -1;
    this->size = size;
    arr = new T[size];
  }

  bool empty() {
    if (front == -1)
      return true;
    else
      return false;
  }

  bool full() {
    if ((rear + 1) % size == front)
      return true;
    else
      return false;
  }

  void enqueue(T value) {
    if (full()) {
      cout << "Queue is empty\n";
      return;
    } else if (front == -1 && rear == -1) {
      front = 0, rear = 0;
    } else {
      rear = (rear + 1) % size;
    }
    arr[rear] = value;
    return;
  }

  T dequeue() {
    if (empty()) {
      cout << "Queue is empty\n";
      return T();
    } else if (empty()) {
      front = -1, rear = -1;

    } else {
      front = (front + 1) % size;
    }
    return arr[front];
  }

  T front_element() {
    if (empty()) {
      cout << "Queue is empty\n";
      return T();
    } else {
      return arr[front];
    }
  }

  void display() {
    if (empty()) {
      cout << "Queue is Empty\n";
      return;
    }
    int i = front;
    while (true) {
      cout << "[" << arr[i] << "]-> ";
      if (i == rear) break;
      i = (i + 1) % size;
    }
    cout << "ENDQUEUE\n";
  }

  ~CircularQueue() { delete[] arr; }
};

int main() {
  CircularQueue<int> q(5);  // Initialize queue with a size of 5

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);

  q.display();  // Display after initial enqueues

  q.dequeue();
  q.dequeue();

  q.display();  // Display after two dequeues

  q.enqueue(60);
  q.enqueue(70);

  q.display();  // Display after more enqueues

  return 0;
}
