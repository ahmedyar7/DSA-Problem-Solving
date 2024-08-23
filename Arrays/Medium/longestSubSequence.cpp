#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int longest = 1;
    int counter = 0;
    int last_smaller = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] - 1 == last_smaller) {
        counter++;
        last_smaller = arr[i];
      } else if (last_smaller != arr[i]) {
        counter = 1;
        last_smaller = arr[i];
      }
      longest = max(longest, counter);
    }
    return longest;
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
    cout << solution.longestConsecutive(arr) << endl;
  }

  return 0;
}