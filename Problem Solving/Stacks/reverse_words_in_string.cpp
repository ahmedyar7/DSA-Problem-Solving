#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    int left = 0;
    int right = s.length() - 1;

    string temp = "";
    string ans = "";

    // Iterate the string and keep on adding to form a word
    // If empty space is encountered then add the current word to the result
    while (left <= right) {
      char ch = s[left];
      if (ch != ' ') {
        temp += ch;
      } else if (ch == ' ') {
        if (ans != "")
          ans = temp + " " + ans;
        else
          ans = temp;
        temp = "";
      }
      left++;
    }

    // If not empty string then add to the result(Last word is added)
    if (temp != "") {
      if (ans != "")
        ans = temp + " " + ans;
      else
        ans = temp;
    }

    return ans;
    // code
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
    string s;
    getline(cin, s);
    cout << solution.reverseWords(s) << endl;
  }

  return 0;
}
