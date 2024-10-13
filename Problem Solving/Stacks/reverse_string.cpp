#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      st.push(i);
    }
    for (int i = 0; i < s.size(); i++) {
      st.pop();
    }
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
    vector<char> vec(n);
    for (int i = 0; i < n; i++) vec.push_back(i);
    // cout << solution.reverseString() << endl;
    solution.reverseString(vec);
  }

  return 0;
}