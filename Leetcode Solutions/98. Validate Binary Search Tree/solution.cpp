/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 private:
  bool inorder_traversal(TreeNode* root, long long& previous) {
    if (root == nullptr) return true;  // Base case

    // Traverse left subtree
    if (!inorder_traversal(root->left, previous))
      return false;  // left subtree fails
    if (root->val <= previous) return false;
    previous = root->val;
    return inorder_traversal(root->right, previous);
  }

 public:
  bool isValidBST(TreeNode* root) {
    long long previous = LONG_MIN;
    return inorder_traversal(root, previous);
  }
};