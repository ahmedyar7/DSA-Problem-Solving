#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <iostream>

#include "practice.cpp"
using namespace std;

int main() {
  const int SIZE = 100;              // Size of the array
  int arr[SIZE];                     // Array to store random numbers
  int minRange = 1, maxRange = 100;  // Range of random numbers

  // Seed the random number generator
  srand(static_cast<unsigned int>(time(0)));

  // Generate 100 random numbers and store them in the array
  for (int i = 0; i < SIZE; ++i) {
    arr[i] = minRange + (rand() % (maxRange - minRange + 1));
  }

  int n = sizeof(arr) / sizeof(arr[0]);

  SortingAlgorithm sort;
  sort.radix_sort(arr, n);
  sort.print_arr(arr, n);
}
