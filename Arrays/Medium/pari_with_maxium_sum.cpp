#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int pairWithMaxSum(vector<int> &arr) {
    if (arr.size() < 2) {
      return -1;
    }
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size() - 1; i++) {
      sum = arr[i] + arr[i + 1];
      if (sum > maxi) {
        maxi = sum;
      }
    }
    return maxi;
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
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << solution.pairWithMaxSum(arr) << endl;
  }

  return 0;
}