#include <bits-stdc++.h>
using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      result = result ^ nums[i];  // XOR operation
    }
    return result;
  }
};
