#include <iostream>
using namespace std;

struct Element {
  string data;
  int priority;
};

class PriorityQueue {
 private:
  Element* arr;
  int front;
  int rear;
  int size;

 public:
  PriorityQueue(int size) {
    this->size = size;
    front = -1, rear = -1;
    arr = new Element[size];
  }

  bool full() const { return (rear == size - 1); }
  bool empty() const { return (front == -1); }

  void enqueue(string value, int priority) {
    if (full()) {
      cout << "Queue is full\n";
      return;
    }

    // If Queue is empty, initialize front & rear
    if (empty()) {
      front = 0;
      rear = 0;
      arr[rear].data = value;
      arr[rear].priority = priority;
      return;
    }

    // Find the correct position to insert new element based on priority
    int i = rear;
    while (i >= front && arr[i].priority < priority) {
      arr[i + 1] = arr[i];  // Shift elements to the right
      i--;
    }

    // Insert the new element at the correct position
    arr[i + 1].data = value;
    arr[i + 1].priority = priority;
    rear++;  // Update the rear index
  }

  string dequeue() {
    if (empty()) {
      cout << "Priority Queue is empty\n";
      return '\0';
    }
    string value = arr[front].data;
    front++;
    if (front > rear) {
      front = -1, rear = -1;
    }
    return value;
  }

  string get_front() {
    if (empty()) {
      cout << "Priority Queue is empty\n";
      return '\0';
    }
    return arr[front].data;
  }

  void display() {
    if (empty()) {
      cout << "Priority Queue is empty\n";
      return;
    }

    cout << "Elements: \n";
    for (int i = front; i <= rear; i++) {
      cout << "[" << arr[i].data << "] -> ";
    }
    cout << endl;
    cout << "Priorty " << endl;
    for (int i = front; i <= rear; i++) {
      cout << "[" << arr[i].priority << "] -> ";
    }

    cout << "END\n";
  }
};

int main() {
  PriorityQueue pq(5);

  pq.enqueue("Ahmed", 5);
  pq.enqueue("Yar", 1);
  pq.enqueue("Umar", 3);
  pq.enqueue("Malik", 4);
  pq.enqueue("Muhammad", 2);

  pq.display();
}