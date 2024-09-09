#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long int floorSqrt(long long int n) {
    int low = 0;
    int high = n;
    int ans = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (mid * mid <= n) {
        ans = mid;
        low = mid + 1;
      }
      high = mid - 1;
    }
    return ans + 1, high + 1;
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
    long long int n;
    cin >> n;
    cout << solution.floorSqrt(n) << endl;
  }

  return 0;
}