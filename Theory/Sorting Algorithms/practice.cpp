#include <iostream>
using namespace std;

class SortingAlgorithms {
 public:
  void print_arr(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
      cout << arr[i] << " ";
    }
  }

  void selection_sort(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++) {
      int mini = i;
      for (int j = i; j <= n - 1; j++) {
        if (arr[j] < arr[mini]) mini = j;
      }
      swap(arr[i], arr[mini]);
    }
  }

  void bubble_sort(int arr[], int n) {
    bool flag = false;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < i; j++) {
        if (arr[j] > arr[j + 1]) {
          swap(arr[j], arr[j + 1]);
          flag = true;
        }
      }
      if (flag == false) break;
    }
  }

  void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
      int j = i;
      while (j > 0 && arr[j - 1] > arr[j]) {
        swap(arr[j - 1], arr[j]);
        j--;
      }
    }
  }

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

  int merge_sort(int arr[], int low, int high) {
    if (low < high) {
      int mid = low + (high - low) / 2;
      merge_sort(arr, low, mid);
      merge_sort(arr, mid + 1, high);
      merge(arr, low, mid, high);
    }
  }

  int quick_sort(int arr[], int low, int high) {
    if (low < high) {
      int index = partition(arr, low, high);
      quick_sort(arr, low, index - 1);
      quick_sort(arr, index + 1, high);
    }
  }

  void count_sort(int arr[], int n) {
    int max = find_max(arr, n);
    int min = find_min(arr, n);
    int size = max - min + 1;
    int *counter_arr = new int[size]();

    for (int i = 0; i < n; i++) {
      counter_arr[arr[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
      while (counter_arr[i] > 0) {
        arr[index++] = i + min;
        counter_arr[i]--;
      }
    }
    delete[] counter_arr;
  }

 private:
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

  int partition(int arr[], int low, int high) {
    int left = low + 1;
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
};