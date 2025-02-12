#include <bits-stdc++.h>
using namespace std;

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& arr) {
    int n = arr.size();
    int counter = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++) {
      if (arr[i] == 1) {
        counter++;
        maxi = max(maxi, counter);

      } else {
        counter = 0;
      }
    }

    return maxi;
  }
};