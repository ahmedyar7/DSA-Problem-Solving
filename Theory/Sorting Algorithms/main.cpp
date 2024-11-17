#include <iostream>

#include "algorithms.cpp"
using namespace std;

int main() {
  int arr[] = {23, 12, 1, 54, 3, 0, 55, 11, 44, 233, 23111, 44, 343};
  int n = sizeof(arr) / sizeof(arr[0]);

  // selection_sort(arr, n);
  // print_arr(arr, n);

  // insertion_sort(arr, n);
  // print_arr(arr, n);

  // bubble_sort(arr, n);
  // print_arr(arr, n);

  // merge_sort(arr, 0, n - 1);
  // print_arr(arr, n);

  // quick_sort(arr, 0, n - 1);
  // print_arr(arr, n);

  // count_sort(arr, n);

  radix_sort(arr, n);
  print_arr(arr, n);
}
