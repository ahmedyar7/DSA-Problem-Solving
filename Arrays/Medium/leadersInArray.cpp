#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> leaders(int n, int arr[]) {
    vector<int> answer;

    for (int i = 0; i < n - 1; i++) {
      bool leader = true;

      for (int j = i + 1; j < n; j++) {
        if (arr[j] > arr[i]) {
          leader = false;
        }
      }

      if (leader = true) {
        answer.push_back(arr[i]);
      }
    }
    return answer;
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
    int arr[10];

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    // cout << solution.leaders() << endl;

    vector<int> ans = solution.leaders(n, arr);

    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }

  return 0;
}