# [155. Min Stack](https://leetcode.com/problems/min-stack/description/)

### Explanation of the `MinStack` class

This `MinStack` class is designed to store integers and provide two key operations efficiently:

1. **Push an integer onto the stack**.
2. **Pop an integer off the stack**.

Additionally, it also supports:

- **Getting the top element** (the most recently added element).
- **Getting the minimum element** in the stack at any given time.

### Data Structure

The `MinStack` uses a stack (`st`) of `pair<int, int>`, where:

- The first `int` in the pair represents the actual value being pushed onto the stack.
- The second `int` represents the minimum value at that point in the stack (the minimum among all elements in the stack).

By using this structure, we can efficiently get the minimum value in constant time without having to traverse the entire stack.

### Class Methods

1. **Constructor:**

   ```cpp
   MinStack() {}
   ```

   This constructor initializes an empty stack (`st`).

2. **Push Method:**

   ```cpp
   void push(int val) {
       if (st.empty()) {
           st.push({val, val});  // First element's min is itself
       } else {
           st.push({val, min(val, st.top().second)});  // Store value and current min
       }
   }
   ```

   - If the stack is empty, the first value is pushed onto the stack, and both the value and the minimum are the same (`{val, val}`).
   - If the stack is not empty, the new element `val` is pushed along with the minimum value. The minimum is computed using the `min(val, st.top().second)` function, which compares the current element with the minimum value of the stack (the second element of the pair at the top of the stack).

3. **Pop Method:**

   ```cpp
   void pop() {
       if (!st.empty()) {
           st.pop();
       }
   }
   ```

   - If the stack is not empty, the top element is removed from the stack.

4. **Top Method:**

   ```cpp
   int top() {
       return st.top().first;  // Access the value only
   }
   ```

   - This method returns the value at the top of the stack (the first element of the top pair).

5. **GetMin Method:**
   ```cpp
   int getMin() {
       return st.top().second;  // Access the current minimum
   }
   ```
   - This method returns the current minimum value in the stack (the second element of the top pair).

### Dry Run Example

Let’s go through an example step by step to see how the `MinStack` works in action.

#### Example:

```cpp
MinStack* obj = new MinStack();
obj->push(10);      // Push 10
obj->push(20);      // Push 20
obj->push(5);       // Push 5
obj->push(15);      // Push 15
int min1 = obj->getMin();  // Get minimum (should return 5)
obj->pop();         // Pop the top element (15)
int top1 = obj->top();  // Get top (should return 5)
int min2 = obj->getMin();  // Get minimum (should still return 5)
obj->pop();         // Pop the top element (5)
int top2 = obj->top();  // Get top (should return 20)
int min3 = obj->getMin();  // Get minimum (should return 10)
```

#### Step-by-step dry run:

1. **Initial State:**

   - Stack: `[]` (empty stack)

2. **Push 10:**
   - Stack: `[{10, 10}]`
     - The minimum is `10` (since it's the only element).
3. **Push 20:**

   - Stack: `[{10, 10}, {20, 10}]`
     - The current element is `20`, and the minimum value is `min(20, 10) = 10`, so `10` is stored as the minimum.

4. **Push 5:**

   - Stack: `[{10, 10}, {20, 10}, {5, 5}]`
     - The current element is `5`, and the minimum value is `min(5, 10) = 5`, so `5` is stored as the minimum.

5. **Push 15:**

   - Stack: `[{10, 10}, {20, 10}, {5, 5}, {15, 5}]`
     - The current element is `15`, and the minimum value is `min(15, 5) = 5`, so `5` is stored as the minimum.

6. **GetMin():**

   - `getMin()` returns `5`, as `5` is the minimum at the top of the stack.

7. **Pop (remove 15):**

   - Stack: `[{10, 10}, {20, 10}, {5, 5}]`
     - The top element `15` is removed. The minimum value of the remaining stack is still `5`.

8. **Top():**

   - `top()` returns `5`, as `5` is now the top element.

9. **GetMin():**

   - `getMin()` returns `5`, as `5` is the minimum.

10. **Pop (remove 5):**

    - Stack: `[{10, 10}, {20, 10}]`
      - The top element `5` is removed. The next minimum value in the stack is `10`.

11. **Top():**

    - `top()` returns `20`, as `20` is the top element now.

12. **GetMin():**
    - `getMin()` returns `10`, as `10` is now the minimum in the stack.

### Final Result:

After all the operations, the stack will look like this:

```cpp
[{10, 10}, {20, 10}]
```

- The minimum value is `10` at the top.

### **Time Complexity**

- **push(val)**: O(1) because inserting into the stack is constant time, and calculating the minimum for each element is also constant time.
- **pop()**: O(1) because removing the top element is a constant-time operation.
- **top()**: O(1) because accessing the top element is constant time.
- **getMin()**: O(1) because accessing the minimum is constant time.

### **Space Complexity**

- **O(n)**: Where `n` is the number of elements in the stack, because each element stores a pair of values.
