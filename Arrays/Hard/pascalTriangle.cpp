#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    // code here
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