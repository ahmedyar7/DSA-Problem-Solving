#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findMin(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[low] <= arr[mid]) {
        ans = min(ans, arr[low]);
        low = mid + 1;
      }

      else {
        ans = min(ans, arr[mid]);
        high = mid - 1;
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
    cout << solution.findMin(arr) << endl;
  }

  return 0;
}