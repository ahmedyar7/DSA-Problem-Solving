#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<long long> sumOfThree(long long num) {
    if (num % 3 != 0) return {};
    long long x = num / 3;
    return {x - 1, x, x + 1};
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
    long long num;
    cin >> num;
    vector<int> arr;
    for (int i = 0; i < arr.size(); i++) {
      cin >> arr[i];
    }
    // cout << solution.sumOfThree(num) << endl << endl;

    vector<long long> result = solution.sumOfThree(num);

    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << " ";
    }

    cout << endl;
  }

  return 0;
}