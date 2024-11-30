# [700. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/description/)

### Intuition

The approach behind this solution is based on the properties of a **Binary Search Tree (BST)**. In a BST:

- All nodes in the **left subtree** of a node have values **smaller** than the node.
- All nodes in the **right subtree** of a node have values **greater** than the node.

Using this property, we can effectively search for a value in the tree by traversing it in a way that eliminates half of the tree at each step, making it an efficient search algorithm with a time complexity of **O(log n)** in the best case (balanced tree).

### Approach

1. **Base Case (Empty Tree or Found)**:

   - If the current node (`root`) is `nullptr`, the tree (or subtree) has been fully traversed without finding the value, so we return `nullptr` to indicate the value is not present.
   - If the current node's value (`root->val`) is equal to the target value (`val`), we return the node itself because we've found the value.

2. **Left Subtree or Right Subtree?**:
   - If the target value (`val`) is **greater** than the current node's value (`root->val`), then the target must be in the **right** subtree of the current node. Therefore, we recursively search the right child (`root->right`).
   - If the target value (`val`) is **less** than the current node's value (`root->val`), then the target must be in the **left** subtree of the current node. Therefore, we recursively search the left child (`root->left`).

### Detailed Explanation

1. **Recursion**: This algorithm uses recursion to traverse the tree. At each level, it checks whether the current node matches the target value or whether it should move to the left or right subtree based on the BST properties.

2. **Termination Conditions**:

   - If the node is `nullptr`, the recursion ends, and the function returns `nullptr`, indicating that the target value is not present in the tree.
   - If the node’s value matches the target, the node itself is returned, ending the search.

3. **Efficiency**:
   - The key benefit of this approach is the elimination of half of the tree at each step, based on the comparison of the target value with the current node’s value. This leads to a logarithmic time complexity in the best case for a balanced BST.

### Example Walkthrough

Consider the following BST:

```
       10
      /  \
     5    15
    / \   / \
   3   7 12  18
```

We want to search for `7`.

1. Start at the root node: `10`.
   - `7 < 10`, so we move to the **left** subtree (`5`).
2. At node `5`:

   - `7 > 5`, so we move to the **right** subtree (`7`).

3. At node `7`:
   - `7 == 7`, so we have found the node. The function returns `7`.

### Example Code Execution

Let’s take an example with `val = 7`:

- `searchBST(root, 7)`
- At `root = 10`, since `7 < 10`, it calls `searchBST(root->left, 7)` (moves to left subtree).
- Now `root = 5`, since `7 > 5`, it calls `searchBST(root->right, 7)` (moves to right subtree).
- Now `root = 7`, the condition `root->val == 7` is satisfied, so it returns the node `7`.

If the target were `3`, the function would have moved left first (at node `10`, then `5`, and finally `3`), and it would return the node `3`.

### Time Complexity

- In a **balanced BST**, the time complexity is **O(log n)** where `n` is the number of nodes. This is because we eliminate half of the tree at each step, similar to a binary search on an array.
- In the **worst case** (e.g., a degenerate tree where all nodes are skewed to one side), the time complexity would degrade to **O(n)**, where `n` is the number of nodes, as we would essentially be performing a linear search.
