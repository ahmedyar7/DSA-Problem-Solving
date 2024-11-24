class MyCircularDeque {
 private:
  int front;
  int rear;
  int size;
  int* arr;

 public:
  MyCircularDeque(int k) {
    size = k;
    front = -1;
    rear = -1;
    arr = new int[size];
  }

  bool insertFront(int value) {
    if (isFull()) {
      cout << "Queue is full\n";
      return false;
    } else if (front == -1) {
      front = rear = 0;
    } else if (front == 0) {
      front = size - 1;
    } else {
      front = front - 1;
    }
    arr[front] = value;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) {
      cout << "Queue is full\n";
      return false;
    } else if (front == -1) {
      front = rear = 0;
    } else if (rear == size - 1) {
      rear = 0;
    } else {
      rear = (rear + 1) % size;
    }
    arr[rear] = value;
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) {
      cout << "The queue is empty\n";
      return false;
    }
    int value = arr[front];
    if (front == rear) {
      front = rear = -1;
    } else if (front == size - 1) {
      front = 0;
    } else {
      front = (front + 1) % size;
    }
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) {
      cout << "The Queue is empty\n";
      return false;
    }
    int value = arr[rear];
    if (front == rear) {
      front = rear = -1;
    } else if (rear == 0) {
      rear = size - 1;
    } else {
      rear = rear - 1;
    }
    return true;
  }

  int getFront() {
    if (isEmpty()) {
      return -1;
    }
    return arr[front];
  }

  int getRear() {
    if (isEmpty()) {
      return -1;
    }
    return arr[rear];
  }

  bool isEmpty() { return front == -1; }

  bool isFull() { return ((rear + 1) % size == front); }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */