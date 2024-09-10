#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int func_(int mid, int n) {
    long long ans = 1;
    while (n > 0) {
      if (n % 2 == 1) {
        ans = ans * mid;
        n = n - 1;
      } else {
        mid = mid * mid;
        n = n / 2;
      }
    }

    return mid;
  }

  int NthRoot(int n, int m) {
    int low = 1, high = m;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int midN = func_(mid, n);

      if (midN == m) {
        return mid;
      } else if (midN < m)
        low = mid + 1;
      else
        high = mid - 1;
    }

    return -1;
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
    int n, m;
    cin >> n >> m;
    cout << solution.NthRoot(n, m) << endl;
  }

  return 0;
}