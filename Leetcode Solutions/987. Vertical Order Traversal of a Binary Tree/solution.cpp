#include <bits/stdc++.h>

#include <map>
#include <vector>
class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, vector<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> q;
    vector<vector<int>> ans;

    if (root == nullptr) {
      return ans;
    }

    q.push(make_pair(
        root, make_pair(0, 0)));  // root at horizontal distance 0, level 0
    while (!q.empty()) {
      pair<TreeNode*, pair<int, int>> temp = q.front();
      q.pop();
      TreeNode* front_node = temp.first;
      int hd = temp.second.first;      // horizontal distance
      int level = temp.second.second;  // vertical level

      nodes[hd][level].push_back(
          front_node->val);  // Add node value at this position

      // Push left and right children with updated positions
      if (front_node->left != nullptr) {
        q.push(make_pair(front_node->left, make_pair(hd - 1, level + 1)));
      }
      if (front_node->right != nullptr) {
        q.push(make_pair(front_node->right, make_pair(hd + 1, level + 1)));
      }
    }

    // Now, process the nodes and prepare the final answer
    for (auto& hd_pair : nodes) {
      vector<int> vertical;  // Collect all values at this horizontal distance
      for (auto& level_pair : hd_pair.second) {
        sort(level_pair.second.begin(),
             level_pair.second.end());  // Sort values at each level
        for (int val : level_pair.second) {
          vertical.push_back(val);
        }
      }
      ans.push_back(vertical);  // Add the sorted values for this vertical slice
    }

    return ans;
  }
};
