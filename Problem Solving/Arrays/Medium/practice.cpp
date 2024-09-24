#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& arr, int target) {
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

  void sortColors(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
      if (arr[mid] == 0) {
        swap(arr[low], arr[mid]);
        low++;
        mid++;
      } else if (arr[mid] == 1) {
        mid++;
      } else {
        swap(arr[mid], arr[high]);
        high--;
      }
    }
  }

  int majorityElement(vector<int>& arr) {
    map<int, int> hashed;
    for (auto it : arr) {
      hashed[it]++;
    }
    for (auto it : hashed) {
      if (it.second > arr.size() / 2) {
        return it.first;
      }
    }
    return -1;
  }

  int pairWithMaxSum(vector<int>& arr) {
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size() - 1; i++) {
      sum = arr[i] + arr[i + 1];
      if (sum < 0) {
        sum = 0;
      }
      maxi = max(sum, maxi);
    }
    return maxi;
  }

  int maxProfit(vector<int>& arr) {
    int profit = 0;
    int min_cost = arr[0];
    for (int i = 0; i < arr.size(); i++) {
      int cost = arr[i] - min_cost;
      profit = max(cost, profit);
      min_cost = min(min_cost, arr[i]);
    }
    return profit;
  }

  vector<int> rearrangeArray(vector<int>& arr) {
    vector<int> pos, neg;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] < 0) {
        neg.push_back(arr[i]);
      } else {
        pos.push_back(arr[i]);
      }
    }
    for (int i = 0; i < arr.size() / 2; i++) {
      arr[2 * i] = pos[i];
      arr[2 * i + 1] = neg[i];
    }
    return arr;
  }

  int maxSubArray(vector<int>& arr) {
    int maximum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
      sum += arr[i];

      if (sum < 0) sum = 0;

      maximum = max(maximum, sum);
    }
    return maximum;
  }

  vector<int> majorityElement_2(vector<int>& arr) {
    map<int, int> hashed;
    vector<int> ans;

    for (auto it : arr) {
      hashed[it]++;
    }
    for (auto it : hashed) {
      if (it.second > (arr.size() / 3 % arr.size())) {
        ans.push_back(it.first);
      }
    }
    return ans;
  }

  int mostFrequentEven(vector<int>& arr) {
    map<int, int> hashmap;
    int max_element = INT_MAX;
    int min_element = INT_MIN;

    for (auto it : arr) {
      hashmap[it]++;
    }

    for (auto it : hashmap) {
      if (it.first % 2 == 0) {
        min_element = max(min_element, it.first);
        return min_element;
      }
    }

    return -1;
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
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << solution.mostFrequentEven(arr) << endl;
    // vector<int> answer = solution.majorityElement_2(arr);
    // for (int i = 0; i < answer.size(); i++) {
    //   cout << answer[i] << " ";
    // }
    // cout << endl;
  }

  return 0;
}