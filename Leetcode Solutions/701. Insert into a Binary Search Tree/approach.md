# [701. Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/description/)

### Intuition

The problem is about inserting a new value into a **Binary Search Tree (BST)**. In a BST:

- **All values in the left subtree** of a node are **less** than the node's value.
- **All values in the right subtree** of a node are **greater** than the node's value.

This property allows us to decide the direction (left or right) to go based on the value we want to insert. We simply follow the tree structure recursively, looking for the right spot where the new value should be placed.

### Approach

1. **Base Case (Empty Tree)**:

   - If the `root` is `nullptr`, this means we have reached an empty spot in the tree where the new value should be inserted. At this point, we create a new `TreeNode` with the value to insert and return it.

2. **Recursive Step**:

   - If the value to insert (`val`) is **greater** than the current node’s value (`root->val`), we recursively insert the value into the **right subtree** by calling `insertIntoBST(root->right, val)`.
   - If the value to insert (`val`) is **less** than the current node’s value (`root->val`), we recursively insert the value into the **left subtree** by calling `insertIntoBST(root->left, val)`.

3. **Return the root**:
   - After the insertion, the tree structure might change, but the root remains the same. Therefore, the function returns the root of the tree after insertion.

### Detailed Explanation

1. **Recursion**:

   - The function uses recursion to traverse the tree, starting from the `root`.
   - At each node, it compares the value to insert with the current node's value and decides whether to go left or right. This continues until an appropriate `nullptr` spot is found where a new node is inserted.

2. **Tree Structure**:

   - In a BST, the insertion operation ensures that the **left subtree** always contains values smaller than the node, and the **right subtree** always contains values greater than the node.
   - This maintains the properties of the BST as we keep inserting new nodes.

3. **Insertion Process**:
   - The process can be visualized as searching for a leaf node where the new value can be inserted. The key difference from a search operation is that instead of stopping when the value is found, we insert a new node when we find a `nullptr` where the new value should go.

### Example Walkthrough

Consider the following BST:

```
       10
      /  \
     5    15
    / \   / \
   3   7 12  18
```

We want to insert `13`.

1. **Start at the root node** (`10`):

   - `13 > 10`, so we move to the **right** child (`15`).

2. **At node `15`**:

   - `13 < 15`, so we move to the **left** child (`12`).

3. **At node `12`**:

   - `13 > 12`, so we move to the **right** child, which is `nullptr`.

4. **Insert the new node**:
   - Since the right child of node `12` is `nullptr`, we insert a new node with value `13` here.

Now the tree will look like this:

```
       10
      /  \
     5    15
    / \   / \
   3   7 12  18
              /
            13
```

### Example Code Execution

Let’s consider the case where we insert `13` into the tree:

- `insertIntoBST(root, 13)`
- At `root = 10`, since `13 > 10`, we call `insertIntoBST(root->right, 13)` (move to the right subtree).
- At `root = 15`, since `13 < 15`, we call `insertIntoBST(root->left, 13)` (move to the left subtree).
- At `root = 12`, since `13 > 12`, we call `insertIntoBST(root->right, 13)` (move to the right subtree, which is `nullptr`).
- At `root = nullptr`, we insert a new `TreeNode(13)` and return it, which is set as the right child of node `12`.

### Time Complexity

- **Best Case**: **O(log n)** in a balanced tree. Each step moves either left or right, halving the tree at each level.
- **Worst Case**: **O(n)** if the tree is skewed (e.g., a linked list), where the algorithm may need to traverse all the way down to the last node.

### Space Complexity

- The space complexity is determined by the recursion stack. In the best case (balanced tree), the recursion depth is **O(log n)**. In the worst case (skewed tree), the recursion depth is **O(n)**.
