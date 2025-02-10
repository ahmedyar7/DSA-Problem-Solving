#include <bits-stdc++.h>
using namespace std;

class Solution {
 public:
  void reverse(vector<int>& nums, int left, int right) {
    while (left < right) {
      swap(nums[left], nums[right]);

      left++;
      right--;
    }
  }
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    // Reverse the entire array
    reverse(nums, 0, n - 1);

    // Reverse first k elements
    reverse(nums, 0, k - 1);

    // Reverse remaining n-k elements
    reverse(nums, k, n - 1);

    return;
  }
};