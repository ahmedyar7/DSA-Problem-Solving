#include <iostream>
using namespace std;

// Print the Sorted array
void print_arr(int arr[], int n) {
  cout << "[";
  for (int i = 0; i < n; i++) {
    cout << "" << arr[i] << " ";
  }
  cout << "]";
  cout << endl;
}

// Implementation of selection sort
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

// Implementation of bubble sort
void bubble_sort(int arr[], int n) {
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Implementation of insertion sort
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

// Implementation of merge sort
void merge(int arr[], int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  int k = 0;
  int size = high - low + 1;
  int *temp = new int[size];

  while (left <= mid && right <= high) {
    if (arr[left] < arr[right]) temp[k++] = arr[left++];
    temp[k++] = arr[right++];
  }

  while (left <= mid) temp[k++] = arr[left++];

  while (right <= high) temp[k++] = arr[right++];

  for (int i = 0; i < size; i++) arr[low + i] = temp[i];
  delete[] temp;
}
void merge_sort(int arr[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

// Implementation of quick sort
int partition(int arr[], int low, int high) {
  int left = low;
  int right = high;
  int pivot = arr[low];

  while (true) {
    while (left <= right && arr[left] <= pivot) left++;
    while (left <= right && arr[right] > pivot) right--;

    if (left > right) break;

    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
  }

  int temp = arr[low];
  arr[low] = arr[right];
  arr[right] = temp;

  return right;
}
void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    int index = partition(arr, low, high);
    quick_sort(arr, low, index);
    quick_sort(arr, index + 1, high);
  }
}
