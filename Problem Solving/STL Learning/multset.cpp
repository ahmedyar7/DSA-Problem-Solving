#include <bits/stdc++.h>
using namespace std;

void explain_multi_set() {
  // Also contain the duplicates elements
  // everything else is same

  multiset<int> mul;
  mul.insert(1);
  mul.insert(1);
  mul.insert(2);

  mul.erase(1);  // All 1's are erased

  mul.erase(mul.find(1));  // Erase 1st occurance of 1

  mul.erase(mul.find(1), mul.find(1));
}

int main() {}
