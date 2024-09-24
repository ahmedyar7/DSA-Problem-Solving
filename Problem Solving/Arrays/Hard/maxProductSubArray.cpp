#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& arr) {
    int ans = INT_MIN;
    int prefix = 1, suffix = 1;

    for (int i = 0; i < arr.size(); i++) {
      if (prefix == 0) prefix = 1;
      if (suffix == 0) suffix = 1;

      prefix = prefix * arr[i];
      suffix = suffix * arr[i];

      ans = max(ans, max(prefix, suffix));
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << solution.maxProduct(arr) << endl << endl;
  }

  return 0;
}
