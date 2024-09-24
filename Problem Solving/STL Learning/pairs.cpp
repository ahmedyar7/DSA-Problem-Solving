#include <bits/stdc++.h>
using namespace std;

void explain_pairs() {
  pair<int, int> p = {1, 3};
  cout << p.first << " " << p.second << endl;
  cout << endl;

  pair<int, pair<int, int>> p2 = {1, {3, 1}};
  cout << p2.first << endl;
  cout << p2.second.first << " " << p2.second.second << endl;
  cout << endl;

  pair<int, int> arr[] = {{1, 2}, {2, 5}, {3, 5}};
  cout << arr[0].first << " " << arr[0].second << endl;

  cout << arr[1].first << " " << arr[1].second << endl;

  cout << arr[2].first << " " << arr[2].second << endl;
}

int main() { explain_pairs(); }

/*

This can store any data type there is
We can also use the nested property of the pairs

*/