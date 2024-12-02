# [96. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)

The given problem is a classical problem in combinatorics: finding the **Catalan number** for a given `n`. This problem can be directly related to counting the number of unique binary search trees (BSTs) that can be formed with `n` distinct nodes, where `n` is the number of nodes in the tree.

### Problem Breakdown:

1. **Catalan Number**: The `n`-th Catalan number represents the number of unique binary search trees that can be constructed using `n` distinct nodes. It can be calculated using the formula:
   \[
   C_n = \frac{(2n)!}{(n+1)! \cdot n!}
   \]

   - This formula involves calculating factorials, but you can avoid computing large factorials directly by using a recursive dynamic programming approach, which is more efficient.

2. **Recursive Approach**:
   - If you want to count the number of unique BSTs, the problem is reduced to considering all possible root nodes, then calculating the number of BSTs for the left and right subtrees.
   - For each node `i` from 1 to `n`, if `i` is the root, then:
     - The left subtree contains nodes from `1` to `i-1`, and the right subtree contains nodes from `i+1` to `n`.
     - The number of unique BSTs with `i` as the root is the product of the number of unique BSTs in the left and right subtrees.
     - This gives the recursive formula for the number of unique BSTs:
       \[
       dp[i] = \sum\_{i=1}^{n} dp[i-1] \cdot dp[n-i]
       \]
       where `dp[i]` is the number of unique BSTs for `i` nodes.

### Approach to Solve:

1. **Recursive Formula**: The `n`-th Catalan number can be calculated using a recursive relationship. You can recursively calculate the number of unique BSTs by considering each node as the root and then multiplying the results for the left and right subtrees.
