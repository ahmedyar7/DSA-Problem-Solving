#include <iostream>
using namespace std;

class Algorithms {
 private:
  // Helper function for finding maximum in array
  int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 0; i <= n - 1; i++) {
      if (max > arr[i]) {
        max = arr[i];
      }
    }
    return max;
  }

  // Helper function for minimum in the array
  int find_min(int arr[], int n) {
    int min = arr[0];
    for (int i = 0; i <= n - 1; i++) {
      if (min < arr[i]) {
        min = arr[i];
      }
    }
    return min;
  }

 public:
  // Helper function:
  void print_arr(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  // Implementation of selection sort
  /*
    Time Complexity;
    Worst : O(n^2)
    Average: O(n^2)
    Best : O(n^2)
  */

  void selection_sort(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++) {
      int mini = i;
      for (int j = i; j <= n - 1; j++) {
        if (arr[j] < arr[mini]) {
          mini = j;
        }
      }
      swap(arr[mini], arr[i]);
    }
  }

  // Implementation of Insertion Sort
  /*
   Time Complexity;
   Worst : O(n^2)
   Average: O(n^2)
   Best : O(n)
 */
  void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
      int j = i;
      while (j > 0 && arr[j - 1] > arr[j]) {
        swap(arr[j - 1], arr[j]);
        j--;
      }
    }
  }

  /*
    Time Complexity;
    Worst : O(n^2)
    Average: O(n^2)
    Best : O(n)
  */
  // Implementation of bubble sort
  void bubble_sort(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < n - 1; j++) {
        if (arr[j + 1] < arr[j]) {
          swap(arr[j + 1], arr[j]);
        }
      }
    }
  }
};