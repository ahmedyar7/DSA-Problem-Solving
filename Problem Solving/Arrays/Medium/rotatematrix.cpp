#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& arr) {
    // code
    int n = arr.size();
    int m = arr[0].size();

    // Transpose the matrix
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < m; j++) {
        swap(arr[i][j], arr[j][i]);
      }
    }

    // Reverse each row
    for (int i = 0; i < n; i++) {
      reverse(arr[i].begin(), arr[i].end());
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
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
    solution.rotate(arr);
  }

  return 0;
}
