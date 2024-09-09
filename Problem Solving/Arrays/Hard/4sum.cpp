#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++) {
      if (i > 0 && arr[i] == arr[i - 1]) continue;

      for (int j = i + 1; j < arr.size(); j++) {
        if (j != (i + 1) && arr[j] == arr[j - 1]) continue;

        int k = j + 1;
        int l = arr.size() - 1;

        while (k < l) {
          int sum = arr[i] + arr[j] + arr[k] + arr[l];

          if (sum == target) {
            vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
            ans.push_back(temp);
            k++;
            l--;

            while (k < l && arr[k] == arr[k + 1]) k++;
            while (k < l && arr[l] == arr[l - 1]) l--;
          }

          else if (sum < target) {
            k++;
          } else {
            l--;
          }
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
    int target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // cout << solution.solve() << endl;
    vector<vector<int>> ans = solution.fourSum(arr, target);

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