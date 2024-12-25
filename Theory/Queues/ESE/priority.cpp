#include <iostream>
using namespace std;

class PriorityQueue {
 private:
  int front;
  int rear;
  int size;
  int *arr;

 public:
  PriorityQueue(int size) {
    this->size = size;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  bool empty() { return front == -1; }
  bool full() { return rear == size - 1; }
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
      // Find correct position to insert based on priority
      int i = rear;
      while (i >= front && arr[i] < data) {
        arr[i + 1] = arr[i];
        i--;
      }
      arr[i + 1] = data;
      rear++;
    }
  }

  int pop() {
    if (empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    int data = arr[front];
    front++;
    if (front > rear) {
      front = rear = -1;  // Reset when queue is empty
    }
    return data;
  }

  int top() {
    if (empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    return arr[front];
  }

  void display() {
    for (int i = rear; i <= front; i++) {
      cout << arr[i] << " ";
    }
    cout << "Queue end\n";
  }
};

int main() {
  PriorityQueue pq(5);  // Create a priority queue with size 5

  // Insert elements into the priority queue
  pq.push(30);
  pq.push(20);
  pq.push(50);
  pq.push(10);
  pq.push(40);

  cout << "Priority Queue after inserting elements:\n";
  pq.display();  // Display elements in priority queue

  // Pop elements from the queue
  cout << "Popping elements from the queue:\n";
  cout << "Popped: " << pq.pop() << endl;
  cout << "Popped: " << pq.pop() << endl;
  cout << "Popped: " << pq.pop() << endl;

  cout << "Priority Queue after popping elements:\n";
  pq.display();  // Display remaining elements

  // Top element in the queue
  cout << "Top element: " << pq.top() << endl;

  return 0;
}