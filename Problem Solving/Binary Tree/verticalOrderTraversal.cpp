#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};

    // Map to store nodes: {column -> {row, value}}
    map<int, vector<pair<int, int>>> nodes;

    // Queue for BFS: {node, row, column}
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()) {
      auto [node, position] = q.front();
      q.pop();
      int row = position.first, col = position.second;

      // Add the node value with its row and column
      nodes[col].push_back({row, node->val});

      // Process left and right children
      if (node->left) q.push({node->left, {row + 1, col - 1}});
      if (node->right) q.push({node->right, {row + 1, col + 1}});
    }

    // Prepare the result
    vector<vector<int>> result;
    for (auto& [col, vec] : nodes) {
      // Sort by row first, then by value
      sort(vec.begin(), vec.end());
      vector<int> column;
      for (auto& [row, value] : vec) {
        column.push_back(value);
      }
      result.push_back(column);
    }

    return result;
  }
};

// Helper function to build a binary tree from vector input
TreeNode* buildTree(const vector<int>& nodes) {
  if (nodes.empty()) return nullptr;

  TreeNode* root = new TreeNode(nodes[0]);
  queue<TreeNode*> q;
  q.push(root);
  int i = 1;

  while (i < nodes.size()) {
    TreeNode* curr = q.front();
    q.pop();

    if (i < nodes.size() && nodes[i] != -1) {
      curr->left = new TreeNode(nodes[i]);
      q.push(curr->left);
    }
    i++;

    if (i < nodes.size() && nodes[i] != -1) {
      curr->right = new TreeNode(nodes[i]);
      q.push(curr->right);
    }
    i++;
  }
  return root;
}

// Main function to test the solution
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  Solution solution;

  // Example 1
  vector<int> tree1 = {3, 9, 20, -1, -1, 15, 7};
  TreeNode* root1 = buildTree(tree1);
  vector<vector<int>> result1 = solution.verticalTraversal(root1);
  for (const auto& col : result1) {
    for (int val : col) {
      cout << val << " ";
    }
    cout << endl;
  }
  cout << endl;

  // Example 2
  vector<int> tree2 = {1, 2, 3, 4, 5, 6, 7};
  TreeNode* root2 = buildTree(tree2);
  vector<vector<int>> result2 = solution.verticalTraversal(root2);
  for (const auto& col : result2) {
    for (int val : col) {
      cout << val << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
