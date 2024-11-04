#include <iostream>
using namespace std;

class PriorityQueue {
 private:
  int *arr;   // Dynamic array to hold elements
  int size;   // Maximum size of the queue
  int front;  // Front index of the queue
  int rear;   // Rear index of the queue

 public:
  // Constructor to initialize queue with a given size
  PriorityQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    arr = new int[size];
  }

  // Destructor to free up allocated memory
  ~PriorityQueue() { delete[] arr; }

  // Check if the queue is full
  bool full() const { return rear == size - 1; }

  // Check if the queue is empty
  bool empty() const { return front == -1; }

  // Enqueue with priority: inserts in sorted order
  void enqueue(int value) {
    if (full()) {
      cout << "Queue is full\n";
      return;
    }

    // If queue is empty, initialize front and rear
    if (empty()) {
      front = rear = 0;
      arr[rear] = value;
      return;
    }

    // Find the position for the new element
    int i = rear;
    while (i >= front && arr[i] < value) {
      arr[i + 1] = arr[i];  // Shift elements to the right
      i--;
    }

    // Insert the new element
    arr[i + 1] = value;
    rear++;  // Update the rear index
  }

  // Dequeue the highest-priority element
  int dequeue() {
    if (empty()) {
      cout << "The Queue is empty\n";
      return -1;
    }

    // Get the front element (highest priority)
    int value = arr[front];
    front++;  // Move front to the next element

    // Reset front and rear if the queue is now empty
    if (front > rear) {
      front = rear = -1;
    }

    return value;
  }

  // Get the front (highest-priority) element without removing it
  int get_front() const {
    if (empty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    return arr[front];
  }

  // Display all elements in the priority queue
  void display() const {
    if (empty()) {
      cout << "Queue is empty\n";
      return;
    }

    cout << "Priority Queue: ";
    for (int i = front; i <= rear; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  PriorityQueue pq(5);

  pq.enqueue(5);
  pq.enqueue(10);
  //   pq.enqueue(20);
  //   pq.enqueue(3);

  pq.display();  // Should display elements in priority order: 15 10 7 5

  //   cout << "Dequeued element: " << pq.dequeue() << endl;
  //   pq.display();  // Should display remaining elements: 10 7 5

  return 0;
}
