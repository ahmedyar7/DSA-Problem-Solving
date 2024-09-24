#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int count = 0;
  void merge(vector<long long>& arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<long long> temp;

    while (left <= mid && right <= high) {
      if (arr[left] <= arr[right]) {
        temp.push_back(arr[left]);
        left++;
      } else {
        temp.push_back(arr[right]);
        count += (mid - left + 1);
        right++;
      }
    }

    while (left <= mid) {
      temp.push_back(arr[left]);
      left++;
    }
    while (right <= high) {
      temp.push_back(arr[right]);
      right++;
    }

    for (int i = low; i <= high; i++) {
      arr[i] = temp[i - low];
    }
  }

  void merge_sort(vector<long long>& arr, int low, int high) {
    if (low < high) {
      int mid = (high + low) / 2;
      merge_sort(arr, low, mid);
      merge_sort(arr, mid + 1, high);
      merge(arr, low, mid, high);
    }
  }

  long long int inversionCount(vector<long long>& arr, int n) {
    merge_sort(arr, 0, n - 1);
    return count;
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
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << solution.inversionCount(arr, n) << endl;
  }

  return 0;
}