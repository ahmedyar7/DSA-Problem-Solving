#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& arr) {
    next_permutation(arr.begin(), arr.end());
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
    // cout << solution.nextPermutation(arr) << endl;
    solution.nextPermutation(arr);

    for (auto it : arr) {
      cout << it << " ";
    }
    cout << endl;
  }

  return 0;
}