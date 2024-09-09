#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxLen(vector<int>& arr, int n) {
    unordered_map<int, int> hashmap;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];

      if (sum == 0) {
        maxi = i + 1;
      }

      else {
        if (hashmap.find(sum) != hashmap.end()) {
          maxi = max(maxi, i - hashmap[sum]);
        } else {
          hashmap[sum] = i;
        }
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
    cout << solution.maxLen(arr, n) << endl << endl;
  }

  return 0;
}