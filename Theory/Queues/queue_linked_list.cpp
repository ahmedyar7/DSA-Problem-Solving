#include <iostream>
using namespace std;

// Node structure
struct Node {
  int data;
  Node* next;
};

// Queue class with linked list implementation
class Queue {
 private:
  Node* front;
  Node* rear;

 public:
  Queue() {
    front = nullptr;  // Initialize an empty queue
    rear = nullptr;
  }

  // Check if the queue is empty
  bool empty() { return front == nullptr; }

  // Enqueue operation: Insert element at the rear of the queue
  void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (rear == nullptr) {
      // If the queue is empty, both front and rear will point to the new node
      front = rear = newNode;
    } else {
      // Add new node at the end of the queue and update rear
      rear->next = newNode;
      rear = newNode;
    }
    cout << "Enqueued: " << value << endl;
  }

  // Dequeue operation: Remove element from the front of the queue
  int dequeue() {
    if (empty()) {
      cout << "Queue is empty! Cannot dequeue." << endl;
      return -1;
    }

    Node* temp = front;       // Store the front node temporarily
    int result = temp->data;  // Retrieve the data to return later
    front = front->next;      // Move front to the next node

    // If front becomes nullptr, set rear to nullptr (queue is empty now)
    if (front == nullptr) {
      rear = nullptr;
    }

    delete temp;  // Free memory of the old front node
    cout << "Dequeued: " << result << endl;
    return result;
  }

  // Peek operation: View the element at the front of the queue
  int peek() {
    if (empty()) {
      cout << "Queue is empty!" << endl;
      return -1;
    }
    return front->data;  // Return the front data without removing it
  }

  // Display the entire queue
  void display() {
    if (empty()) {
      cout << "Queue is empty!" << endl;
      return;
    }
    Node* current = front;
    cout << "Queue: ";
    while (current != nullptr) {
      cout << "[" << current->data << "] -> ";
      current = current->next;
    }
    cout << "NULL\n";
  }

  // Destructor to free allocated memory
  ~Queue() {
    while (!empty()) {
      dequeue();  // Dequeue all elements
    }
  }
};

int main() {
  Queue q;  // Create an empty queue

  q.enqueue(10);  // Insert 10
  q.enqueue(20);  // Insert 20
  q.enqueue(30);  // Insert 30

  q.display();  // Display the queue: 10 20 30

  q.dequeue();  // Remove front element (10)
  q.display();  // Display the queue: 20 30

  q.enqueue(40);  // Insert 40
  q.display();    // Display the queue: 20 30 40

  cout << "Front element is: " << q.peek() << endl;  // Peek at the front: 20

  return 0;
}
