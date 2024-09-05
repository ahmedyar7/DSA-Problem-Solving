#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int search(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (left <= right) {
      int mid = low - (low + high) / 2;

      if (arr[mid] == target) {
        return mid;
      } else if (target > arr[mid]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
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
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solution.search(arr, target) << endl;
  }

  return 0;
}