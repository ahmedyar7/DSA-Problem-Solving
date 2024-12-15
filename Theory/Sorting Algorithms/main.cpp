#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "practice.cpp"  // Include the header for the SortingAlgorithms class

using namespace std;
using namespace std::chrono;

int main() {
  // Initialize random seed
  srand(time(0));

  // Set the size of the array
  int n = 1000;  // You can adjust the size

  // Create a vector of random integers
  vector<int> arr(n);

  // Fill the vector with random numbers
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 10000;  // Random number between 0 and 9999
  }

  SortingAlgorithms sorter;

  // Test each sorting algorithm and measure the time taken

  // Selection Sort
  vector<int> arr1 = arr;  // Copy the original array
  auto start = high_resolution_clock::now();
  sorter.selection_sort(arr1.data(), n);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Selection Sort: " << duration.count() << " microseconds" << endl;

  // Bubble Sort
  vector<int> arr2 = arr;
  start = high_resolution_clock::now();
  sorter.bubble_sort(arr2.data(), n);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Bubble Sort: " << duration.count() << " microseconds" << endl;

  // Insertion Sort
  vector<int> arr3 = arr;
  start = high_resolution_clock::now();
  sorter.insertion_sort(arr3.data(), n);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Insertion Sort: " << duration.count() << " microseconds" << endl;

  // Shell Sort
  vector<int> arr4 = arr;
  start = high_resolution_clock::now();
  sorter.shell_sort(arr4.data(), n);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Shell Sort: " << duration.count() << " microseconds" << endl;

  // Merge Sort
  vector<int> arr5 = arr;
  start = high_resolution_clock::now();
  sorter.merge_sort(arr5.data(), 0, n - 1);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Merge Sort: " << duration.count() << " microseconds" << endl;

  // Quick Sort
  vector<int> arr6 = arr;
  start = high_resolution_clock::now();
  sorter.quick_sort(arr6.data(), 0, n - 1);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Quick Sort: " << duration.count() << " microseconds" << endl;

  // Count Sort
  vector<int> arr7 = arr;
  start = high_resolution_clock::now();
  sorter.count_sort(arr7.data(), n);
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop - start);
  cout << "Count Sort: " << duration.count() << " microseconds" << endl;

  return 0;
}
