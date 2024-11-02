#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
  int data;
  Node* prev;
  Node* next;
  Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Class for the doubly-ended queue (deque)
class Deque {
 private:
  Node* front;
  Node* rear;
  int size;

 public:
  Deque() : front(nullptr), rear(nullptr), size(0) {}

  // Check if the deque is empty
  bool isEmpty() { return size == 0; }

  // Add an element to the front of the deque
  void insertFront(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
      front = rear = newNode;
    } else {
      newNode->next = front;
      front->prev = newNode;
      front = newNode;
    }
    size++;
  }

  // Add an element to the rear of the deque
  void insertRear(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
      front = rear = newNode;
    } else {
      newNode->prev = rear;
      rear->next = newNode;
      rear = newNode;
    }
    size++;
  }

  // Remove an element from the front of the deque
  void deleteFront() {
    if (isEmpty()) {
      cout << "Deque is empty. Cannot delete from front.\n";
      return;
    }
    Node* temp = front;
    if (front == rear) {
      front = rear = nullptr;
    } else {
      front = front->next;
      front->prev = nullptr;
    }
    delete temp;
    size--;
  }

  // Remove an element from the rear of the deque
  void deleteRear() {
    if (isEmpty()) {
      cout << "Deque is empty. Cannot delete from rear.\n";
      return;
    }
    Node* temp = rear;
    if (front == rear) {
      front = rear = nullptr;
    } else {
      rear = rear->prev;
      rear->next = nullptr;
    }
    delete temp;
    size--;
  }

  // Get the front element
  int getFront() {
    if (isEmpty()) {
      cout << "Deque is empty. No front element.\n";
      return -1;
    }
    return front->data;
  }

  // Get the rear element
  int getRear() {
    if (isEmpty()) {
      cout << "Deque is empty. No rear element.\n";
      return -1;
    }
    return rear->data;
  }

  // Display the elements of the deque
  void display() {
    if (isEmpty()) {
      cout << "Deque is empty.\n";
      return;
    }
    Node* temp = front;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  // Destructor to clean up the memory
  ~Deque() {
    while (!isEmpty()) {
      deleteFront();
    }
  }
};

// Test the deque implementation
int main() {
  Deque dq;

  dq.insertRear(10);
  dq.insertRear(20);
  dq.insertFront(5);
  dq.display();  // Output: 5 10 20

  cout << "Front element: " << dq.getFront() << endl;  // Output: 5
  cout << "Rear element: " << dq.getRear() << endl;    // Output: 20

  dq.deleteFront();
  dq.display();  // Output: 10 20

  dq.deleteRear();
  dq.display();  // Output: 10

  dq.deleteRear();
  dq.display();  // Output: Deque is empty.

  return 0;
}
