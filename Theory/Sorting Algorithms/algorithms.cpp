#include <iostream>
using namespace std;

void selection_sort(int arr[], int n) {
  for (int i = 0; i <= n - 2; i++) {
    int mini = i;
    for (int j = i; j <= n - 1; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }
}

void print_arr(int arr[], int n) {
  cout << "[";
  for (int i = 0; i < n; i++) {
    cout << "" << arr[i] << " ";
  }
  cout << "]";
  cout << endl;
}

void bubble_sort(int arr[], int n) {
  bool did_swap = false;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        did_swap = true;
      }
    }
    if (!did_swap) {  // If no swaps were made, the array is sorted
      break;
    }
  }
}

void insertion_sort(int arr[], int n) {
  for (int i = 0; i <= n - 1; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      int temp = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = temp;
      j--;
    }
  }
}

void merge(int arr[], int low, int mid, int high) {}

void merge_sort(int arr[], int low, int high) {}

int partition(int arr[], int low, int high) {}

void quick_sort(int arr[], int low, int high) {}