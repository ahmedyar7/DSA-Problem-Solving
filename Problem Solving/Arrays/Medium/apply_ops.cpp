#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> applyOperations(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        nums[i] = nums[i] * 2;
        nums[i + 1] = 0;
      }
    }

    int i = 0;
    int j = 0;
    while (j < nums.size()) {
      if (nums[j] == 0) {
        j++;
      } else {
        swap(nums[i], nums[j]);
        i++;
        j++;
      }
    }

    return nums;
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
    vector<int> result = solution.applyOperations(arr);
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;
    // cout << solution.solve() << endl << endl;
  }

  return 0;
}