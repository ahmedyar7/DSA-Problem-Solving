#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& arr) {
    // size of array
    int n = arr.size();

    //. Checking for the edge cases

    // 1. Single element in array
    if (n == 1) return arr[0];

    // 2. Checking the first and 2nd element
    if (arr[0] != arr[1]) return arr[0];

    // 3. Checking if last and 2nd last element
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    //. Binary Search
    int low = 0;
    int high = n - 2;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      // Checking if the mid element and the element left and right to it are
      // same or not
      if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) return arr[mid];

      /*
        1. If the mid is even and the mid element and the element next to it i.e
        mid+1 are same then this mean that the mid element is still on the right
        half

        2. If the mid is odd and the mid element and the element previous to it
        i.e mid-1 are same then this means that the element is still on the
        right half.

        3. In both the condition we need to eliminate the right half

        4. Else condition do the same and remove the right half
      */

      if (mid % 2 == 0 && arr[mid] == arr[mid + 1] ||
          (mid % 2 == 1 && arr[mid] == arr[mid - 1])) {
        low = mid + 1;
      } else {
        high = mid - 1;
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
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solution.singleNonDuplicate(arr) << endl;
  }

  return 0;
}