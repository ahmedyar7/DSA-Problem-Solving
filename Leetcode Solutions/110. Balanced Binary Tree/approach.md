# [110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

## Explanation of the Code

This code checks whether a given binary tree is **height-balanced**. A **height-balanced binary tree** is defined as a binary tree in which the height difference between the left and right subtrees of any node is at most 1. Here's a breakdown of the code:

---

### **Key Functions**

1. **`maxheight(TreeNode* root)`**

   - Calculates the height of the tree rooted at `root` while checking if the tree is height-balanced.
   - If the tree is not height-balanced, it returns `-1` as a signal.
   - If the tree is balanced, it returns the height of the tree.

2. **`isBalanced(TreeNode* root)`**
   - Determines whether the tree is height-balanced by calling `maxheight`.
   - If `maxheight` returns `-1`, the tree is not balanced; otherwise, it is balanced.

---

### **Detailed Step-by-Step Explanation**

#### 1. **Base Case**:

```cpp
if (root == nullptr) {
    return 0;
}
```

- If the current node (`root`) is `nullptr`, it means we've reached a leaf node or an empty tree.
- The height of an empty tree is defined as `0`.

---

#### 2. **Recursive Calculation of Subtree Heights**:

```cpp
int left = maxheight(root->left);
if (left == -1)
    return -1;
int right = maxheight(root->right);
if (right == -1)
    return -1;
```

- Recursively calculate the height of the left and right subtrees.
- If either subtree returns `-1`, it means that subtree is unbalanced, so the entire tree rooted at `root` is also unbalanced. Hence, return `-1`.

---

#### 3. **Check Balance Condition**:

```cpp
if (abs(left - right) > 1)
    return -1;
```

- If the absolute difference between the heights of the left and right subtrees (`abs(left - right)`) is greater than `1`, the current tree is unbalanced. Return `-1`.

---

#### 4. **Return Height of the Tree**:

```cpp
return max(left, right) + 1;
```

- If the tree is balanced, return the height of the current node as `1 + max(left, right)`.

---

#### 5. **Determine Overall Balance**:

```cpp
bool isBalanced(TreeNode* root) {
    return maxheight(root) != -1;
}
```

- If `maxheight` returns `-1`, the tree is not balanced; otherwise, it is balanced.

---

### **Dry Run**

#### Tree Structure:

```
        1
       / \
      2   3
     /
    4
```

**Step 1: Start with `isBalanced(root)`**

- Call `maxheight(root)` where `root = 1`.

---

**Step 2: Compute `maxheight(1)`**

- Calculate `maxheight(root->left)` for `root->left = 2`.

---

**Step 3: Compute `maxheight(2)`**

- Calculate `maxheight(root->left)` for `root->left = 4`.

---

**Step 4: Compute `maxheight(4)`**

- Both `root->left` and `root->right` are `nullptr`, so:
  ```cpp
  maxheight(4->left) = 0
  maxheight(4->right) = 0
  ```
- `abs(0 - 0) <= 1`, so return `max(0, 0) + 1 = 1`.

---

**Step 5: Back to `maxheight(2)`**

- Left subtree height = `1` (from `4`).
- Calculate `maxheight(root->right)` for `root->right = nullptr`.
  ```cpp
  maxheight(2->right) = 0
  ```
- `abs(1 - 0) <= 1`, so return `max(1, 0) + 1 = 2`.

---

**Step 6: Back to `maxheight(1)`**

- Left subtree height = `2` (from `2`).
- Calculate `maxheight(root->right)` for `root->right = 3`.

---

**Step 7: Compute `maxheight(3)`**

- Both `root->left` and `root->right` are `nullptr`, so:
  ```cpp
  maxheight(3->left) = 0
  maxheight(3->right) = 0
  ```
- `abs(0 - 0) <= 1`, so return `max(0, 0) + 1 = 1`.

---

**Step 8: Final Calculation for `maxheight(1)`**

- Left subtree height = `2` (from `2`).
- Right subtree height = `1` (from `3`).
- `abs(2 - 1) <= 1`, so return `max(2, 1) + 1 = 3`.

---

**Step 9: Result of `isBalanced`**

- `maxheight(root)` did not return `-1`, so the tree is balanced.
- `isBalanced(root)` returns `true`.

---

### **Complexity Analysis**

1. **Time Complexity**:

   - Each node is visited once.
   - Time complexity: **O(n)**, where `n` is the number of nodes.

2. **Space Complexity**:
   - Space required for the recursion stack in the worst case (when the tree is skewed): **O(h)**, where `h` is the height of the tree.

---

### Example Output

For the tree:

```
        1
       / \
      2   3
     /
    4
```

**Function Calls**:

```cpp
isBalanced(root); // true
```
