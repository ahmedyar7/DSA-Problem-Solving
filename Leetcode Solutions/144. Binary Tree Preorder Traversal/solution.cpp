class Solution {
  vector<int> preorderTraversal(TreeNode\* root) {
    if (root == nullptr) {
      return {};  // Return an empty vector for null nodes
    }

    vector<int> result;

    // Add the root node's data
    result.push_back(root->val);

    // Traverse the left subtree and append its result
    vector<int> left = preorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    // Traverse the right subtree and append its result
    vector<int> right = preorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
  }
};
