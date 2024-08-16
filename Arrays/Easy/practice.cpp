
#include <bits/stdc++.h>
using namespace std;

//. Remove Duplicates from an array

void remove_duplicates() {
  int arr[] = {1, 1, 2, 2, 3, 3, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      arr[++i] = arr[j];
    }
  }
  for (int k = 0; k < i; k++) {
    cout << arr[k] << " ";
  }
}

// . Left Rotate Array by one number

void left_rotate_once() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int temp = arr[0];
  for (int i = 1; i < n; i++) {
    arr[i - 1] = arr[i];
  }
  arr[n - 1] = temp;
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

//. Check Sorted & Rotated

void check_sorted_n_rotated() {
  int arr[] = {2, 3, 4, 5, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[n + 1] < (arr[i % n])) count++;
  }
  if (count > 1)
    cout << "True";
  else
    cout << "False";
}

// . 2nd Largest Element

void second_largest_element() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  int largest = arr[0];
  int second_largest = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] > largest) {
      second_largest = largest;
      largest = arr[i];
    } else if (arr[i] < largest && arr[i] > second_largest) {
      second_largest = arr[i];
    }
  }
  cout << second_largest;
}

int main() { second_largest_element(); }