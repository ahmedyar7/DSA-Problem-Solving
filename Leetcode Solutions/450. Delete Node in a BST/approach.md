# [450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/description/?envType=problem-list-v2&envId=binary-search-tree)

### Intuition and Approach for `deleteNode` Function

The problem requires deleting a node with a given `key` in a **Binary Search Tree (BST)** while maintaining its properties. Let's break down the approach:

---

### **1. BST Property**

In a BST:

- Left subtree of a node contains only nodes with values less than the node’s value.
- Right subtree contains only nodes with values greater than the node’s value.

The solution leverages these properties to recursively find and delete the target node.

---

### **2. Recursive Search**

The algorithm recursively traverses the tree:

1. **If `key < root->val`**:
   - The node to delete lies in the left subtree.
   - Recursively call `deleteNode` for `root->left`.
2. **If `key > root->val`**:

   - The node to delete lies in the right subtree.
   - Recursively call `deleteNode` for `root->right`.

3. **If `key == root->val`**:
   - Found the node to delete.

---

### **3. Deletion Cases**

After locating the node, there are three possible cases:

#### **Case 1: Node with No Children (Leaf Node)**

- Simply delete the node and return `nullptr`.

```cpp
if (root->left == nullptr && root->right == nullptr) {
    delete root;
    return nullptr;
}
```

#### **Case 2: Node with One Child**

- Replace the node with its only child:
  - **Left child exists**: Replace with `root->left`.
  - **Right child exists**: Replace with `root->right`.

```cpp
if (root->left == nullptr) {
    TreeNode* temp = root->right;
    delete root;
    return temp;
} else if (root->right == nullptr) {
    TreeNode* temp = root->left;
    delete root;
    return temp;
}
```

#### **Case 3: Node with Two Children**

- Replace the node’s value with its **inorder successor** (smallest value in the right subtree).
- Recursively delete the inorder successor.

```cpp
TreeNode* inorder_successor = find_min_node(root->right);
root->val = inorder_successor->val;
root->right = deleteNode(root->right, inorder_successor->val);
```

---

### **4. Helper Function**

The `find_min_node` function locates the inorder successor:

- The inorder successor of a node is the smallest node in its right subtree (leftmost node in `root->right`).

```cpp
TreeNode* find_min_node(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
```

---

### **5. Return Updated Tree**

After handling all cases, return the updated `root`.

---

### **Overall Intuition**

- **Traversal**: The function traverses the tree recursively to find the target node.
- **Replacement**: Once the target node is found, it handles deletion based on the node's children.
- **Inorder Successor**: Ensures the tree remains a valid BST after deletion in case of two children.

---
