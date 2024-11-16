#include <iostream>

#include "algorithms.cpp"
using namespace std;

int main() {
  int arr[] = {13, 46, 24, 52, 20, 9};
  int n = sizeof(arr) / sizeof(arr[0]);

  //   selection_sort(arr, n);
  bubble_sort(arr, n);
  print_arr(arr, n);
}
