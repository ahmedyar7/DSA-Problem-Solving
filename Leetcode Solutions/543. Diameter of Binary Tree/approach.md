# [543. Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

Let's break down the code with a dry run to understand how it works. The goal is to calculate the **diameter** of a binary tree, which is the length of the longest path between any two nodes. This path may or may not pass through the root.

### Classes and Functions:

- **`height()`**: Computes the height of a node (the longest path from that node to any leaf).
- **`diameterHelper()`**: Computes both the height of the node and updates the diameter at each node.
- **`diameterOfBinaryTree()`**: A public function that initializes the diameter and calls the helper function to calculate it.

### Dry Run Example:

Consider the following binary tree:

```
         1
        / \
       2   3
      / \
     4   5
```

The diameter of this tree is the longest path between any two nodes, which in this case is from node `4` to node `5` passing through node `2`. The diameter is `3` (4 -> 2 -> 5).

### Step-by-Step Execution:

1. **Initial Call**:

   - We call `diameterOfBinaryTree(root)` where `root` is the node with value `1`. Initially, `diameter = 0`.

2. **Recursive Helper Call (`diameterHelper`)**:

   - The `diameterHelper` function is called on node `1`.

3. **At node 1**:
   - Call `diameterHelper` on the left child (`node 2`).
4. **At node 2**:

   - Call `diameterHelper` on the left child (`node 4`).

5. **At node 4**:

   - Call `diameterHelper` on the left child (nullptr). It returns `0` (base case).
   - Call `diameterHelper` on the right child (nullptr). It also returns `0`.
   - Now, for node `4`, the left height is `0` and the right height is `0`. The diameter at node `4` is `0 + 0 = 0` (no path across this node).
   - Return `max(0, 0) + 1 = 1` (the height of node `4`).

6. **Back to node 2**:

   - Call `diameterHelper` on the right child (`node 5`).

7. **At node 5**:

   - Call `diameterHelper` on the left child (nullptr). It returns `0`.
   - Call `diameterHelper` on the right child (nullptr). It returns `0`.
   - Now, for node `5`, the left height is `0` and the right height is `0`. The diameter at node `5` is `0 + 0 = 0`.
   - Return `max(0, 0) + 1 = 1` (the height of node `5`).

8. **Back to node 2**:

   - Now, at node `2`, the left height is `1` (from node `4`) and the right height is `1` (from node `5`).
   - The diameter at node `2` is `1 + 1 = 2`.
   - Update `diameter = max(0, 2) = 2`.
   - Return `max(1, 1) + 1 = 2` (the height of node `2`).

9. **Back to node 1**:

   - Call `diameterHelper` on the right child (`node 3`).

10. **At node 3**:

    - Call `diameterHelper` on the left child (nullptr). It returns `0`.
    - Call `diameterHelper` on the right child (nullptr). It returns `0`.
    - Now, for node `3`, the left height is `0` and the right height is `0`. The diameter at node `3` is `0 + 0 = 0`.
    - Return `max(0, 0) + 1 = 1` (the height of node `3`).

11. **Back to node 1**:

    - Now, at node `1`, the left height is `2` (from node `2`) and the right height is `1` (from node `3`).
    - The diameter at node `1` is `2 + 1 = 3`.
    - Update `diameter = max(2, 3) = 3`.
    - Return `max(2, 1) + 1 = 3` (the height of node `1`).

12. **Final Result**:
    - After all recursive calls are completed, the diameter of the tree is `3`.

### Final Output:

The function returns `3`, which is the diameter of the binary tree.

### Key Insights:

- The `height()` function computes the height of the node (max height of left and right subtrees + 1).
- The `diameterHelper()` function computes the diameter at each node by checking the sum of the heights of the left and right subtrees. It then updates the `diameter` if a larger value is found during recursion.
- The overall time complexity is **O(N)** where N is the number of nodes, as each node is visited exactly once.
- The space complexity is **O(H)** where H is the height of the tree, due to the recursion stack. In the worst case (a skewed tree), this would be **O(N)**. In the best case (a balanced tree), it would be **O(log N)**.
