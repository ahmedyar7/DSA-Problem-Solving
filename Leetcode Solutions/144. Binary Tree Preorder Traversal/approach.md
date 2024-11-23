# [144. Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/description/)

This document explains the implementation of **preorder traversal** for a binary tree using recursion in C++. Preorder traversal is a **depth-first traversal technique** where nodes are visited in the following order:

1. **Root Node**
2. **Left Subtree**
3. **Right Subtree**

---

## TreeNode Struct

The `TreeNode` struct defines the structure of a binary tree node. Here's its implementation:

```cpp
struct TreeNode {
    int val;           // Value of the node
    TreeNode *left;    // Pointer to the left child
    TreeNode *right;   // Pointer to the right child

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and child pointers
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
```

### Explanation:

- **`val`**: Holds the value of the node.
- **`left`**: Pointer to the left child node.
- **`right`**: Pointer to the right child node.

### Constructors:

1. **Default Constructor**: Initializes `val` to `0` and both `left` and `right` to `nullptr`.
2. **Parameterized Constructor**: Initializes `val` to a given value `x` and sets `left` and `right` to `nullptr`.
3. **Constructor with Children**: Initializes `val` to `x` and assigns provided pointers to the `left` and `right` children.

---

## Preorder Traversal Function

This function performs preorder traversal of a binary tree and returns a vector of node values in the order they are visited.

```cpp
vector<int> preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return {}; // Return an empty vector for null nodes
    }

    vector<int> result;

    // Add the root node's data
    result.push_back(root->val);

    // Traverse the left subtree and append its result
    vector<int> left = preorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    // Traverse the right subtree and append its result
    vector<int> right = preorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}
```

---

### **Step-by-step Explanation**

#### 1. Base Case: Null Node

```cpp
if (root == nullptr) {
    return {}; // Return an empty vector for null nodes
}
```

- If the current node (`root`) is `nullptr`, it indicates that the subtree is empty. The function returns an empty vector `{}`.

#### 2. Create the Result Vector

```cpp
vector<int> result;
```

- Initialize an empty vector `result` to store the values of nodes visited during the traversal.

#### 3. Process the Root Node

```cpp
result.push_back(root->val);
```

- Add the value of the current node (`root->val`) to the result vector. This step processes the **root** as part of the preorder traversal.

#### 4. Traverse the Left Subtree

```cpp
vector<int> left = preorderTraversal(root->left);
result.insert(result.end(), left.begin(), left.end());
```

- Recursively call `preorderTraversal` on the left child (`root->left`) to traverse the left subtree.
- Append the result of the left subtree to the `result` vector using:
  ```cpp
  result.insert(result.end(), left.begin(), left.end());
  ```

#### 5. Traverse the Right Subtree

```cpp
vector<int> right = preorderTraversal(root->right);
result.insert(result.end(), right.begin(), right.end());
```

- Similarly, recursively call `preorderTraversal` on the right child (`root->right`) to traverse the right subtree.
- Append the result of the right subtree to the `result` vector.

#### 6. Return the Final Result

```cpp
return result;
```

- After processing the root node and traversing both the left and right subtrees, return the `result` vector containing the preorder traversal of the tree.

---

## Example Walkthrough

### Given Binary Tree:

```
        1
       / \
      2   3
     / \
    4   5
```

### Traversal Order:

Preorder Traversal (Root → Left → Right): **`1, 2, 4, 5, 3`**

### Dry Run:

1. **Call `preorderTraversal(1)`**:

   - Add `1` to result: `result = [1]`.
   - Traverse the left subtree: `preorderTraversal(2)`.

2. **Call `preorderTraversal(2)`**:

   - Add `2` to result: `result = [2]`.
   - Traverse the left subtree: `preorderTraversal(4)`.

3. **Call `preorderTraversal(4)`**:

   - Add `4` to result: `result = [4]`.
   - Both left and right children are `nullptr`. Return `[4]`.

4. **Back to `preorderTraversal(2)`**:

   - Append `[4]` to result: `result = [2, 4]`.
   - Traverse the right subtree: `preorderTraversal(5)`.

5. **Call `preorderTraversal(5)`**:

   - Add `5` to result: `result = [5]`.
   - Both left and right children are `nullptr`. Return `[5]`.

6. **Back to `preorderTraversal(2)`**:

   - Append `[5]` to result: `result = [2, 4, 5]`.
   - Return `[2, 4, 5]`.

7. **Back to `preorderTraversal(1)`**:

   - Append `[2, 4, 5]` to result: `result = [1, 2, 4, 5]`.
   - Traverse the right subtree: `preorderTraversal(3)`.

8. **Call `preorderTraversal(3)`**:

   - Add `3` to result: `result = [3]`.
   - Both left and right children are `nullptr`. Return `[3]`.

9. **Back to `preorderTraversal(1)`**:
   - Append `[3]` to result: `result = [1, 2, 4, 5, 3]`.
   - Return `[1, 2, 4, 5, 3]`.

---

## Result:

The preorder traversal of the binary tree is:

```cpp
{1, 2, 4, 5, 3}
```

---

## Time and Space Complexity:

### **Time Complexity**:

- **`O(n)`**: Each node is visited exactly once, where `n` is the number of nodes in the tree.

### **Space Complexity**:

- **`O(n)`**: Space is required for the recursion stack (in case of a skewed tree) and the result vector.

---

Let me know if you have further questions! 😊
