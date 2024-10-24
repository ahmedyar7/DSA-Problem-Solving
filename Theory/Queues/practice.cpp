#include <iostream>
using namespace std;

class Queue {
 private:
  int size;
  int front;
  int rear;
  int *arr;

 public:
  Queue(int caps) {
    size = caps;
    front = -1;  // Correctly initialize front
    rear = -1;   // Correctly initialize rear
    arr = new int[size];
  }

  ~Queue() { delete[] arr; }

  bool is_full() {
    return (rear ==
            size - 1);  // The queue is full when rear reaches the last index
  }

  bool is_empty() {
    return (front == rear);  // Queue is empty when front equals rear
  }

  void enqueue(int value) {
    if (is_full()) {
      return;
    }
    rear++;
    arr[rear] = value;
    if (front == -1) {
      front = 0;
    }
  }

  int dequeue() {
    if (is_empty()) return -1;

    int value = arr[front];
    front++;
    if (front >= rear) {
      front = rear = -1;
    }
    return value;
  }

  void display() {
    if (is_empty()) {
      cout << "Queue is empty" << endl;
      return;
    }
    for (int i = front; i <= rear; i++) {
      cout << arr[i] << " - ";
    }
    cout << "END-QUEUE\n";
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
