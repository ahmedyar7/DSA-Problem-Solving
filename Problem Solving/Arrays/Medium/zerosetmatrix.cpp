#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();

    vector<int> row(n, 0);
    vector<int> cols(m, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (arr[i][j] == 0) {
          row[i] = 1;
          cols[j] = 1;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (row[i] == 1 || cols[j] == 1) {
          arr[i][j] = 0;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
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
    solution.setZeroes(arr);
  }

  return 0;
}
