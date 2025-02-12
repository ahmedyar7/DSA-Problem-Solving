#include <bits-stdc++.h>
using namespace std;

class Solution {
 public:
  // Better Approach
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> hashmap;

    for (int i = 0; i < nums.size(); i++) {
      int requried = target - nums[i];

      if (hashmap.find(requried) != hashmap.end()) {
        return {hashmap[requried], i};
      }
      hashmap[nums[i]] = i;
    }
    return {-1, -1};
  }

  // Optimal Approach
  vector<int> twoSum_2(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    sort(nums.begin(), nums.end());

    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum == target)
        return {left, right};

      else if (left < right)
        left++;
      else
        right++;
    }
    return {-1, -1};
  }
};