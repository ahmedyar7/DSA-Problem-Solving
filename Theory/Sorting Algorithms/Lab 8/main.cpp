#include <cstdlib>
#include <ctime>
#include <iostream>

#include "algo.cpp"
using namespace std;

int main() {
  int arr[100];

  srand(time(0));

  for (int i = 0; i < 100; ++i) {
    arr[i] = rand() % 1000;
  }
  int n = sizeof(arr) / sizeof(arr[0]);

  Algorithms algo;
  // cout << "Selection sort \n\n";
  // algo.selection_sort(arr, n);
  // algo.print_arr(arr, n);

  // cout << "\nInsertion sort \n\n";
  // algo.insertion_sort(arr, n);
  // algo.print_arr(arr, n);

  // cout << "\nBubble sort \n\n";
  // algo.bubble_sort(arr, n);
  // algo.print_arr(arr, n);

  // cout << "\n Shell Sort \n\n";
  // algo.shell_sort(arr, n);
  // algo.print_arr(arr, n);

  // cout << "\n Count Sort \n\n";
  // algo.count_sort(arr, n);
  // algo.print_arr(arr, n);

  // cout << "\n Merge Sort \n\n";
  // algo.merge_sort(arr, 0, n - 1);
  // algo.print_arr(arr, n);

  cout << "\n Quick Sort \n\n";
  algo.quick_sort(arr, 0, n - 1);
  algo.print_arr(arr, n);
}
