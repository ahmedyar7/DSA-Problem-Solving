#include <bits/stdc++.h>
using namespace std;

// . BRUTE FORCE APPORACH
/*
- We will take a pointer and place it on the elements of 1st array
- Then we will iterate over the 2nd array and when we found the corresponding
element
- We will place it in the intersection array
- We will also maintain the visited array[] = 0
- When the element will be added to the intersection array we would increment
the index of visited array.s
*/

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    vector<int> result;

    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) {
        i++;
      } else if (nums1[i] > nums2[j]) {
        j++;
      } else {
        result.push_back(nums1[i]);
        i++;
        j++;
      }
    }

    return result;
  }
};