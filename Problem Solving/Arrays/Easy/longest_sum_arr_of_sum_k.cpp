#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lenOfLongSubarr_BETTER_APPROACH(int A[], int n, int K) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += A[j];
        if (sum == K) {
          ans = max(ans, j - i + 1);
        }
      }
    }

    return ans;
  }

  int lenOfLongSubarr_OPTIMAL_APPROACH(int arr[], int n, int k) {
    // unordered_map 'um' implemented
    // as hash table
    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;

    // traverse the given array
    for (int i = 0; i < n; i++) {
      // accumulate sum
      sum += arr[i];

      // when subarray starts from index '0'
      if (sum == k) maxLen = i + 1;

      // make an entry for 'sum' if it is
      // not present in 'um'
      if (um.find(sum) == um.end()) um[sum] = i;

      // check if 'sum-k' is present in 'um'
      // or not
      if (um.find(sum - k) != um.end()) {
        // update maxLength
        if (maxLen < (i - um[sum - k])) maxLen = i - um[sum - k];
      }
    }

    // required maximum length
    return maxLen;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  cin >> t;
  Solution solution;
  while (t--) {
    int n;
    int k;
    cin >> n >> k;
    int arr[10];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << solution.lenOfLongSubarr_OPTIMAL_APPROACH(arr, n, k) << endl;
  }

  return 0;
}