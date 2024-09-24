#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int xorOperation(int n, int start) {
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
      arr[i] = start + 2 * i;
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
      result = result ^ arr[i];
    }

    return result;
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
    int start;
    cin >> n >> start;
    // solution.xorOperation(n, start);
    cout << solution.xorOperation(n, start) << endl << endl;
  }

  return 0;
}