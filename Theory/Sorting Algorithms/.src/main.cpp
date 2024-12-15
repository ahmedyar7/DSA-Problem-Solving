#include <algorithm>  // For copy
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "algo.cpp"
using namespace std;

int main() {
  int original[100];
  int arr[100];  // Array to be sorted

  srand(time(0));

  for (int i = 0; i < 100; ++i) {
    original[i] = rand() % 1000;  // Fill original array with random numbers
  }

  int n = sizeof(original) / sizeof(original[0]);

  Algorithms algo;

  // Selection Sort
  cout << "Selection Sort \n\n";
  copy(original, original + n, arr);  // Copy original array to arr
  algo.selection_sort(arr, n);
  algo.print_arr(arr, n);

  // Insertion Sort
  cout << "\nInsertion Sort \n\n";
  copy(original, original + n, arr);  // Copy original array to arr
  algo.insertion_sort(arr, n);
  algo.print_arr(arr, n);

  // Bubble Sort
  cout << "\nBubble Sort \n\n";
  copy(original, original + n, arr);  // Copy original array to arr
  algo.bubble_sort(arr, n);
  algo.print_arr(arr, n);

  // Shell Sort
  cout << "\nShell Sort \n\n";
  copy(original, original + n, arr);  // Copy original array to arr
  algo.shell_sort(arr, n);
  algo.print_arr(arr, n);

  // Count Sort
  cout << "\nCount Sort \n\n";
  copy(original, original + n, arr);  // Copy original array to arr
  algo.count_sort(arr, n);
  algo.print_arr(arr, n);

  // Merge Sort
  cout << "\nMerge Sort \n\n";
  copy(original, original + n, arr);  // Copy original array to arr
  algo.merge_sort(arr, 0, n - 1);
  algo.print_arr(arr, n);

  // Quick Sort
  cout << "\nQuick Sort \n\n";
  copy(original, original + n, arr);  // Copy original array to arr
  algo.quick_sort(arr, 0, n - 1);
  algo.print_arr(arr, n);

  // Radix Sort
  cout << "\nRadix Sort \n\n";
  copy(original, original + n, arr);  // Copy original array to arr
  algo.radix_sort(arr, n);
  algo.print_arr(arr, n);

  return 0;
}
