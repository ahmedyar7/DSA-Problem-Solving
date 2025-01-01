#include <bits-stdc++.h>
using namespace std;

class Solution {
 public:
  // int findKRotation(vector<int> &arr) {
  //   int low = 0;
  //   int high = arr.size() - 1;
  //   int ans = INT_MAX;
  //   int index = -1;

  //   while (low <= high) {
  //     int mid = low + (high - low) / 2;
  //     if (arr[low] <= arr[mid]) {
  //       if (arr[low] < ans) {
  //         index = low;
  //         ans = arr[low];
  //       }
  //       low = mid + 1;
  //     } else {
  //       if (arr[mid] < ans) {
  //         index = mid;
  //         ans = arr[mid];
  //       }
  //       high = mid - 1;
  //     }
  //   }
  //   return index;
  // }

  int findKRotation(vector<int> &arr) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();
    int index = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[low] <= arr[mid]) {
        if (arr[low] < ans) {
          index = low;
          ans = arr[low];
        }
        low = mid + 1;
      } else {
        if (arr[mid] < ans) {
          index = mid;
          ans = arr[mid];
        }
        high = mid - 1;
      }
    }
    return index;
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
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solution.findKRotation(arr) << endl;
  }

  return 0;
}