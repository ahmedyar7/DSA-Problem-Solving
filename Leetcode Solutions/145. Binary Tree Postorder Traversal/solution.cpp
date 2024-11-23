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
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
      return {};  // Return an empty vector for null nodes
    }

    vector<int> result;

    // Traverse the left subtree and append its result
    vector<int> left = postorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    // Traverse the right subtree and append its result
    vector<int> right = postorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());

    // Add the root node's data
    result.push_back(root->val);

    return result;
  }
};