class Node {
 public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

class Stack {
 private:
  Node* top;

 public:
  Stack() { top = nullptr; }

  bool empty() { return top == nullptr; }

  void push(int value) {
    Node* new_node = new Node(value);
    new_node->next = top;
    top = new_node;
  }

  int pop() {
    if (empty()) return -1;  // Handle underflow case
    Node* temp = top;
    top = top->next;
    int value = temp->data;
    delete temp;
    return value;
  }

  int peek() {
    if (empty()) return -1;  // Handle underflow case
    return top->data;
  }
};

class MyQueue {
 private:
  Stack* st1;
  Stack* st2;

 public:
  MyQueue() {
    st1 = new Stack();
    st2 = new Stack();
  }

  void push(int x) { st1->push(x); }

  int pop() {
    if (st1->empty() && st2->empty()) {
      return -1;  // Queue is empty
    }
    if (st2->empty()) {
      while (!st1->empty()) {
        st2->push(st1->pop());
      }
    }
    return st2->pop();
  }

  int peek() {
    if (st1->empty() && st2->empty()) {
      return -1;  // Queue is empty
    }
    if (st2->empty()) {
      while (!st1->empty()) {
        st2->push(st1->pop());
      }
    }
    return st2->peek();  // Only peek without removing
  }

  bool empty() { return st1->empty() && st2->empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
