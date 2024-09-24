#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int first_occurence(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int first = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (arr[mid] == target) {
        first = mid;
        high = mid - 1;
      } else if (arr[mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return first;
  }

  int last_occurence(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int last = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == target) {
        last = mid;
        low = mid + 1;
      } else if (arr[mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }

    return last;
  }

  int count(int arr[], int n, int x) {
    int first = first_occurence(arr, n, x);
    int last = last_occurence(arr, n, x);
    if (first == -1 || last == -1) return 0;
    return last - first + 1;
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
    int arr[10000];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solution.count(arr, n, target) << endl;
  }

  return 0;
}