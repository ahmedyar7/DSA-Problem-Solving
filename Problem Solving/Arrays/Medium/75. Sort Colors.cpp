#include <bits-stdc++.h>
using namespace std;

class Solution {
 public:
  // Brute Force
  void sortColors(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return;
  }

  // Better Approach
  void sortColors_2(vector<int>& nums) {
    int counter0 = 0;
    int counter1 = 0;
    int counter2 = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0)
        counter0++;
      else if (nums[i] == 1)
        counter1++;
      else
        counter2++;
    }

    for (int i = 0; i < counter0; i++) nums[i] = 0;
    for (int i = counter0; i < counter0 + counter1; i++) nums[i] = 1;
    for (int i = counter0 + counter1; i < nums.size(); i++) nums[i] = 2;

    return;
  }

  // Optimal Approach: Dutch National Flag Algorithm
  void sortColors_3(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size();

    for (int i = 0; i < nums.size(); i++) {
      if (nums[mid] == 0) {
        swap(nums[mid], nums[low]);
        low++;
        mid++;
      } else if (nums[mid] == 1) {
        mid++;
      } else {
        swap(nums[mid], nums[high]);
        high--;
      }
    }

    return;
  }
};