#include <iostream>
using namespace std;

class CircularQueue {
 private:
  int *queue;
  int front, rear, capacity;

 public:
  CircularQueue(int capacity) {
    this->capacity = capacity;
    queue = new int[capacity];
    front = rear = -1;
  }

  // Check if the queue is full
  bool isFull() { return (front == (rear + 1) % capacity); }

  // Check if the queue is empty
  bool isEmpty() { return (front == -1); }

  // Enqueue operation
  void enqueue(int value) {
    if (isFull()) {
      cout << "Queue is full! Cannot enqueue " << value << endl;
      return;
    }
    if (isEmpty()) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % capacity;
    }
    queue[rear] = value;
    cout << "Enqueued " << value << endl;
  }

  // Dequeue operation
  int dequeue() {
    if (isEmpty()) {
      cout << "Queue is empty! Cannot dequeue" << endl;
      return -1;
    }
    int result = queue[front];
    if (front == rear) {  // Queue becomes empty after this dequeue
      front = rear = -1;
    } else {
      front = (front + 1) % capacity;
    }
    cout << "Dequeued " << result << endl;
    return result;
  }

  // Peek operation to see the front element
  int peek() {
    if (isEmpty()) {
      cout << "Queue is empty! Cannot peek" << endl;
      return -1;
    }
    return queue[front];
  }

  // Display the queue
  void displayQueue() {
    if (isEmpty()) {
      cout << "Queue is empty!" << endl;
      return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
      cout << queue[i] << " ";
      if (i == rear) break;
      i = (i + 1) % capacity;
    }
    cout << endl;
  }

  // Destructor to free memory
  ~CircularQueue() { delete[] queue; }
};

int main() {
  CircularQueue q(5);  // Initialize queue with a capacity of 5

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);

  q.displayQueue();

  q.dequeue();
  q.dequeue();

  q.displayQueue();

  q.enqueue(60);
  q.enqueue(70);

  q.displayQueue();

  return 0;
}
