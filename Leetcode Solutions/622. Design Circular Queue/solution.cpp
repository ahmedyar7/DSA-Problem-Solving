class MyCircularQueue {
 public:
  int size;
  int front;
  int rear;
  int* arr;
  MyCircularQueue(int k) {
    size = k;
    front = -1;
    rear = -1;
    arr = new int[size];
  }

  bool enQueue(int value) {
    if (isFull()) {  // check if queue is full
      return false;
    }
    if (isEmpty()) {  // if queue is empty, reset front and rear
      front = rear = 0;
    } else if (rear == size - 1 && front != 0) {  // handle circular nature
      rear = 0;
    } else {
      rear++;
    }
    arr[rear] = value;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {  // check if queue is empty
      return false;
    }
    if (front == rear) {             // if only one element was there
      front = rear = -1;             // reset queue to empty
    } else if (front == size - 1) {  // handle circular nature
      front = 0;
    } else {
      front++;
    }
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return arr[front];
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    return arr[rear];
  }

  bool isEmpty() { return (front == -1); }

  bool isFull() {
    return ((rear + 1) % size == front);  // full when rear is just before front
  }
};
