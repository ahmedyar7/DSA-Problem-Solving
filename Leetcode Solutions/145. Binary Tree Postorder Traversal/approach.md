# [145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/description/)

### **Explanation of the Code**

The given code performs a **postorder traversal** of a binary tree using recursion. In **postorder traversal**, the nodes are visited in the following order:

1. **Left Subtree**: Traverse all nodes in the left subtree.
2. **Right Subtree**: Traverse all nodes in the right subtree.
3. **Root Node**: Process the root node last.

### **Detailed Breakdown**

1. **Base Case**:

   ```cpp
   if (root == nullptr) {
       return {}; // Return an empty vector for null nodes
   }
   ```

   If the current node is `nullptr`, the function returns an empty vector since there are no nodes to traverse.

2. **Recursive Traversal**:

   - The function calls itself recursively to traverse the left subtree:

     ```cpp
     vector<int> left = postorderTraversal(root->left);
     ```

     The result of traversing the left subtree is stored in the vector `left`.

   - Similarly, it traverses the right subtree:
     ```cpp
     vector<int> right = postorderTraversal(root->right);
     ```
     The result of traversing the right subtree is stored in the vector `right`.

3. **Combine Results**:

   - The `left` and `right` subtree results are appended to the `result` vector:
     ```cpp
     result.insert(result.end(), left.begin(), left.end());
     result.insert(result.end(), right.begin(), right.end());
     ```

4. **Process Root Node**:

   - The value of the current node is added to the `result` vector:
     ```cpp
     result.push_back(root->val);
     ```

5. **Return the Result**:
   - The `result` vector is returned, containing the postorder traversal of the subtree rooted at the current node:
     ```cpp
     return result;
     ```

---

### **Dry Run Example**

#### **Binary Tree**

Consider the following binary tree:

```
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
```

- **Preorder Traversal (Root → Left → Right):** `1, 2, 4, 5, 3, 6, 7`
- **Postorder Traversal (Left → Right → Root):** `4, 5, 2, 6, 7, 3, 1`

---

#### **Function Call Hierarchy**

We start with the root of the tree (`1`) and follow the recursive calls:

1. **Call `postorderTraversal(1)`**

   - `root->left = 2`
   - `root->right = 3`
   - Traverse the left subtree: `postorderTraversal(2)`

2. **Call `postorderTraversal(2)`**

   - `root->left = 4`
   - `root->right = 5`
   - Traverse the left subtree: `postorderTraversal(4)`

3. **Call `postorderTraversal(4)`**

   - `root = nullptr` for both left and right children.
   - Return `[4]`.

4. **Back to `postorderTraversal(2)`**

   - Append `[4]` (result from left subtree).
   - Traverse the right subtree: `postorderTraversal(5)`.

5. **Call `postorderTraversal(5)`**

   - `root = nullptr` for both left and right children.
   - Return `[5]`.

6. **Back to `postorderTraversal(2)`**

   - Append `[5]` (result from right subtree).
   - Add `2` (current node value).
   - Return `[4, 5, 2]`.

7. **Back to `postorderTraversal(1)`**

   - Append `[4, 5, 2]` (result from left subtree).
   - Traverse the right subtree: `postorderTraversal(3)`.

8. **Call `postorderTraversal(3)`**

   - `root->left = 6`
   - `root->right = 7`
   - Traverse the left subtree: `postorderTraversal(6)`.

9. **Call `postorderTraversal(6)`**

   - `root = nullptr` for both left and right children.
   - Return `[6]`.

10. **Back to `postorderTraversal(3)`**

    - Append `[6]` (result from left subtree).
    - Traverse the right subtree: `postorderTraversal(7)`.

11. **Call `postorderTraversal(7)`**

    - `root = nullptr` for both left and right children.
    - Return `[7]`.

12. **Back to `postorderTraversal(3)`**

    - Append `[7]` (result from right subtree).
    - Add `3` (current node value).
    - Return `[6, 7, 3]`.

13. **Back to `postorderTraversal(1)`**
    - Append `[6, 7, 3]` (result from right subtree).
    - Add `1` (current node value).
    - Return `[4, 5, 2, 6, 7, 3, 1]`.

---

#### **Final Output**

The postorder traversal of the binary tree is:

```
[4, 5, 2, 6, 7, 3, 1]
```

This matches the expected order: Left → Right → Root.
