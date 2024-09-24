#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    for (int i = 0; i < numRows; i++) {
      vector<int> row(i + 1, 1);
      for (int j = 1; j < i; j++) {
        row[j] = result[i - 1][j - 1] + result[i - 1][j];
      }
      result.push_back(row);
    }
    return result;
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
    int numRows;
    cin >> numRows;
    vector<vector<int>> result = solution.generate(numRows);
    for (const auto& row : result) {
      for (int val : row) {
        cout << val << " ";
      }
      cout << endl;
    }
  }

  return 0;
}