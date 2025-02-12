#include <bits-stdc++.h>
using namespace std;

class Solution {
 public:
  // Brute Force Approach: Generate All the Subarrays: O(n^3)
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int sum = 0;
        for (int k = i; k <= j; k++) {
          sum += nums[k];
          maxi = max(maxi, sum);
        }
      }
    }
    return maxi;
  }

  // Better Approach Approach: Reducing Itterations: O(n^2)
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums[j];
        maxi = max(maxi, sum);
      }
    }
    return maxi;
  }

  // Optimal Approach: kadanae's Algorithm: O(n)
  int maxSubArray(vector<int>& nums) {
    long long sum = 0;
    long long maxi = LONG_MIN;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (sum < 0) sum = 0;
      if (sum > maxi) maxi = sum;
    }
    return maxi;
  }
};

/*
    Brute Force:
    - This approach includes the generation of all the sum array
    - Then calculation of there sum and finding the best sum
*/