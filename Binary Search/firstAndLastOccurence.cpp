#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lower_bound_function(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] >= target) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }

  int upper_bound_function(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] > target) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return ans;
  }

  int first_occurence(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int first = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (arr[mid] == target) {
        first = mid;
        high = mid - 1;
      } else if (arr[mid] < target) {
        low = mid + 1;
      } else
        low = mid + 1;
    }
    return first;
  }

  int last_occurence(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size();
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

  vector<int> searchRange(vector<int>& arr, int target) {
    // int lower_bound = lower_bound_function(arr, target);

    // if (lower_bound == arr.size() || arr[lower_bound] != target)
    //   return {-1, -1};
    // return {lower_bound, upper_bound_function(arr, target) - 1};

    int first_occ = first_occurence(arr, target);
    if (first_occ == -1) return {-1, -1};
    int last_occ = last_occurence(arr, target);
    return {first_occ, last_occ};
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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> result = solution.searchRange(arr, x);

    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;
  }

  return 0;
}