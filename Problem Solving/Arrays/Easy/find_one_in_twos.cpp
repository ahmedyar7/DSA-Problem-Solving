#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& arr) {
    unordered_map<int, int> hash;
    for (auto it : arr) {
      hash[it]++;
    }
    for (auto z : hash) {
      if (z.second == 1) {
        return z.first;
      }
    }
    return -1;
  }

  int findDuplicate(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> hash;
    for (auto it : arr) {
      hash[it]++;
    }
    for (auto z : hash) {
      if (z.second >= 2) {
        return z.first;
      }
    }
    return -1;
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
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << solution.singleNumber(arr) << endl;
  }

  return 0;
}