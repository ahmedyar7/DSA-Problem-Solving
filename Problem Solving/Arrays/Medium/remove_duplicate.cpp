#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;

    for (auto it : nums) {
      if (i > 2 || it > nums[i - 2]) {
        nums[i++] = it;
      }
    }

    return i;
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
    cout << solution.removeDuplicates(arr) << endl << endl;
  }

  return 0;
}