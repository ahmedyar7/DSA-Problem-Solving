#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++) {
      if (i > 0 && arr[i] == arr[i - 1]) continue;

      int j = i + 1, k = arr.size() - 1;

      while (j < k) {
        int sum = arr[i] + arr[j] + arr[k];

        if (sum == 0) {
          vector<int> temp = {arr[i], arr[j], arr[k]};
          ans.push_back(temp);
          j++;
          k--;

          while (j < k && arr[k] == arr[k + 1]) k--;
          while (j < k && arr[j] == arr[j - 1]) j++;
        }

        else if (sum < 0) {
          j++;
        } else {
          k--;
        }
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // cout << solution.solve() << endl << endl;

    vector<vector<int>> ans = solution.threeSum(arr);

    for (int i = 0; ans.size(); i++) {
      for (int j = 0; j < ans[0].size(); j++) {
        cout << ans[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}