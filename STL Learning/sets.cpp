#include <bits/stdc++.h>
using namespace std;

void explain_sets() {
  // This would store the sorted and the unique elements
  set<int> st;
  st.insert(1);  // {1}
  st.insert(2);  // {1,2}
  st.insert(3);  // {1, 2, 3}
  st.insert(4);  // {1, 2, 3, 4}

  auto it = st.find(2);
  cout << it << endl;
}
int main() { explain_sets(); }
