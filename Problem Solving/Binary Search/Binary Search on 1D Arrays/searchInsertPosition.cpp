#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
      int mid = (low + high) / 2;

      if (arr[mid] >= target) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
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
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solution.searchInsert(arr, target) << endl;
  }

  return 0;
}