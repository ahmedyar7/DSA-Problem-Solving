# [222. Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes/description/)

### Explanation of the Code

This code defines a class `Solution` with a function `countNodes` to calculate the total number of nodes in a binary tree. It uses a recursive approach to count the nodes in the left and right subtrees and adds them together, including the current node.

---

### Step-by-Step Explanation

1. **Base Case**:

   - If the current node (`root`) is `nullptr`, return `0`. This indicates that there are no nodes in an empty subtree.

   ```cpp
   if (root == nullptr) {
       return 0;
   }
   ```

2. **Recursive Step**:

   - The function recursively calculates the total number of nodes in the left subtree by calling `countNodes(root->left)`.
   - Similarly, it calculates the total number of nodes in the right subtree by calling `countNodes(root->right)`.

   ```cpp
   int left = countNodes(root->left);
   int right = countNodes(root->right);
   ```

3. **Summing Nodes**:

   - The total number of nodes is calculated as:
     - The nodes in the left subtree (`left`).
     - The nodes in the right subtree (`right`).
     - Plus 1 for the current node (`root`).

   ```cpp
   return left + right + 1;
   ```

---

### Dry Run

#### Example Tree:

```
        1
       / \
      2   3
     / \
    4   5
```

#### Step-by-Step Execution:

1. **At Root Node (`1`)**:

   - Call `countNodes(root->left)` to calculate the nodes in the left subtree.
   - Call `countNodes(root->right)` to calculate the nodes in the right subtree.

2. **At Node `2`**:

   - Call `countNodes(root->left)` for the left subtree.
   - Call `countNodes(root->right)` for the right subtree.

3. **At Node `4`**:

   - Both `left` and `right` children are `nullptr`.
   - Returns `0` for both subtrees.
   - Total nodes = `0 (left) + 0 (right) + 1 (current node) = 1`.

4. **At Node `5`**:

   - Both `left` and `right` children are `nullptr`.
   - Returns `0` for both subtrees.
   - Total nodes = `0 (left) + 0 (right) + 1 (current node) = 1`.

5. **Back at Node `2`**:

   - Left subtree (`countNodes(4)`) returned `1`.
   - Right subtree (`countNodes(5)`) returned `1`.
   - Total nodes = `1 (left) + 1 (right) + 1 (current node) = 3`.

6. **At Node `3`**:

   - Both `left` and `right` children are `nullptr`.
   - Returns `0` for both subtrees.
   - Total nodes = `0 (left) + 0 (right) + 1 (current node) = 1`.

7. **Back at Root Node (`1`)**:
   - Left subtree (`countNodes(2)`) returned `3`.
   - Right subtree (`countNodes(3)`) returned `1`.
   - Total nodes = `3 (left) + 1 (right) + 1 (current node) = 5`.

---

### Final Result:

The total number of nodes in the binary tree is **5**.

---

### Time Complexity:

- **O(n)**: Each node is visited exactly once.

### Space Complexity:

- **O(h)**: Space is used by the recursion stack, where `h` is the height of the tree.
