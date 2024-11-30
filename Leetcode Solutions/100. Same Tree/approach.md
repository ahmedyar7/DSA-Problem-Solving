# [100. Same Tree](https://leetcode.com/problems/same-tree/)

### **Approach and Intuition**

The function `isSameTree` checks whether two binary trees `p` and `q` are structurally identical and have the same node values. The approach uses **recursive traversal** to compare corresponding nodes in the two trees.

### **Key Steps:**

1. **Base Case**:

   - If both nodes are `nullptr` (i.e., end of corresponding branches in both trees), return `true`.
   - If one node is `nullptr` and the other is not, return `false` (trees differ in structure).

2. **Recursive Case**:

   - First, check if the left subtrees of `p` and `q` are identical by recursively calling `isSameTree(p->left, q->left)`.
   - Then, check if the right subtrees of `p` and `q` are identical by calling `isSameTree(p->right, q->right)`.
   - Finally, compare the values of the current nodes `p->val` and `q->val`.

3. **Combine Results**:
   - The trees are the same if and only if:
     - The left subtrees are identical.
     - The right subtrees are identical.
     - The current nodes' values are equal.
   - Return `true` if all three conditions are `true`; otherwise, return `false`.

### **Dry Run**

Consider the following example trees:

**Tree 1 (`p`):**

```
    1
   / \
  2   3
```

**Tree 2 (`q`):**

```
    1
   / \
  2   3
```

#### **Step-by-Step Execution**:

1. **Call**: `isSameTree(p, q)` where `p->val = 1`, `q->val = 1`:

   - `p` and `q` are not `nullptr`.
   - `p->val == q->val` → `true`.

2. **Left Subtree Check**:

   - **Call**: `isSameTree(p->left, q->left)` where `p->left->val = 2`, `q->left->val = 2`:

     - `p->left` and `q->left` are not `nullptr`.
     - `p->left->val == q->left->val` → `true`.

     - **Call**: `isSameTree(p->left->left, q->left->left)` where both are `nullptr`.
       - Return `true`.
     - **Call**: `isSameTree(p->left->right, q->left->right)` where both are `nullptr`.

       - Return `true`.

     - Combine results: `left = true`, `right = true`, `value = true` → Return `true`.

3. **Right Subtree Check**:

   - **Call**: `isSameTree(p->right, q->right)` where `p->right->val = 3`, `q->right->val = 3`:

     - `p->right` and `q->right` are not `nullptr`.
     - `p->right->val == q->right->val` → `true`.

     - **Call**: `isSameTree(p->right->left, q->right->left)` where both are `nullptr`.
       - Return `true`.
     - **Call**: `isSameTree(p->right->right, q->right->right)` where both are `nullptr`.

       - Return `true`.

     - Combine results: `left = true`, `right = true`, `value = true` → Return `true`.

4. Combine all results at the root:
   - `left = true`, `right = true`, `value = true`.
   - Return `true`.

### **Final Output**:

Both trees are the same, so the function returns `true`.
