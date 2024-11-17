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

// Implementation Of selection sort
void selection_sort(int arr[], int n) {
  for (int i = 0; i <= n - 2; i++) {
    int mini = i;
    for (int j = i; j <= n - 1; j++) {
      if (arr[j] < arr[mini]) mini = j;
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }
}

// Implementation of bubble sort
void bubble_sort(int arr[], int n) {
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Implementation of Insertion sort
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

void merge(int arr[], int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  int k = 0;
  int size = high - low + 1;
  int *temp = new int[size];

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp[k++] = arr[left++];
    } else {
      temp[k++] = arr[right++];
    }
  }

  while (left <= mid) {
    temp[k++] = arr[left++];
  }
  while (right <= high) {
    temp[k++] = arr[right++];
  }

  for (int i = 0; i < size; i++) {
    arr[low + i] = temp[i];
  }
  delete[] temp;
}

// Implementation of Merge sort
void merge_sort(int arr[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

int partition(int arr[], int low, int high) {
  int left = low;
  int right = high - 1;
  int pivot = arr[low];

  while (true) {
    while (left <= right && arr[left] <= pivot) left++;
    while (left <= right && arr[right] > pivot) right--;
    if (left > right) {
      break;
    }
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
  }
  int temp = arr[low];
  arr[low] = arr[right];
  arr[right] = temp;
  return right;
}

// Implementation of Quick sort
void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    int index = partition(arr, low, high);
    quick_sort(arr, low, index);
    quick_sort(arr, index + 1, high);
  }
}

// Implementation of Counting sort
void count_sort(int arr[], int n) {
  int min = arr[0];
  int max = arr[0];

  for (int i = 0; i < n; i++) {
    if (arr[i] > max) max = arr[i];
    if (arr[i] < min) min = arr[i];
  }

  int range = max - min + 1;
  int *temp = new int[range]();

  for (int i = 0; i < n; i++) {
    temp[arr[i] - min]++;
  }

  int index = 0;
  for (int i = 0; i < range; i++) {
    while (temp[i] > 0) {
      arr[index++] = i + min;
      temp[i]--;
    }
  }
}

// Implementation of Bucket sort
void bucket_sort(int arr[], int n) {
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) max = arr[i];
  }

  int *buckets = new int[max + 1]();
  for (int i = 0; i < n; i++) {
    buckets[arr[i]]++;
  }

  int index = 0;
  for (int i = 0; i < n; i++) {
    while (buckets[i] > 0) {
      arr[index++] = i;
      buckets[i]--;
    }
  }
}

// Function to find the maximum value in the array
int findMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) max = arr[i];
  }
  return max;
}

// Function to perform counting sort based on a specific digit
void counting_sort(int arr[], int n, int exp) {
  int *output = new int[n];  // Temporary array to store sorted numbers
  int count[10] = {0};       // Count array for digits (0-9)

  // Count occurrences of each digit
  for (int i = 0; i < n; i++) {
    int digit = (arr[i] / exp) % 10;  // Extract the digit at position `exp`
    count[digit]++;
  }

  // Update count[i] to store the actual position of this digit in `output`
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  // Build the output array
  for (int i = n - 1; i >= 0; i--) {  // Traverse array backward for stability
    int digit = (arr[i] / exp) % 10;
    output[count[digit] - 1] = arr[i];
    count[digit]--;
  }

  // Copy the sorted output array back to the original array
  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }

  // Free allocated memory
  delete[] output;
}

// Radix Sort implementation
void radix_sort(int arr[], int n) {
  int max = findMax(
      arr, n);  // Find the maximum number to determine the number of digits

  // Perform counting sort for every digit (exp = 1, 10, 100, ...)
  for (int exp = 1; max / exp > 0; exp *= 10) {
    counting_sort(arr, n, exp);
  }
}