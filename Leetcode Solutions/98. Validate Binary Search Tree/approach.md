# [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/description/)

To check if a binary tree is a valid Binary Search Tree (BST), we can use an in-order traversal approach:

1. **In-order Traversal**: Traverse the tree in left-root-right order. For a valid BST, the values should appear in **strictly increasing** order.
2. **Tracking Previous Node**: While traversing, keep track of the previously visited node's value. If at any point the current node's value is less than or equal to the previous node's value, the tree is not a valid BST.

3. **Base Case**: If the node is `nullptr` (empty), return `true` (valid).

4. **Recursion**: For each node, recursively visit the left subtree, check the current node's value against the previous one, update the previous value, and then recursively visit the right subtree.

5. **Edge Case Handling**: Use `long long` for the previous value to avoid overflow when comparing extreme values (e.g., `INT_MIN` or `INT_MAX`).

The algorithm ensures that all nodes satisfy the BST property, with an O(n) time complexity for traversing all nodes.
