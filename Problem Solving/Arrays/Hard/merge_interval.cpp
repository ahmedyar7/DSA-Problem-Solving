#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
      if (ans.empty() || arr.back()[1] > ans[i][1]) {
        ans.push_back(arr[i]);
      } else {
        ans.back()[1] = max(arr.back()[1], ans[i][1]);
      }
    }

    return ans;
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
      }
    }

    vector<vector<int>> ans = solution.merge(arr);

    for (auto it : ans) {
      cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
  }

  return 0;
}