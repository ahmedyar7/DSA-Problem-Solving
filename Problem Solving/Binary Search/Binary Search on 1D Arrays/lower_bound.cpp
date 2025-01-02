#include <bits-stdc++.h>

using namespace std;

class Solution {
 public:
  int findFloor(vector<long long> &arr, long long n, long long target) {
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high) {
      int mid = low + (high - low) / 2;

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
    long long n, x;
    cin >> n >> x;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solution.findFloor(arr, n, x) << endl;
  }

  return 0;
}