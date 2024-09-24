#include <bits/stdc++.h>
using namespace std;

void explain_sort() {
  sort(a, a + n);            // a = start a+n = end + 1
  sort(v.begin(), v.end());  // for vectors

  // Sorting in descending order
  sort(a, a + n, greater<int>);

  // Sorting in our own way
  sort(a, a + n,
       comp);  // comp will be a comparator function that would return boolean
               // value

  int num = 6;
  int count = __builtin_popcount();
  long long num = 43324134243;
  int count_1 = __builtin_popcountll();

  // next Permutation
  string s = "123";
  sort(s.begin(), s.end());
  do {
    cout << s << endl;
  } while (next_permutation(s.begin(), s.end()));

  int maxi = *max_element(a, a + n);
}

int main() {}