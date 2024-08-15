#include <vector>
using namespace std;

bool check(vector<int>& nums) {
  int countDrops = 0;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    if (nums[i] > nums[(i + 1) % n]) {
      countDrops++;
    }
    if (countDrops > 1) {
      return false;  // More than one "drop", so not a rotated sorted array
    }
  }

  return true;
}
