#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxLen(vector<int>& arr, int n) {
    int sum = 0;       // This will store the sum of array
    int maxi_arr = 0;  // This will store the maxium subarray
    map<int, int> mpp;

    for (int i = 0; i < n; i++) {
      sum += arr[i];  // This will add the element while traversing once

      if (sum == 0) {  // This will check wether the sum = 0 or not
        maxi_arr =
            i +
            1;  // If yes then adding the till that very index to the maxi_arr
      }

      else {
        if (mpp.find(sum) != mpp.end()) {
          maxi_arr = max(maxi_arr, i - mpp[sum]);
        } else {
          mpp[sum] = i;
        }
      }
    }

    return maxi_arr;
  }

  vector<int> twoSum(vector<int>& arr, int target) {
    map<int, int> hashmap;

    for (int i = 0; i < arr.size(); i++) {
      int req = target - arr[i];

      if (hashmap.find(req) != hashmap.end()) {
        return {hashmap[req] + 1, i + 1};
      } else {
        hashmap[arr[i]] = i;
      }
    }

    return {-1, -1};
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
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    // cout << solution.maxLen(arr, n) << endl << endl;

    vector<int> ans = solution.twoSum(arr, target);
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }

  return 0;
}