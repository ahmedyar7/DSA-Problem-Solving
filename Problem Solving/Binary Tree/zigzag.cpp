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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    bool left_to_right = true;

    while (!q.empty()) {
      int size = q.size();
      vector<int> ans(size);

      for (int i = 0; i < size; i++) {
        TreeNode* front_node = q.front();
        q.pop();

        int index = left_to_right ? i : size - i - 1;
        ans[index] = front_node->val;

        if (front_node->left != nullptr) {
          q.push(front_node->left);
        }
        if (front_node->right != nullptr) {
          q.push(front_node->right);
        }
      }
      result.push_back(ans);
      left_to_right = !left_to_right;
    }
    return result;
  }
};