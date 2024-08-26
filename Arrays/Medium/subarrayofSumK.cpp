#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& arr, int k) {
    map<int, int> hashmap;
    int prefixSum = 0;
    int counter = 0;
    hashmap[0] = 1;

    for (int i = 0; i < arr.size(); i++) {
      prefixSum += arr[i];
      int remove = prefixSum - k;
      counter += hashmap[remove];
      hashmap[prefixSum] += 1;
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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    cout << solution.subarraySum(arr, k) << endl;
  }

  return 0;
}