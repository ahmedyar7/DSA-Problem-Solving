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
    cout << solution.lenOfLongSubarr_BETTER_APPROACH(arr, n, k) << endl;
  }

  return 0;
}