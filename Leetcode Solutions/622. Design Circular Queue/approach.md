# [622. Design Circular Queue](https://leetcode.com/problems/design-circular-queue/description/)

The `MyCircularQueue` class implements a circular queue data structure. This data structure uses a fixed-size array to maintain a queue that wraps around when the end of the array is reached, effectively making it circular. Here's a breakdown of how this implementation works, including explanations of the methods and their behavior:

---

### **Attributes**

1. **`size`**: The maximum number of elements the queue can hold.
2. **`front`**: Index pointing to the front of the queue (the element to be dequeued next).
3. **`rear`**: Index pointing to the rear of the queue (the last added element).
4. **`arr`**: The underlying array that stores the queue elements.

---

### **Constructor**

```cpp
MyCircularQueue(int k) {
    size = k;
    front = -1;
    rear = -1;
    arr = new int[size];
}
```

- Initializes the queue with a given size `k`.
- Initially, `front` and `rear` are set to `-1`, indicating that the queue is empty.
- A dynamic array `arr` of size `k` is allocated to store the queue elements.

---

### **Methods**

#### **1. `enQueue(int value)`**

```cpp
bool enQueue(int value) {
    if (isFull()) {
        return false;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == size - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    arr[rear] = value;
    return true;
}
```

- Adds an element to the rear of the queue.
- **Steps**:
  1. If the queue is full (`isFull()`), return `false`.
  2. If the queue is empty (`isEmpty()`), set `front` and `rear` to `0` to initialize the queue.
  3. If `rear` is at the end of the array (`rear == size - 1`) but there's space at the start (`front != 0`), wrap around by setting `rear = 0`.
  4. Otherwise, increment `rear` and add the element at `arr[rear]`.
- **Circular Nature**:
  - The modulo operation ensures the queue wraps around when it reaches the end of the array.
- **Returns**: `true` if the operation is successful, `false` otherwise.

---

#### **2. `deQueue()`**

```cpp
bool deQueue() {
    if (isEmpty()) {
        return false;
    }
    if (front == rear) {
        front = rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
    return true;
}
```

- Removes an element from the front of the queue.
- **Steps**:
  1. If the queue is empty (`isEmpty()`), return `false`.
  2. If there's only one element (`front == rear`), reset the queue by setting `front = rear = -1`.
  3. If `front` is at the end of the array (`front == size - 1`), wrap around by setting `front = 0`.
  4. Otherwise, increment `front`.
- **Circular Nature**:
  - Similar to `enQueue`, it wraps around using modulo.
- **Returns**: `true` if the operation is successful, `false` otherwise.

---

#### **3. `Front()`**

```cpp
int Front() {
    if (isEmpty()) {
        return -1;
    }
    return arr[front];
}
```

- Retrieves the front element of the queue without removing it.
- **Returns**:
  - The value at `arr[front]` if the queue is not empty.
  - `-1` if the queue is empty.

---

#### **4. `Rear()`**

```cpp
int Rear() {
    if (isEmpty()) {
        return -1;
    }
    return arr[rear];
}
```

- Retrieves the rear element of the queue without removing it.
- **Returns**:
  - The value at `arr[rear]` if the queue is not empty.
  - `-1` if the queue is empty.

---

#### **5. `isEmpty()`**

```cpp
bool isEmpty() {
    return (front == -1);
}
```

- Checks if the queue is empty.
- **Returns**: `true` if `front == -1`, otherwise `false`.

---

#### **6. `isFull()`**

```cpp
bool isFull() {
    return ((rear + 1) % size == front);
}
```

- Checks if the queue is full.
- **Logic**:
  - The queue is full when advancing `rear` by 1 (modulo `size`) lands on `front`.
- **Returns**: `true` if the queue is full, otherwise `false`.

---

### **Key Points**

1. **Circular Nature**:

   - Both `enQueue` and `deQueue` handle the circular behavior using modulo arithmetic to wrap around when the array's end is reached.

2. **Queue Full Condition**:

   - `((rear + 1) % size == front)` ensures that `rear` cannot overwrite `front`.

3. **Edge Case for Single Element**:
   - When the queue has only one element, `front` and `rear` point to the same index. After dequeuing, both are reset to `-1`.

---

### **Example Dry Run**

#### Input

```cpp
MyCircularQueue* obj = new MyCircularQueue(3);
obj->enQueue(1);  // Adds 1
obj->enQueue(2);  // Adds 2
obj->enQueue(3);  // Adds 3
obj->enQueue(4);  // Fails (Queue is full)
obj->deQueue();   // Removes 1
obj->enQueue(4);  // Adds 4
obj->Rear();      // Returns 4
```

#### Execution

1. **Initialization**:

   - `size = 3`, `front = -1`, `rear = -1`, `arr = [_, _, _]`.

2. **`enQueue(1)`**:

   - Queue is empty (`isEmpty()`), set `front = rear = 0`.
   - Add `1` at `arr[rear]`.
   - State: `front = 0`, `rear = 0`, `arr = [1, _, _]`.

3. **`enQueue(2)`**:

   - Increment `rear` to `1`.
   - Add `2` at `arr[rear]`.
   - State: `front = 0`, `rear = 1`, `arr = [1, 2, _]`.

4. **`enQueue(3)`**:

   - Increment `rear` to `2`.
   - Add `3` at `arr[rear]`.
   - State: `front = 0`, `rear = 2`, `arr = [1, 2, 3]`.

5. **`enQueue(4)`**:

   - Queue is full (`isFull()`), return `false`.

6. **`deQueue()`**:

   - Increment `front` to `1`.
   - State: `front = 1`, `rear = 2`, `arr = [1, 2, 3]`.

7. **`enQueue(4)`**:

   - Wrap around: Set `rear = 0`.
   - Add `4` at `arr[rear]`.
   - State: `front = 1`, `rear = 0`, `arr = [4, 2, 3]`.

8. **`Rear()`**:
   - Return `arr[rear] = 4`.

---

### **Time Complexities**

- `enQueue`: \( O(1) \)
- `deQueue`: \( O(1) \)
- `Front`, `Rear`, `isEmpty`, `isFull`: \( O(1) \)
