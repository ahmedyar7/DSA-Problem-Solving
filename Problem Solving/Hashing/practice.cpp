#include <bits/stdc++.h>
using namespace std;

void freq_count(vector<int>& arr, int n, int p) {
  unordered_map<int, int> hash;

  for (int i = 0; i < n; i++) {
    if (arr[i] >= 1 && arr[i] <= n) {
      hash[arr[i]]++;
    }
  }

  for (int i = 0; i < n; i++) {
    arr[i] = hash[i + 1];
  }

  for (auto it : hash) {
    cout << it.first << " -> " << it.second << endl;
  }
}

int max_frequency(vector<int> arr, int k) {
  sort(arr.begin(), arr.end());
  int max_freq = 1;
  int total_ops = 0;
  int left = 0;
  for (int right = 1; right < arr.size(); right++) {
    total_ops += arr[right] - arr[right - 1] * (right - left);
    while (total_ops > k) {
      total_ops -= arr[right] - arr[left];
      left++;
    }
    max_freq = max(max_freq, right - left + 1);
  }
  return max_freq;
}

int main() {
  vector<int> nums = {1, 2, 4};
  int k = 5;
  cout << max_frequency(nums, k);
}