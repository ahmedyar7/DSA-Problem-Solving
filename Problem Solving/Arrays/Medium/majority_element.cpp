#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  //. BRUTE FORCE APPROACH
  int majorityElement_BRUTE_FORCE(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
      int count = 0;
      for (int j = 0; j < arr.size(); j++) {
        if (arr[i] == arr[j]) {
          count++;
        }
        if (count > arr.size() / 2) {
          return arr[i];
        }
      }
    }
  }

  //. BETTER APPROACh
  int majorityElement_BETTER(vector<int>& arr) {
    map<int, int> hashed;
    for (auto it : arr) {
      hashed[it]++;
    }
    for (auto it : hashed) {
      if (it.second > arr.size() / 2) {
        return it.first;
      }
    }
    return -1;
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
    cout << solution.majorityElement_BETTER(arr) << endl;
    // solution.majorityElement(arr);
  }

  return 0;
}