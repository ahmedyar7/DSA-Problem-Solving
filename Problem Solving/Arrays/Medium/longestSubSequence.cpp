#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& arr) {
    if (arr.size() == 0) return 0;
    set<int> st(arr.begin(), arr.end());
    int longest = 0;

    for (auto it : st) {
      if (st.find(it - 1) == st.end()) {
        int count = 1;
        int x = it;

        while (st.find(x + 1) != st.end()) {
          x = x + 1;
          count = count + 1;
        }
        longest = max(longest, count);
      }
    }

    return longest;
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
    cout << solution.longestConsecutive(arr) << endl;
  }

  return 0;
}