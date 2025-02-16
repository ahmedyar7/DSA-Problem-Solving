#include <bits-stdc++.h>
using namespace std;

class Solution {
 public:
  // Brute Force Approach
  int removeDuplicates(vector<int>& nums) {
    set<int> st;
    for (auto it : nums) {
      st.insert(it);
    }

    int index = 0;
    for (auto it : st) {
      nums[index] = it;
      index++;
    }

    return st.size();
  }

  // Optimal Approach
  int removeDuplicates_2(vector<int>& arr) {
    int n = arr.size();
    int i = 0;

    for (int j = 1; j < n; j++) {
      if (arr[i] != arr[j]) {
        arr[i + 1] = arr[j];
        i++;
      }
    }
    return i + 1;
  }
};

/*
    Brute Force:
    1. Placing all the elments in set
    2. Itterate over the set to place element at
    the start of array
    3. return size of sets


    Optimal Approach:
    1. Placing two pointer on 0th and 1st index
    2. Traversing throught the array
    3. Moving them until they same
    4. When the fall on same value the second would take the
    place of the first pointer
*/
