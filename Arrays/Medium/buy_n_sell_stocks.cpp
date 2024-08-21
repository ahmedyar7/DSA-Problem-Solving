#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& arr) {
    int mini = arr[0];
    int profit = 0;

    for (int i = 0; i < arr.size(); i++) {
      int cost = arr[i] - mini;
      profit = max(profit, cost);
      mini = min(mini, arr[i]);
    }
    return profit;
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
    cout << solution.maxProfit(arr) << endl;
  }

  return 0;
}