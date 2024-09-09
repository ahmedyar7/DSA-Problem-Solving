#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& arr) {
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] >= 0) {
        pos.push_back(arr[i]);
      } else {
        neg.push_back(arr[i]);
      }
    }
    for (int i = 0; i < arr.size() / 2; i++) {
      arr[i * 2] = pos[i];
      arr[i * 2 - 1] = neg[i];
    }

    return arr;
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
    // cout << solution.rearrangeArray(arr) << endl;
    vector<int> result = solution.rearrangeArray(arr);
    for (auto it : result) {
      cout << it << " ";
    }
    cout << endl;
  }

  return 0;
}