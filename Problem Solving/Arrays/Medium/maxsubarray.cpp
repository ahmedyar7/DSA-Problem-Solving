#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSubArray_BRUTE(vector<int>& arr) {
    int n = arr.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += arr[j];

        maxi = max(sum, maxi);
      }
    }
    return maxi;
  }
  int Kadane_Algorith(vector<int>& arr) {
    int sum = 0;
    int maxi = arr[0];

    for (int i = 0; i < arr.size(); i++) {
      sum += arr[i];
      if (sum > maxi) maxi = sum;
      if (sum < 0) sum = 0;
    }
    return maxi;
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
    cout << solution.Kadane_Algorith(arr) << endl;
  }

  return 0;
}