#include <bits/stdc++.h>
using namespace std;

// . BRUTE FORCE APPROACH
void left_rotate_by_k_places() {
  int d = 3;
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  int temp[10];

  // Adding into temp
  for (int i = 0; i < d; i++) {
    temp[i] = arr[i];
  }

  // Shifting
  for (int i = d; i < n; i++) {
    arr[i - d] = arr[i];
  }

  int z = 0;
  for (int i = n - d; i < n; i++) {
    arr[i] = temp[i - (n - d)];
  }

  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

//. OPTIMAL APPROACH
void rotate() {
  int d = 3;
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  int n = arr.size();

  // Reverse the first d elements
  reverse(arr.begin(), arr.begin() + d);
  // Reverse the remaining elements
  reverse(arr.begin() + d, arr.end());
  // Reverse the entire array
  reverse(arr.begin(), arr.end());

  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

void right_rotate() {
  int d = 3;
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  int n = arr.size();
  reverse(arr.end(), arr.begin());
  reverse(arr.end() - d, arr.begin());
  reverse(arr.begin(), arr.end() - d);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

int main() { right_rotate(); }