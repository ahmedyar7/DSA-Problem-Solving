# [103. Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)

### **Approach and Intuition**

The goal of this algorithm is to traverse a binary tree level by level, but in a zigzag order: left-to-right for one level, then right-to-left for the next, and so on.

### **Key Concepts**

1. **Level Order Traversal (BFS):**

   - We use a **queue** to traverse the tree level by level.
   - At each level, all nodes are processed before moving on to the next level.

2. **Zigzag Mechanism:**
   - At each level, nodes are appended to a vector (`ans`).
   - The order of appending alternates between **left-to-right** and **right-to-left** using a boolean flag `L_T_R`.

---

### **Detailed Steps**

1. **Initialization:**

   - Start by creating an empty vector `result` to store the final zigzag order.
   - Initialize a queue and push the `root` node into it.
   - Use a boolean `L_T_R` to control the zigzag direction. Initially, it’s set to `true` (left-to-right).

2. **Level-wise Traversal Using Queue:**
   - While the queue is not empty, do the following:
     - Determine the number of nodes in the current level (`size = q.size()`).
     - Create a temporary vector `ans` of size `size` to store the nodes of the current level in zigzag order.
3. **Processing Each Level:**

   - For each node in the current level:
     - Pop the front node from the queue.
     - Calculate its position in the vector `ans`:
       - If `L_T_R` is `true` (left-to-right), use index `i`.
       - If `L_T_R` is `false` (right-to-left), use index `size - i - 1`.
     - Assign the node’s value to the calculated index in `ans`.
     - Push the left and right children of the node (if they exist) into the queue for the next level.

4. **Store the Result:**

   - After processing all nodes of the current level, push `ans` to `result`.

5. **Toggle the Direction:**

   - Flip the `L_T_R` flag (`L_T_R = !L_T_R`) to reverse the order for the next level.

6. **Return the Result:**
   - Once all levels are processed, return `result`.

---

### **Intuition**

- **Breadth-First Search (BFS):**  
  BFS is ideal for level-order traversal as it explores all nodes at the present depth level before moving on to nodes at the next depth level.

- **Zigzag Logic:**  
  The zigzag pattern is achieved by reversing the insertion order using the `L_T_R` flag:

  - In a typical level-order traversal, nodes are always appended left-to-right.
  - Here, we manipulate the indices so that the insertion order alternates between left-to-right and right-to-left.

- **Vector Pre-sizing:**  
  The vector `ans` is pre-sized to `size` (number of nodes in the current level) to allow direct index assignment.

---

### **Complexity Analysis**

1. **Time Complexity:**
   - \(O(N)\): Each node is processed exactly once, where \(N\) is the number of nodes in the tree.
2. **Space Complexity:**
   - \(O(N)\):
     - The space used by the queue in the worst case (a full binary tree) is \(O(N)\).
     - The result vector stores all nodes in a zigzag order.

---

### **Example Dry Run**

Consider the tree:

```
       1
     /   \
    2     3
   / \   / \
  4   5 6   7
```

- **Level 1**:

  - Queue: [1]
  - `L_T_R = true`
  - Process node `1` → `ans = [1]`
  - Result: `[[1]]`

- **Level 2**:

  - Queue: [2, 3]
  - `L_T_R = false`
  - Process node `2` → `ans[1] = 2` → `ans = [_, 2]`
  - Process node `3` → `ans[0] = 3` → `ans = [3, 2]`
  - Result: `[[1], [3, 2]]`

- **Level 3**:
  - Queue: [4, 5, 6, 7]
  - `L_T_R = true`
  - Process nodes 4, 5, 6, 7 → `ans = [4, 5, 6, 7]`
  - Result: `[[1], [3, 2], [4, 5, 6, 7]]`
