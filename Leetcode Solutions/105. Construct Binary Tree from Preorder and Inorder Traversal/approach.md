# [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

### Problem Recap:

We are given two traversal arrays:

- **Preorder Traversal**: The root node is visited first, followed by the left subtree, and then the right subtree.
- **Inorder Traversal**: The left subtree is visited first, followed by the root node, and then the right subtree.

We need to construct the binary tree from these two traversals.

### Approach:

1. **Preorder Array**: The first element of the `preorder` array is always the root of the current tree (or subtree).
2. **Inorder Array**: Once we have the root (from the `preorder` array), we can locate its position in the `inorder` array. The elements to the left of the root in `inorder` form the left subtree, and the elements to the right of the root form the right subtree.
3. We recursively repeat this process for the left and right subtrees.

### Code Explanation:

#### Function `find_index`

This function simply finds the index of the root value in the `inorder` array. We use this index to split the `inorder` array into left and right subtrees.

```cpp
int find_index(vector<int>& inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}
```

#### Function `buildTreeHelper`

This function is called recursively to build the binary tree. It takes:

- **`preorder`** and **`inorder`** arrays.
- **`preorder_index`**: This keeps track of the current root in the `preorder` array.
- **`inorder_start`** and **`inorder_end`**: These define the bounds of the current subtree in the `inorder` array.

### Step-by-step Dry Run:

Let's take an example with the following arrays:

- **Preorder** = `[10, 5, 1, 7, 15, 12, 18]`
- **Inorder** = `[1, 5, 7, 10, 12, 15, 18]`

#### Step 1: First Call to `buildTree`

The function `buildTree` initializes the `preorder_index` as `0` and calls `buildTreeHelper(preorder, inorder, preorder_index, 0, inorder.size() - 1)`.

#### Step 2: First Recursive Call to `buildTreeHelper`

- **`preorder_index = 0`**, so the root value is `preorder[0] = 10`.
- Create a new `TreeNode` with value `10`.
- Find the index of `10` in `inorder` using `find_index`: `inorder_index = 3`.
- Split the `inorder` array into two parts:
  - Left subtree: `inorder[0, 2] = [1, 5, 7]`
  - Right subtree: `inorder[4, 6] = [12, 15, 18]`
- Recursively construct the left and right subtrees.

#### Step 3: Construct Left Subtree of Root (10)

- **`preorder_index = 1`**, so the root value is `preorder[1] = 5`.
- Create a new `TreeNode` with value `5`.
- Find the index of `5` in `inorder`: `inorder_index = 1`.
- Split the `inorder` array into two parts:
  - Left subtree: `inorder[0, 0] = [1]`
  - Right subtree: `inorder[2, 2] = [7]`
- Recursively construct the left and right subtrees.

#### Step 4: Construct Left Subtree of 5

- **`preorder_index = 2`**, so the root value is `preorder[2] = 1`.
- Create a new `TreeNode` with value `1`.
- Find the index of `1` in `inorder`: `inorder_index = 0`.
- There are no elements left for the left or right subtrees, so both left and right children are `nullptr`.

#### Step 5: Construct Right Subtree of 5

- **`preorder_index = 3`**, so the root value is `preorder[3] = 7`.
- Create a new `TreeNode` with value `7`.
- There are no elements left for the left or right subtrees, so both left and right children are `nullptr`.

#### Step 6: Construct Right Subtree of Root (10)

- **`preorder_index = 4`**, so the root value is `preorder[4] = 15`.
- Create a new `TreeNode` with value `15`.
- Find the index of `15` in `inorder`: `inorder_index = 5`.
- Split the `inorder` array into two parts:
  - Left subtree: `inorder[4, 4] = [12]`
  - Right subtree: `inorder[6, 6] = [18]`
- Recursively construct the left and right subtrees.

#### Step 7: Construct Left Subtree of 15

- **`preorder_index = 5`**, so the root value is `preorder[5] = 12`.
- Create a new `TreeNode` with value `12`.
- There are no elements left for the left or right subtrees, so both left and right children are `nullptr`.

#### Step 8: Construct Right Subtree of 15

- **`preorder_index = 6`**, so the root value is `preorder[6] = 18`.
- Create a new `TreeNode` with value `18`.
- There are no elements left for the left or right subtrees, so both left and right children are `nullptr`.

### Final Tree Structure:

```
        10
       /  \
      5    15
     / \   / \
    1   7 12  18
```

### Summary of Dry Run:

1. We start with the root node, which is always the first element of the `preorder` array.
2. We find the root's position in the `inorder` array, which allows us to separate the left and right subtrees.
3. Recursively repeat this process for both the left and right subtrees until all nodes are added.

This process runs in **O(n)** time, where `n` is the number of nodes, since we visit each node exactly once and do a linear search for the index in the `inorder` array for each root.
