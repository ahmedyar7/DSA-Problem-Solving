#include <bits/stdc++.h>
using namespace std;

void explain_list() {
  list<int> ls;
  ls.push_back(2);
  ls.emplace_back(2);
  ls.push_front(22);
  ls.emplace_front(2);

  for (auto it : ls) {
    cout << it << " ";
  }
}

int main() {
  explain_list();
  //
}

// This is also dynamic in nature
// This also provide the front entering operation as well
