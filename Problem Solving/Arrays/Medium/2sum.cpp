#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum_BRUTE_SOLUTION(vector<int>& arr, int target) {
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++) {
      for (int j = i + 1; j < arr.size(); i++) {
        if (arr[i] + arr[j] == target) {
          answer.push_back(i);
          answer.push_back(j);
        }
      }
    }
    return answer;
  }

  vector<int> twoSum_BETTER_SOLUTION(vector<int>& arr, int target) {
    map<int, int> hashed;

    for (int i = 0; i < arr.size(); i++) {
      int req = target - arr[i];
      if (hashed.find(req) != hashed.end()) {
        return {hashed[req], i};
      }
      hashed[arr[i]] = i;
    }
    return {-1, -1};
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  Solution solution;
  while (t--) {
    int n;
    int target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<int> result = solution.twoSum_BETTER_SOLUTION(arr, target);
    for (int index : result) {
      cout << index << " ";
    }
    cout << endl;
  }

  return 0;
}