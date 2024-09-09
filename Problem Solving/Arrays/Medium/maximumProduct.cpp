#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    int max_product = arr[0];
    int min_product = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
      if (arr[i] == 0) return 0;
      if (arr[i] < 0) swap(max_product, min_product);

      max_product = max(arr[i], max_product * arr[i]);
      min_product = min(arr[i], min_product * arr[i]);

      result = max(result, max_product);
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
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    cout << solution.maxProduct(arr) << endl;
  }

  return 0;
}