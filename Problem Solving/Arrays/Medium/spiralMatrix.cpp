#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    int top = 0;  // Initialize top
    int left = 0;
    int bottom = n - 1;
    int right = m - 1;

    vector<int> ans;

    while (top <= bottom && left <= right) {
      for (int i = left; i <= right; i++) {
        ans.push_back(arr[top][i]);
      }
      top++;

      for (int i = top; i <= bottom; i++) {
        ans.push_back(arr[i][right]);
      }
      right--;

      for (int i = right; i >= left; i--) {
        ans.push_back(arr[bottom][i]);
      }
      bottom--;

      for (int i = bottom; i >= top; i--) {
        ans.push_back(arr[i][left]);
      }
      left++;
    }

    return ans;  // Return the final spiral order
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  Solution solution;
  while (t--) {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> arr(rows, vector<int>(cols));

    // Reading the matrix elements
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        cin >> arr[i][j];
      }
    }

    // cout << solution.setZeroes(matrix) << endl;
    vector<int> result = solution.spiralOrder(arr);

    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
