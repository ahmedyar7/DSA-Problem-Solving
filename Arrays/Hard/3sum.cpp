#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& arr) {
    set<vector<int>> st;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (arr[i] + arr[j] + arr[k] == 0) {
            vector<int> temp = {arr[i], arr[j], arr[k]};
            sort(temp.begin(), temp.end());
            st.insert(temp);
          }
        }
      }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
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
    // cout << solution.solve() << endl;
    vector<vector<int>> result = solution.threeSum(arr);
    for (const auto& triplet : result) {
      for (int num : triplet) {
        cout << num << " ";
      }
      cout << endl;
    }

    if (result.empty()) {
      cout << "No triplets found" << endl;
    }
  }
}
