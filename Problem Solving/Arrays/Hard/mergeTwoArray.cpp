#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void merge(vector<int>& arr, int m, vector<int>& arr2, int n) {
    for (int j = 0, i = m; j < n; j++) {
      arr[i] = arr2[j];
      i++;
    }
    sort(arr.begin(), arr.end());
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
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> arr(n1), arr2(n2);

    for (int i = 0; i < n1; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < n2; i++) {
      cin >> arr2[i];
    }
    solution.merge(arr, n1, arr2, n2);
    // cout <<  << endl << endl;
  }
  return 0;
}