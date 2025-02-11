#include <bits-stdc++.h>
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> hashmap;

    for (auto it : nums) {
      hashmap[it]++;
    }

    for (auto it : hashmap) {
      if (it.second > nums.size() / 2) {
        return it.first;
      }
    }
    return 0;
  }
};