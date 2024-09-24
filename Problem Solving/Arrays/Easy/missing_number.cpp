#include <bits/stdc++.h>
using namespace std;

int missingNumber_BRUTE(vector<int>& arr) {
  int n = arr.size();
  vector<bool> present(n + 1, false);  // To mark the presence of numbers

  for (int i = 0; i < n; i++) {
    if (arr[i] < n) {
      present[arr[i]] = true;
    }
  }

  for (int i = 0; i <= n; i++) {
    if (!present[i]) {
      return i;
    }
  }

  return n;  // In case all numbers from 0 to n-1 are present, return n
}

int missingNumber_BETTER(vector<int>& arr) {
  int n = arr.size();

  // Initialize hash vector to track presence of numbers
  vector<int> hash(n + 1, 0);

  // Mark the numbers present in the array
  for (int i = 0; i < n; i++) {
    if (arr[i] < n) {
      hash[arr[i]] = 1;
    }
  }

  // Find the first missing number
  for (int i = 0; i <= n; i++) {
    if (hash[i] == 0) {
      return i;
    }
  }
}

int missingNumber_OPTIMAL(vector<int>& arr) {
  int n = arr.size();
  // Sum of first n natural numbers including 0 to n
  int sum = (n * (n + 1)) / 2;
  int s2 = 0;
  for (int i = 0; i < n; i++) {
    s2 += arr[i];
  }
  return (sum - s2);
}

int findMaxConsecutiveOnes(vector<int>& arr) {
  int n = arr.size();
  int maxi = 0;
  int counter = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      counter++;
      maxi = max(maxi, counter);
    } else {
      counter = 0;
    }
  }
  return maxi;
}

int singleNumber(vector<int>& nums) {
  unordered_map<int, int> a;
  for (auto x : nums) a[x]++;
  for (auto z : a)
    if (z.second == 1) return z.first;
  return -1;
}
