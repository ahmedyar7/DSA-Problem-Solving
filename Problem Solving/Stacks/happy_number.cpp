#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int sum_of_squares(int n) {
    int output = 0;
    while (n != 0) {
      int digit = n % 10;
      output += digit * digit;
      n = n / 10;
    }
    return output;
  }

  bool isHappy(int n) {
    std::set<int> st;
    while (st.find(n) == st.end()) {
      st.insert(n);
      n = sum_of_squares(n);

      if (n == 1) {
        return true;  // The number is happy
      }
    }
    return false;  // A cycle was detected, so the number is not happy
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
    cout << solution.isHappy(n) << endl;
  }

  return 0;
}
