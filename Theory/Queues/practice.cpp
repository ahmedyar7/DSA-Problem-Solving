#include <iostream>
using namespace std;

class Queue {
 private:
 public:
  int size;
  int front;
  int rear;
  int* arr;

  Queue(int cap) {
    size = cap;
    front = -1;
    rear = -1;
    arr = new int[size];
  }

  ~Queue() { delete[] arr; }

  bool is_full() {
    if (rear == size - 1) return true;
    return false;
  }

  bool is_empty() {
    if (front == rear) return true;
    return false;
  }

  void enqueue(int value) {
    if (is_full()) {
      return;
    }
    if (front == -1) front = 0;
    rear++;
    arr[rear] = value;
  }

  int dequeue() {
    if (is_empty()) return -1;
    int value = arr[front];
    front++;
    if (front > rear) front = rear = -1;
    return value;
  }

  void display() {
    for (int i = front; i <= rear; i++) {
      cout << arr[i] << " - ";
    }
    cout << "QUEUE-END\n";
  }
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
