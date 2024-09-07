#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {}
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
    cout << solution.singleNonDuplicate(arr) << endl;
  }

  return 0;
}