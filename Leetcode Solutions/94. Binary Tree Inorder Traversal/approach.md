# [94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

This C++ code implements **inorder traversal** for a binary tree using recursion. In **inorder traversal**, nodes are visited in the following order:

1. **Left Subtree**
2. **Root Node**
3. **Right Subtree**

---

## TreeNode Structure

The `TreeNode` struct defines the structure of a binary tree node.

### Code:

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

### Key Points:

- **`val`**: Holds the value of the node.
- **`left`**: Points to the left child node.
- **`right`**: Points to the right child node.

---

## Inorder Traversal Function

The goal is to traverse a binary tree **inorder** (Left → Root → Right) and return a vector containing the node values.

### Code:

```cpp
vector<int> inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return {}; // Return an empty vector for null nodes
    }

    vector<int> result;

    // Traverse the left subtree and append its result
    vector<int> left = inorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    // Add the root node's data
    result.push_back(root->val);

    // Traverse the right subtree and append its result
    vector<int> right = inorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}
```

---

## Step-by-Step Explanation

### **1. Base Case**

```cpp
if (root == nullptr) {
    return {}; // Return an empty vector for null nodes
}
```

- If the current node is `nullptr`, it means we have reached a leaf node or the tree is empty.
- The function returns an empty vector `{}` in this case.

---

### **2. Initialize Result Vector**

```cpp
vector<int> result;
```

- Create a `result` vector to store the node values as we traverse the tree.

---

### **3. Traverse the Left Subtree**

```cpp
vector<int> left = inorderTraversal(root->left);
result.insert(result.end(), left.begin(), left.end());
```

- Recursively call `inorderTraversal` on the left child (`root->left`) to traverse the left subtree.
- Store the result of the left subtree traversal in a `left` vector.
- Append all elements of `left` to `result` using:
  ```cpp
  result.insert(result.end(), left.begin(), left.end());
  ```

---

### **4. Add Root Node Value**

```cpp
result.push_back(root->val);
```

- Add the value of the current node (`root->val`) to the `result` vector.

---

### **5. Traverse the Right Subtree**

```cpp
vector<int> right = inorderTraversal(root->right);
result.insert(result.end(), right.begin(), right.end());
```

- Recursively call `inorderTraversal` on the right child (`root->right`) to traverse the right subtree.
- Store the result of the right subtree traversal in a `right` vector.
- Append all elements of `right` to `result`.

---

### **6. Return the Result**

```cpp
return result;
```

- After processing the left subtree, root node, and right subtree, return the final `result` vector containing the nodes in **inorder** order.

---

## Example Dry Run

### Input Binary Tree:

```
        1
       / \
      2   3
     / \
    4   5
```

### Traversal Order:

Inorder Traversal (Left → Root → Right): **`4, 2, 5, 1, 3`**

---

### Dry Run:

#### **Step 1**: Call `inorderTraversal(1)`:

- Root is `1`.
- Traverse the left subtree: Call `inorderTraversal(2)`.

---

#### **Step 2**: Call `inorderTraversal(2)`:

- Root is `2`.
- Traverse the left subtree: Call `inorderTraversal(4)`.

---

#### **Step 3**: Call `inorderTraversal(4)`:

- Root is `4`.
- Left and right children are `nullptr`.
- Return `{4}`.

---

#### **Step 4**: Back to `inorderTraversal(2)`:

- Left subtree result: `{4}`.
- Add root value (`2`) to result: `{4, 2}`.
- Traverse the right subtree: Call `inorderTraversal(5)`.

---

#### **Step 5**: Call `inorderTraversal(5)`:

- Root is `5`.
- Left and right children are `nullptr`.
- Return `{5}`.

---

#### **Step 6**: Back to `inorderTraversal(2)`:

- Right subtree result: `{5}`.
- Append to result: `{4, 2, 5}`.
- Return `{4, 2, 5}`.

---

#### **Step 7**: Back to `inorderTraversal(1)`:

- Left subtree result: `{4, 2, 5}`.
- Add root value (`1`) to result: `{4, 2, 5, 1}`.
- Traverse the right subtree: Call `inorderTraversal(3)`.

---

#### **Step 8**: Call `inorderTraversal(3)`:

- Root is `3`.
- Left and right children are `nullptr`.
- Return `{3}`.

---

#### **Step 9**: Back to `inorderTraversal(1)`:

- Right subtree result: `{3}`.
- Append to result: `{4, 2, 5, 1, 3}`.
- Return `{4, 2, 5, 1, 3}`.

---

## Final Result:

The inorder traversal of the binary tree is:

```cpp
{4, 2, 5, 1, 3}
```

---

## Complexity Analysis:

### **Time Complexity**:

- **`O(n)`**: Each node is visited exactly once, where `n` is the total number of nodes in the tree.

### **Space Complexity**:

- **`O(n)`**: For the recursion stack (in case of a completely skewed tree) and the result vector.

---

## Summary of Inorder Traversal:

1. Traverse the left subtree recursively.
2. Process the root node.
3. Traverse the right subtree recursively.
4. Combine the results and return the final vector.

Let me know if you have any questions! 😊
