#include <cstdlib>
#include <ctime>
#include <iostream>

#include "algo.cpp"
using namespace std;

int main() {
  int arr[1000];

  // Seed the random number generator with the current time
  srand(time(0));

  // Fill the array with random numbers (e.g., between 0 and 1000)
  for (int i = 0; i < 1000; ++i) {
    arr[i] = rand() % 1000;  // Random numbers between 0 and 999
  }
  int n = sizeof(arr) / sizeof(arr[0]);

  Algorithms algo;
  cout << "Selection sort \n\n";
  algo.selection_sort(arr, n);
  algo.print_arr(arr, n);

  cout << "\nInsertion sort \n\n";
  algo.insertion_sort(arr, n);
  algo.print_arr(arr, n);

  cout << "\nBubble sort \n\n";
  algo.bubble_sort(arr, n);
  algo.print_arr(arr, n);
}
