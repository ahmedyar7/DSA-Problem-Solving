#include <bits/stdc++.h>
using namespace std;

void explain_stack() {
  stack<int> st;
  st.push(3);  //. L = LAST
  st.push(2);  //. I = IN
  st.push(1);  //. F = FIRST
  st.push(4);  //. O = OUT

  cout << st.top() << endl;
}

int main() {
  explain_stack();
  //
}