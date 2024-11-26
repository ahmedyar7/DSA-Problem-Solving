#include <iostream>
using namespace std;

// Helper swapping function
void swap(int *left, int *right) {
  int temp = *left;
  *left = *right;
  *right = temp;
}

// Print the Sorted array
void print_arr(int arr[], int n) {
  cout << "[";
  for (int i = 0; i < n; i++) {
    cout << "" << arr[i] << " ";
  }
  cout << "]";
  cout << endl;
}

// Helper function for finding max and min
int find_max(int arr[], int n) {
  int max = arr[0];
  for (int i = 0; i <= n - 1; i++) {
    if (arr[i] > max) max = arr[i];
  }
  return max;
}

int find_min(int arr[], int n) {
  int min = arr[0];
  for (int i = 0; i <= n - 1; i++) {
    if (arr[i] < min) min = arr[i];
  }
  return min;
}

// Implementation of selection sort
void selection_sort(int arr[], int n) {
  for (int i = 0; i <= n - 2; i++) {
    int mini = i;
    for (int j = i; j <= n - 1; j++) {
      if (arr[j] < arr[mini]) mini = j;
    }
    swap(arr[mini], arr[i]);
  }
}

// Implementation of bubble sort
void bubble_sort(int arr[], int n) {
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    }
  }
}

// Implementation of insertion sort
void insertion_sort(int arr[], int n) {
  for (int i = 0; i <= n - 1; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      swap(arr[j - 1], arr[j]);
      j--;
    }
  }
}

// Implementation of merge sort
void merge(int arr[], int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  int size = high - low + 1;
  int *temp = new int[size];
  int k = 0;
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp[k++] = arr[left++];
    } else {
      temp[k++] = arr[right++];
    }
  }
  while (left <= mid) temp[k++] = arr[left++];
  while (right <= high) temp[k++] = arr[right++];
  for (int i = 0; i < size; i++) {
    arr[i + low] = temp[i];
  }
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
    swap(arr[left], arr[right]);
  }
  swap(arr[low], arr[right]);
  return right;
}

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    int index = partition(arr, low, high);
    quick_sort(arr, low, index - 1);
    quick_sort(arr, index + 1, high);
  }
}

// Implementation of count sort
void count_sort(int arr[], int n) {
  int max = find_max(arr, n);
  int min = find_min(arr, n);
  int size = max - min + 1;
  int *counter_arr = new int[size]();

  for (int i = 0; i <= n - 1; i++) counter_arr[arr[i]]++;
  int index = 0;
  for (int i = 0; i < size; i++) {
    while (counter_arr[i] > 0) {
      arr[index++] = i;
      counter_arr[i]--;
    }
  }
}

// Implementation of bin/ bucket sort
void bucket_sort(int arr[], int n) {
  int max = find_max(arr, n);
  int min = find_min(arr, n);
  int size = max - min + 1;
  int *counter_arr = new int[size]();

  for (int i = 0; i <= n - 1; i++) {
    counter_arr[arr[i]]++;
  }
  int index = 0;
  for (int i = 0; i < size; i++) {
    while (counter_arr[i] > 0) {
      arr[index++] = i;
      counter_arr[i]--;
    }
  }
}

// Helper function for implementing counting sort
void counting_sort(int arr[], int n, int exp) {
  int *counter = new int[10]();
  int *output = new int[n];
  for (int i = 0; i <= n - 1; i++) {
    int digit = (arr[i] / exp) % 10;
    counter[digit]++;
  }
  for (int i = 1; i < 10; i++) {
    counter[i] += counter[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    int digit = (arr[i] / exp) % 10;
    output[--counter[digit]] = arr[i];
  }
  for (int i = 0; i <= n - 1; i++) {
    arr[i] = output[i];
  }
  delete[] counter;
  delete[] output;
}

void radix_sort(int arr[], int n) {
  int max = find_max(arr, n);
  for (int exp = 1; max / exp > 0; exp = exp * 10) {
    counting_sort(arr, n, exp);
  }
}

// Implementation of Shell's Sort
void shell_sort(int arr[], int n) {
  for (int gap = n / 2; gap >= 1; gap = gap / 2) {
    for (int i = gap; i < n; i++) {
      int j = i;
      while (j >= gap && arr[j - gap] > arr[j]) {
        swap(arr[j - gap], arr[j]);
        j = j - gap;
      }
    }
  }
}
