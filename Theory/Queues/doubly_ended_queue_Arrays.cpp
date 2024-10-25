#include <iostream>
using namespace std;

class Deque {
 private:
  int *arr;   // Array to store the elements
  int front;  // Index of the front element
  int rear;   // Index of the rear element
  int size;   // Maximum size of the deque

 public:
  // Constructor
  Deque(int size) {
    this->size = size;
    arr = new int[size];
    front = -1;
    rear = 0;
  }

  // Check if deque is full
  bool isFull() {
    return ((front == 0 && rear == size - 1) || front == rear + 1);
  }

  // Check if deque is empty
  bool isEmpty() { return (front == -1); }

  // Insert an element at the front
  void insertFront(int value) {
    if (isFull()) {
      cout << "Deque is full. Cannot insert " << value << " at front." << endl;
      return;
    }
    // If deque is initially empty
    if (front == -1) {
      front = 0;
      rear = 0;
    } else if (front == 0) {  // Circular increment
      front = size - 1;
    } else {
      front = front - 1;
    }
    arr[front] = value;
  }

  // Insert an element at the rear
  void insertRear(int value) {
    if (isFull()) {
      cout << "Deque is full. Cannot insert " << value << " at rear." << endl;
      return;
    }
    // If deque is initially empty
    if (front == -1) {
      front = 0;
      rear = 0;
    } else if (rear == size - 1) {  // Circular increment
      rear = 0;
    } else {
      rear = rear + 1;
    }
    arr[rear] = value;
  }

  // Delete an element from the front
  int deleteFront() {
    if (isEmpty()) {
      cout << "Deque is empty. Cannot delete from front." << endl;
      return -1;
    }

    int value = arr[front];  // Store the value to be deleted
    if (front == rear) {     // Deque has only one element
      front = -1;
      rear = -1;
    } else if (front == size - 1) {  // Circular increment
      front = 0;
    } else {
      front = front + 1;
    }
    return value;
  }

  // Delete an element from the rear
  int deleteRear() {
    if (isEmpty()) {
      cout << "Deque is empty. Cannot delete from rear." << endl;
      return -1;
    }

    int value = arr[rear];  // Store the value to be deleted
    if (front == rear) {    // Deque has only one element
      front = -1;
      rear = -1;
    } else if (rear == 0) {  // Circular decrement
      rear = size - 1;
    } else {
      rear = rear - 1;
    }
    return value;
  }

  // Display the contents of the deque
  void display() {
    if (isEmpty()) {
      cout << "Deque is empty." << endl;
      return;
    }
    int i = front;
    cout << "Deque elements: ";
    while (true) {
      cout << arr[i] << " ";
      if (i == rear) break;
      i = (i + 1) % size;
    }
    cout << endl;
  }

  // Destructor to release memory
  ~Deque() { delete[] arr; }
};

int main() {
  Deque dq(5);  // Initialize a deque with size 5

  // Insert elements at rear and front
  dq.insertRear(10);
  dq.insertRear(20);
  dq.insertFront(5);
  dq.insertFront(3);

  dq.display();  // Display deque contents

  // Deleting elements from front and rear
  cout << "Deleted from front: " << dq.deleteFront() << endl;
  cout << "Deleted from rear: " << dq.deleteRear() << endl;

  dq.display();  // Display deque contents

  // Insert more elements
  dq.insertRear(25);
  dq.insertFront(1);

  dq.display();  // Final deque contents

  return 0;
}
