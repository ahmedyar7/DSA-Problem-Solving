# [232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/description/)

This implementation creates a queue (`MyQueue`) using two stacks (`st1` and `st2`). The `MyQueue` class provides typical queue operations like `push`, `pop`, `peek`, and `empty`. Here's how it works step by step:

---

### **Core Concepts**

1. **Queue**:

   - A queue follows the **FIFO (First In, First Out)** principle.
   - Elements are added to the back and removed from the front.

2. **Stack**:
   - A stack follows the **LIFO (Last In, First Out)** principle.
   - Elements are added and removed from the top.

To mimic a queue using stacks, this implementation uses **two stacks**:

- **`st1`**: Stores elements in the order they are pushed.
- **`st2`**: Temporarily holds reversed elements when performing `pop` or `peek`.

---

### **Class Breakdown**

#### **Node**

```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};
```

- Represents a single node in a stack.
- **Attributes**:
  - `data`: Stores the value of the node.
  - `next`: Pointer to the next node in the stack.

---

#### **Stack**

```cpp
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
```

- Implements a **stack** using a linked list.
- **Key Methods**:
  - `push`: Adds an element to the top of the stack.
  - `pop`: Removes and returns the top element.
  - `peek`: Returns the top element without removing it.
  - `empty`: Checks if the stack is empty.

---

#### **MyQueue**

```cpp
class MyQueue {
private:
    Stack* st1;  // Main stack to hold elements
    Stack* st2;  // Temporary stack for reversing order

public:
    MyQueue() {
        st1 = new Stack();
        st2 = new Stack();
    }
```

- **Attributes**:
  - `st1`: Main stack where elements are pushed.
  - `st2`: Auxiliary stack used for reversing order during `pop` and `peek`.

---

### **Queue Operations**

#### 1. `push(int x)`

```cpp
void push(int x) {
    st1->push(x);
}
```

- Pushes an element onto `st1`.
- **Complexity**: \( O(1) \).

---

#### 2. `pop()`

```cpp
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
```

- Removes and returns the front element of the queue.
- **Steps**:
  1. If both `st1` and `st2` are empty, the queue is empty, return `-1`.
  2. If `st2` is empty:
     - Transfer all elements from `st1` to `st2`. This reverses the order, making the front of the queue the top of `st2`.
  3. Pop the top element from `st2`.
- **Complexity**:
  - Worst case: \( O(n) \) (when transferring from `st1` to `st2`).
  - Amortized: \( O(1) \) (subsequent pops are \( O(1) \)).

---

#### 3. `peek()`

```cpp
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
```

- Returns the front element of the queue without removing it.
- **Steps**:
  - Similar to `pop`, transfer elements from `st1` to `st2` if `st2` is empty.
  - Return the top element of `st2`.
- **Complexity**:
  - Worst case: \( O(n) \) (when transferring from `st1` to `st2`).
  - Amortized: \( O(1) \).

---

#### 4. `empty()`

```cpp
bool empty() {
    return st1->empty() && st2->empty();
}
```

- Returns `true` if both `st1` and `st2` are empty, indicating the queue is empty.
- **Complexity**: \( O(1) \).

---

### **Example Dry Run**

#### Input

```cpp
MyQueue* obj = new MyQueue();
obj->push(1);
obj->push(2);
obj->peek();   // Returns 1
obj->pop();    // Returns 1
obj->empty();  // Returns false
```

#### Step-by-Step Execution

1. **`push(1)`**:

   - Add `1` to `st1`.
   - `st1`: [1]
   - `st2`: []

2. **`push(2)`**:

   - Add `2` to `st1`.
   - `st1`: [2, 1]
   - `st2`: []

3. **`peek()`**:

   - `st2` is empty, transfer from `st1` to `st2`.
     - `st1`: []
     - `st2`: [1, 2] (reversed order of `st1`).
   - Peek top of `st2` → 1.

4. **`pop()`**:

   - Remove top of `st2`.
   - `st1`: []
   - `st2`: [2]
   - Returns `1`.

5. **`empty()`**:
   - Both `st1` and `st2` are not empty.
   - Returns `false`.

---
