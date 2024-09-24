#include <bits/stdc++.h>
using namespace std;

void explain_priority_queue() {
  priority_queue<int> pq1;
  pq1.push(1);
  pq1.push(2);
  pq1.push(3);
  pq1.push(40);
  pq1.push(5);
  pq1.push(15);

  cout << pq1.top() << endl;

  // With smaller integer numbers
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(1);
  pq.push(12);
  pq.push(11);

  cout << pq.top() << endl;
  pq.pop();
  cout << pq.top() << endl;
}

int main() { explain_priority_queue(); }
