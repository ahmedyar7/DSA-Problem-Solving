#include <iostream>
using namespace std;

class CircularQueue {
 private:
  int* arr;
  int front, rear, size;

 public:
  // Constructor to initialize the queue
  CircularQueue(int size) {
    this->size = size;
    arr = new int[size];
    front = rear = -1;
  }

  // Check if the queue is full
  bool isFull() { return ((rear + 1) % size == front); }

  // Check if the queue is empty
  bool isEmpty() { return front == -1; }

  // Enqueue operation
  void enqueue(int value) {
    if (isFull()) {
      cout << "The Queue is full\n";
      return;
    }

    if (isEmpty()) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % size;
    }

    arr[rear] = value;
  }

  // Dequeue operation
  int dequeue() {
    if (isEmpty()) {
      cout << "The Queue is empty\n";
      return -1;
    }

    int value = arr[front];  // Store the dequeued value

    if (front == rear) {
      front = rear = -1;  // Reset the queue after the last element is removed
    } else {
      front = (front + 1) % size;  // Increment front and wrap around
    }

    return value;
  }

  // Peek operation to see the front element
  int peek() {
    if (isEmpty()) {
      cout << "Queue is empty\n";
      return -1;
    }
    return arr[front];
  }

  // Display the queue using a single loop
  void displayQueue() {
    if (isEmpty()) {
      cout << "Queue is empty\n";
      return;
    }

    cout << "Queue elements: ";

    int i = front;
    while (true) {
      cout << arr[i] << " ";  // Print the current element

      if (i == rear) {  // Stop when we reach the rear element
        break;
      }

      i = (i + 1) % size;  // Move to the next index, wrap around if needed
    }

    cout << endl;
  }

  // Destructor to free memory
  ~CircularQueue() { delete[] arr; }
};

int main() {
  CircularQueue q(5);  // Initialize queue with a size of 5

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);

  q.displayQueue();  // Display after initial enqueues

  q.dequeue();
  q.dequeue();

  q.displayQueue();  // Display after two dequeues

  q.enqueue(60);
  q.enqueue(70);

  q.displayQueue();  // Display after more enqueues

  return 0;
}
