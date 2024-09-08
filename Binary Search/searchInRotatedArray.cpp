// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//  public:
// int search(vector<int>& arr, int target) {
//   int low = 0;
//   int high = arr.size() - 1;

//   while (low <= high) {
//     int mid = low + (high - low) / 2;
//     if (arr[mid] == target) return mid;
//     if (arr[low] <= arr[mid]) {
//       if (arr[low] <= target && target <= arr[mid])
//         high = mid - 1;
//       else
//         low = mid + 1;
//     } else {
//       if (arr[mid] <= target && target <= arr[high])
//         low = mid + 1;
//       else
//         high = mid - 1;
//     }
//   }
//   return -1;
// }

//   int search(vector<int>& arr, int target) {
//     int low = 0;
//     int high = arr.size() - 1;

//     while (low <= high) {
//       int mid = low + (high - low) / 2;

//       if (arr[mid] == target) return true;
//       if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
//         low++, high--;
//         continue;
//       }
//       if (arr[low] <= arr[mid]) {
//         if (arr[low] <= target && target <= arr[mid]) {
//           high = mid - 1;
//         } else
//           low = mid + 1;
//       } else {
//         if (arr[mid] <= target && target <= arr[high]) {
//           low = mid + 1;
//         } else {
//           high = mid - 1;
//         }
//       }
//     }
//     return false;
//   }
// };

// int main() {
// #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif

//   int t;
//   cin >> t;
//   Solution solution;
//   while (t--) {
//     int n;
//     int target;
//     cin >> n >> target;
//     vector<int> arr(n);

//     for (int i = 0; i < n; i++) {
//       cin >> arr[i];
//     }
// IIIIIIIIIIIIIiiiiiiicout << solution.search(arr, target) << endl; } return
// 0; }

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool search(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == target) return true;
      if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
        low++, high--;
        continue;
      }
      if (arr[low] <= arr[mid]) {
        if (arr[low] <= target && target <= arr[mid]) {
          high = mid - 1;
        } else
          low = mid + 1;
      } else {
        if (arr[mid] <= target && target <= arr[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }
    return false;
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
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solution.search(arr, target) << endl;
  }

  return 0;
}