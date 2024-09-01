#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
      int start = arr[i][0];
      int end = arr[i][1];

      if (!ans.empty() && end <= ans.back()[1]) {
        continue;
      }

      for (int j = i + 1; j < n; j++) {
        if (arr[j][0] <= end) {
          end = max(end, arr[j][1]);
        } else {
          break;
        }
      }

      ans.push_back({start, end});
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

    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans[0].size(); j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}