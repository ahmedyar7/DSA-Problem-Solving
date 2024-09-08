#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& arr) {
    // array size
    int n = arr.size();

    /*
        CHECKING FOR EGDGE CASES:

            1. When size is 1 then return arr[0] as peak element
            2. Checking 1st and 2nd element if first > 2nd element return 1st
               element
            3. Checking the last and 2nd last element if last > 2nd last element
               return the last element
    */

    // 1.
    if (n == 1) return 0;

    // 2.
    if (arr[0] > arr[1]) return 0;

    // 3.
    if (arr[n - 1] > arr[n - 2]) return arr[n - 1];

    // Binary Search

    int low = 1;
    int high = n - 2;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      // arr[mid-1] < arr[mid] > arr[mid+1]
      if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        return mid;

      else if (arr[mid] > arr[mid - 1])
        low = mid + 1;
      else
        high = mid - 1;
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
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solution.findPeakElement(arr) << endl;
  }

  return 0;
}