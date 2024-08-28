#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& arr) {
    int n = arr.size();
    int target = 0;
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
      if (i > 0 && arr[i] == arr[i - 1]) continue;

      int j = i + 1;
      int k = n - 1;

      while (j < k) {
        int sum = arr[i] + arr[j] + arr[k];
        if (sum == target) {
          vector<int> temp = {arr[i], arr[j], arr[k]};
          j++;
          k--;

          while (j < k && arr[j] == arr[j - 1]) j++;
          while (j < k && arr[k] == arr[k + 1]) k--;
        } else if (sum < target)
          j++;
        else
          k--;
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
    int target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // cout << solution.solve() << endl;
    vector<vector<int>> ans = solution.threeSum(arr, target);

    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans[0].size(); j++) {
        cout << ans[i][j] << " ";
      }
      cout << " ";
    }
    cout << endl << endl;
  }

  return 0;
}