
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int solve(vector<int>& arr, int target) {
    int counter = 0;
    for (int i = 0; i < arr.size(); i++) {
      for (int j = 0; j < arr.size(); j++) {
        int XOR = 0;
        for (int k = i; k < j; k++) {
          XOR = XOR ^ arr[k];
        }

        if (XOR == target) {
          counter++;
        }
      }
    }

    return counter;
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
    int target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    cout << solution.solve(arr, target) << endl << endl;
  }

  return 0;
}