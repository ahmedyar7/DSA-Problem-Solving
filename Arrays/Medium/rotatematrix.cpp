#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& arr) {}
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
    solution.rotate(arr);
  }

  return 0;
}
