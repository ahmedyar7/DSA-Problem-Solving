#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, int> hashmap;

    for (auto c : s) hashmap[c]++;
    for (auto c : t) {
      if (hashmap.find(c) == hashmap.end() || hashmap[c] == 0) return false;
      hashmap[c]--;
    }
    return true;
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
    string s;
    string t;
    cin >> s;
    cin >> t;
    cout << solution.isAnagram(s, t) << endl;
  }

  return 0;
}