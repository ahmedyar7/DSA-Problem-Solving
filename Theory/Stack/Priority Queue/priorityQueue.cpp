#include <iostream>
#include <string>
using namespace std;

struct Element {
  string data;   // The string data
  int priority;  // Priority of the string
};

class PriorityQueue {
 private:
  Element* arr;  // Array of Element structs
  int size;      // Maximum size of the queue
  int front;     // Front pointer
  int rear;      // Rear pointer

 public:
  PriorityQueue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    arr = new Element[size];  // Dynamically allocate array
  }

  ~PriorityQueue() {
    delete[] arr;  // Free dynamically allocated memory
  }

  bool full() const { return rear == size - 1; }

  bool empty() const { return front == -1; }

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
      cout << "The Queue is empty\n";
      return "";
    }

    // Remove the front element
    string value = arr[front].data;
    front++;

    // Reset front and rear if the queue becomes empty
    if (front > rear) {
      front = -1;
      rear = -1;
    }

    return value;
  }

  void display() const {
    if (empty()) {
      cout << "The queue is empty\n";
      return;
    }
    for (int i = front; i <= rear; i++) {
      cout << "[" << arr[i].data << " (Priority: " << arr[i].priority
           << ")] -> ";
    }
    cout << "QUEUE_END\n";
  }
};

int main() {
  PriorityQueue pq(5);

  pq.enqueue("Low priority task", 1);
  pq.enqueue("Medium priority task", 5);
  pq.enqueue("High priority task", 10);
  pq.enqueue("Another low priority task", 2);

  pq.display();  // Expected output: [High priority task (Priority: 10)] ->
                 // [Medium priority task (Priority: 5)] -> ...

  cout << "Dequeue: " << pq.dequeue()
       << "\n";  // Should remove "High priority task"
  pq.display();

  return 0;
}
