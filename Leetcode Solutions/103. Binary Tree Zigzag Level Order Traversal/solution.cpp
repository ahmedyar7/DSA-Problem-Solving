class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;  // Correct return type
    if (root == nullptr) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool L_T_R = true;  // Left to right flag

    while (!q.empty()) {
      int size = q.size();
      vector<int> ans(size);  // Pre-sized vector for the level

      for (int i = 0; i < size; i++) {
        TreeNode* front_node = q.front();
        q.pop();

        int index = L_T_R ? i : size - i - 1;
        ans[index] = front_node->val;

        if (front_node->left != nullptr) {
          q.push(front_node->left);
        }
        if (front_node->right != nullptr) {
          q.push(front_node->right);
        }
      }

      result.push_back(ans);  // Push the level result
      L_T_R = !L_T_R;         // Toggle direction for next level
    }

    return result;
  }
};
