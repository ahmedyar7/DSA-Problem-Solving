# [641. Design Circular Deque](https://leetcode.com/problems/design-circular-deque/description/)

The `MyCircularDeque` class implements a circular deque (double-ended queue) using a fixed-size array. A circular deque allows inserting and deleting elements from both the front and rear of the queue. Here’s a detailed explanation of the code:

### **Attributes**

1. **`front`**: Index of the front element in the deque.
2. **`rear`**: Index of the rear element in the deque.
3. **`size`**: The maximum size of the deque.
4. **`arr`**: Array used to store the elements of the deque.

---

### **Constructor**

```cpp
MyCircularDeque(int k) {
    size = k;
    front = -1;
    rear = -1;
    arr = new int[size];
}
```

- **Initialization**:
  - `size` is set to the specified value `k`, indicating the capacity of the deque.
  - Both `front` and `rear` are initialized to `-1`, indicating that the deque is empty.
  - `arr` is a dynamically allocated array with a size of `k` to store the deque's elements.

---

### **Methods**

#### **1. `insertFront(int value)`**

```cpp
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
```

- **Inserts an element at the front of the deque**.
- **Steps**:
  1. If the deque is full (`isFull()`), print a message and return `false`.
  2. If the deque is empty (`front == -1`), both `front` and `rear` are set to `0`.
  3. If `front == 0` (i.e., it's at the first index), wrap around to the end of the array (`front = size - 1`).
  4. Otherwise, decrement `front` to move the front pointer backward.
  5. Insert the element at `arr[front]`.
- **Returns**: `true` if successful, `false` if the deque is full.

#### **2. `insertLast(int value)`**

```cpp
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
```

- **Inserts an element at the rear of the deque**.
- **Steps**:
  1. If the deque is full (`isFull()`), print a message and return `false`.
  2. If the deque is empty (`front == -1`), both `front` and `rear` are set to `0`.
  3. If `rear == size - 1` (i.e., it's at the last index), wrap around to the beginning (`rear = 0`).
  4. Otherwise, increment `rear` using modulo arithmetic to stay within bounds.
  5. Insert the element at `arr[rear]`.
- **Returns**: `true` if successful, `false` if the deque is full.

#### **3. `deleteFront()`**

```cpp
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
```

- **Removes an element from the front of the deque**.
- **Steps**:
  1. If the deque is empty (`isEmpty()`), print a message and return `false`.
  2. If there's only one element (`front == rear`), reset the deque by setting `front` and `rear` to `-1`.
  3. If `front == size - 1`, wrap around to the beginning (`front = 0`).
  4. Otherwise, increment `front` using modulo arithmetic to move the front pointer forward.
- **Returns**: `true` if successful, `false` if the deque is empty.

#### **4. `deleteLast()`**

```cpp
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
```

- **Removes an element from the rear of the deque**.
- **Steps**:
  1. If the deque is empty (`isEmpty()`), print a message and return `false`.
  2. If there's only one element (`front == rear`), reset the deque by setting `front` and `rear` to `-1`.
  3. If `rear == 0`, wrap around to the end (`rear = size - 1`).
  4. Otherwise, decrement `rear` to move the rear pointer backward.
- **Returns**: `true` if successful, `false` if the deque is empty.

#### **5. `getFront()`**

```cpp
int getFront() {
    if (isEmpty()) {
        return -1;
    }
    return arr[front];
}
```

- **Returns the front element of the deque** without removing it.
- **Returns**: `arr[front]` if the deque is not empty, `-1` if the deque is empty.

#### **6. `getRear()`**

```cpp
int getRear() {
    if (isEmpty()) {
        return -1;
    }
    return arr[rear];
}
```

- **Returns the rear element of the deque** without removing it.
- **Returns**: `arr[rear]` if the deque is not empty, `-1` if the deque is empty.

#### **7. `isEmpty()`**

```cpp
bool isEmpty() {
    return front == -1;
}
```

- **Checks if the deque is empty**.
- **Returns**: `true` if the deque is empty, `false` otherwise.

#### **8. `isFull()`**

```cpp
bool isFull() {
    return ((rear + 1) % size == front);
}
```

- **Checks if the deque is full**.
- **Returns**: `true` if the deque is full, `false` otherwise.

---

### **Key Points**

- **Circular Nature**: Both `insertFront` and `insertLast` use modulo arithmetic to ensure that the pointers (`front` and `rear`) wrap around when they reach the array's end.
- **Empty and Full Conditions**:
  - The deque is empty when `front == -1`.
  - The deque is full when `(rear + 1) % size == front`, which means there is no room for the next element.
- **Edge Cases**:
  - For operations like inserting or deleting when the deque is full or empty, the code handles these conditions explicitly by returning `false` and printing an appropriate message.
  - Both `insertFront` and `insertLast` properly handle wrapping around when the pointers reach the bounds of the array.

### **Example Dry Run**

Let's consider a deque with size `3`:

1. **Initialize deque**:

   - `front = -1`, `rear = -1`, `arr = [_, _, _]`.

2. **Insert 10 at the front**:

   - `insertFront(10)`: `front = rear = 0`, `arr = [10, _, _]`.

3. **Insert 20 at the rear**:

   - `insertLast(20)`: `rear = 1`, `arr = [10, 20, _]`.

4. **Insert 30 at the rear**:

   - `insertLast(30)`: `rear = 2`, `arr = [10, 20, 30]`.

5. **Try to insert 40 at the front (queue full)**:

   - `insertFront(40)`: Queue is full, returns `false`.

6. **Delete from the front**:

   - `deleteFront()`: `front = 1`, `arr = [10, 20, 30]`.

7. **Insert 40 at the front**:

   - `insertFront(40)`: `front = 0`, `arr = [40, 20, 30]`.

8. **Get front and rear**:
   - `getFront()`: `40`.
   - `getRear()`: `30`.
