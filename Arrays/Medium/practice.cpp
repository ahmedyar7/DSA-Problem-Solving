#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& arr, int target) {
    map<int, int> hashed;
    for (int i = 0; i < arr.size(); i++) {
      int req = target - arr[i];
      if (hashed.find(req) != hashed.end()) {
        return {hashed[req], i};
      }
      hashed[arr[i]] = i;
    }

    return {-1, -1};
  }

  void sortColors(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
      if (arr[mid] == 0) {
        swap(arr[low], arr[mid]);
        low++;
        mid++;
      } else if (arr[mid] == 1) {
        mid++;
      } else {
        swap(arr[mid], arr[high]);
        high--;
      }
    }
  }

  int majorityElement(vector<int>& arr) {
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
    // solution.majorityElement(arr);
    cout << solution.majorityElement(arr) << endl;
    // vector<int> answer = solution.twoSum(arr, target);
    // for (int i = 0; i < n; i++) {
    //   cout << arr[i] << " ";
    // }
    // cout << endl;
  }

  return 0;
}