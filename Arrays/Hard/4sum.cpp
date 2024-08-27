#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& arr, int target) {
    int n = arr.size();

    sort(arr.begin(), arr.end());  // This is because to avoid the duplicates in
                                   // the sorted array
    vector<vector<int>> ans;       // This will store the quads of element

    for (int i = 0; i < n; i++) {
      if (i > 0 && arr[i] == arr[i - 1])
        continue;  // This will make sure no duplicate ith element
      for (int j = i + 1; j < n; j++) {
        if (j > (i + 1) && arr[j] == arr[j - 1])
          continue;  // This will make sure no duplicate jth element

        int k = j + 1;  // 3rd element of array
        int l = n - 1;  // Last element of array

        while (k < l) {  // untill the k donot crosses the l element
          long long sum = arr[i] + arr[j] + arr[k] + arr[l];

          if (sum == target) {
            vector<int> temp = {
                arr[i], arr[j], arr[k],
                arr[l]};  // This would add all the elements to the temp vector

            ans.push_back(temp);
            k++;
            l--;

            // After adding changing the k and l position
            while (k < l && arr[k] == arr[k - 1]) k++;
            while (k < l && arr[l] == arr[l + 1]) l--;
          }
          // if sum is short of target then
          else if (sum < target)
            k++;
          else
            l--;
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