#include <bits-stdc++.h>
using namespace std;

class Solution {
 public:
  void reverse(vector<int>& nums, int left, int right) {
    while (left < right) {
      swap(nums[left], nums[right]);
      left++, right--;
    }

    return;
  }

  void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    // Reverse entire array
    reverse(nums, 0, nums.size() - 1);
    // Reverse left
    reverse(nums, 0, k - 1);
    // Reverse right
    reverse(nums, k + 1, nums.size() - 1);

    return;
  }
};