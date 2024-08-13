#include <bits/stdc++.h>
using namespace std;

void frequencyCount(vector<int>& arr, int N, int P) {
  unordered_map<int, int> unordered_map;

  for (int i = 0; i < N; i++) {
    if (arr[i] >= 1 && arr[i] <= N) {
      unordered_map[arr[i]]++;
    }
  }
  for (int i = 0; i < N; i++) {
    arr[i] = unordered_map[i + 1];
  }
  for (auto it : unordered_map) {
    cout << it.first << " -> " << it.second << endl;
  }
}

int maxFrequency(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  int left = 0;
  int max_freq = 1;
  int total_ops = 0;
  for (int right = 1; right < nums.size(); right++) {
    total_ops += (long long)(nums[right] - nums[right - 1]) * (right - left);
    while (total_ops > k) {
      total_ops -= nums[right] - nums[left];
      left++;
    }
    max_freq = max(max_freq, right - left + 1);
  }
  return max_freq;
}

int main() {
  int nums[] = {1, 2, 4};
  int k = 5;
}