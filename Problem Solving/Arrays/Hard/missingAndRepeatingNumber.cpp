#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> findTwoElement(vector<int> arr, int n) {
    vector<int> hash(n + 1, 0);
    int missing = -1;
    int repeating = -1;

    for (int i = 0; i < n; i++) {
      hash[arr[i]]++;
    }
    for (int i = 1; i <= n; i++) {
      if (hash[i] == 0)
        missing = i;
      else if (hash[i] == 2)
        repeating = i;
      if (missing != -1 && repeating != -1) break;
    }

    return {missing, repeating};
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
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans = solution.findTwoElement(arr, n);
    for (int i = 0; i < ans.size(); i++) cout << arr[i] << " ";
    cout << "\n";
    // cout << solution.findTwoElement(arr, n) << endl << endl;
  }

  return 0;
}