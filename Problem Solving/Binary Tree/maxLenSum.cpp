class Solution {
 public:
  void solve(Node *root, int sum, int &maxSum, int len, int &maxLen) {
    if (root == nullptr) {
      if (len > maxLen) {
        maxLen = len;
        maxSum = sum;
      } else if (len == maxLen) {
        maxSum = max(maxSum, sum);
      }
      return;
    }
    sum = sum + root->data;
    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
  }
  int sumOfLongRootToLeafPath(Node *root) {
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
  }
};