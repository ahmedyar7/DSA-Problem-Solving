#include <bits-stdc++.h>
using namespace std;

class Solution {
 public:
  //  Brute Force Approach
  vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> positives(0);
    vector<int> negatives(0);
    vector<int> result(nums.size(), 0);

    // Storing +ve & -ve
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 0)
        negatives.push_back(nums[i]);
      else
        positives.push_back(nums[i]);
    }

    // nums.size()/2 and not nums.size()
    // This is because both the pos and neg include n/2 elements
    // and they would be not able to access beyound this
    //  causing runtime error

    for (int i = 0; i < nums.size() / 2; i++) {
      result[2 * i] = positives[i];
      result[2 * i + 1] = negatives[i];
    }

    return result;
  }

  // Varitey-2: Number of +vs and -ve are not equal
  vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> positives(0);
    vector<int> negatives(0);
    vector<int> result(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 0)
        negatives.push_back(nums[i]);
      else
        positives.push_back(nums[i]);
    }

    int finalSize = 0;
    if (positives.size() != negatives.size()) {
      if (positives.size() > negatives.size()) {
        finalSize = positives.size();
      } else {
        finalSize = negatives.size();
      }
    } else {
      finalSize = nums.size() / 2;
    }

    for (int i = 0; i < finalSize; i++) {
      if (i < positives.size())  // Only access if index is valid
        result[2 * i] = positives[i];

      if (i < negatives.size())  // Only access if index is valid
        result[2 * i + 1] = negatives[i];
    }

    return result;
  }
};
