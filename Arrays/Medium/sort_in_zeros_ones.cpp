#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& arr) {
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == 0)
        c0++;
      else if (arr[i] == 1)
        c1++;
      else
        c2++;
    }

    for (int i = 0; i < c0; i++) arr[i] = 0;
    for (int i = c0; i < c0 + c1; i++) arr[i] = 1;
    for (int i = c0 + c1; i < arr.size(); i++) arr[i] = 2;
  }
  void Dutch_National_Flag(vector<int>& arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

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

    solution.sortColors(arr);
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
