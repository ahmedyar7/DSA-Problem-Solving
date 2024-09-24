#include <bits/stdc++.h>
using namespace std;

void brute_force() {
  int arr[] = {1, 1, 2, 2, 2, 3, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  set<int> st;

  for (int i = 0; i < n; i++) {
    st.insert(arr[i]);
  }

  int index = 0;

  for (auto it : st) {
    arr[index] = it;
    index++;
  }

  for (int i = 0; i < index; i++) {
    cout << arr[i] << " ";
  }
}
void optimal() {
  int arr[] = {1, 1, 2, 2, 2, 3, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  int i = 0;  // Pointer for the last unique element

  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      arr[++i] = arr[j];  // Move the unique element to the next position
    }
  }

  // Print the array with duplicates removed
  for (int k = 0; k <= i; k++) {
    cout << arr[k] << " ";
  }
}

int main() { optimal(); }
