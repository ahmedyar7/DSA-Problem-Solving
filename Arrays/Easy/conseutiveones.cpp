#include <bits/stdc++.h>
using namespace std;

int consecutive_ones(vector<int>& arr) {
  int maxi = 0;
  int counter = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == 1) {
      counter++;
      maxi = max(maxi, counter);
    } else {
      counter = 0;
    }
  }
  return maxi;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;

  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << consecutive_ones(arr) << endl;
  }

  return 0;
}

//. ----- Approach ----- .//
/*
- Maintain the counter variable for the consecutive number of one's this would
increment with every number of one in the arry
- The maxi variable would store the maximum number of counter variable
- When the chain of the consecutive one's break the counter would be reset to
zero.
*/