#include <bits/stdc++.h>
using namespace std;

//. BRUTE FORCE
void move_all_zero() {
  vector<int> arr = {1, 2, 0, 3, 4, 0, 2, 0};
  vector<int> temp;
  int n = arr.size();

  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) temp.push_back(arr[i]);
  }
  int s_non_zero = temp.size();
  for (int i = 0; i < s_non_zero; i++) {
    arr[i] = temp[i];
  }
  for (int i = s_non_zero; i < n; i++) {
    arr[i] = 0;
  }
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

//. OPTIMAL SOLUTION
void move_zero() {
  vector<int> arr = {1, 0, 1};
  int n = arr.size();
  int j = -1;

  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      j = i;
      break;
    } else
      return;
  }

  for (int i = j + 1; i < n; i++) {
    if (arr[i] != 0) {
      swap(arr[i], arr[j]);
      j++;
    }
  }

  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

int main() { move_zero(); }
