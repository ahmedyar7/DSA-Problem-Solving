# [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)

### Explanation of the Code

This C++ function `maxDepth` calculates the **maximum depth (or height)** of a binary tree using recursion. The maximum depth is the length of the longest path from the root node to any leaf node.

The algorithm works by recursively calculating the depth of the left and right subtrees and returning the larger of the two, adding one to account for the current node.

---

### Step-by-Step Breakdown

#### 1. **Base Case (Tree is Empty)**:

- If the tree is empty (`root == nullptr`), return `0`.
- This indicates that the height of an empty subtree is `0`.

```cpp
if (root == nullptr) {
    return 0;
}
```

#### 2. **Recursive Calls**:

- Call `maxDepth` recursively for the left and right subtrees.
- Store the heights of the left and right subtrees in `left_height` and `right_height`.

```cpp
int left_height = maxDepth(root->left);
int right_height = maxDepth(root->right);
```

#### 3. **Calculate the Maximum Depth**:

- The depth of the current tree is `1 + max(left_height, right_height)`.
- The `1` accounts for the current node.

```cpp
return 1 + std::max(left_height, right_height);
```

---

### Dry Run with Example Tree

#### Example Tree:

```
        1
       / \
      2   3
     / \
    4   5
```

#### Execution Steps:

1. **At Root Node (`1`)**:
   - Call `maxDepth(root->left)` to calculate the depth of the left subtree.
   - Call `maxDepth(root->right)` to calculate the depth of the right subtree.

---

2. **At Node `2`**:
   - Call `maxDepth(root->left)` for the left subtree.
   - Call `maxDepth(root->right)` for the right subtree.

---

3. **At Node `4`**:

   - Both `left` and `right` children are `nullptr`.
   - Returns `0` for both subtrees.
   - Depth = `1 + max(0, 0) = 1`.

4. **At Node `5`**:
   - Both `left` and `right` children are `nullptr`.
   - Returns `0` for both subtrees.
   - Depth = `1 + max(0, 0) = 1`.

---

5. **Back at Node `2`**:
   - Left subtree (`maxDepth(4)`) returned `1`.
   - Right subtree (`maxDepth(5)`) returned `1`.
   - Depth = `1 + max(1, 1) = 2`.

---

6. **At Node `3`**:
   - Both `left` and `right` children are `nullptr`.
   - Returns `0` for both subtrees.
   - Depth = `1 + max(0, 0) = 1`.

---

7. **Back at Root Node (`1`)**:
   - Left subtree (`maxDepth(2)`) returned `2`.
   - Right subtree (`maxDepth(3)`) returned `1`.
   - Depth = `1 + max(2, 1) = 3`.

---

### Final Result:

The **maximum depth of the binary tree** is **3**.

---

### Visualization of Recursive Calls

| Node | Left Subtree Depth | Right Subtree Depth | Calculated Depth |
| ---- | ------------------ | ------------------- | ---------------- |
| `4`  | `0`                | `0`                 | `1`              |
| `5`  | `0`                | `0`                 | `1`              |
| `2`  | `1`                | `1`                 | `2`              |
| `3`  | `0`                | `0`                 | `1`              |
| `1`  | `2`                | `1`                 | `3`              |

---

### Time and Space Complexity

1. **Time Complexity**:

   - **O(n)**, where `n` is the number of nodes in the tree. Each node is visited once.

2. **Space Complexity**:
   - **O(h)**, where `h` is the height of the tree. This is the space required for the recursive call stack.
   - In the worst case (skewed tree), `h = n`. For a balanced tree, `h = log(n)`.

---
