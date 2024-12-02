#include <iostream>
using namespace std;

class SortingAlgorithm {
 public:
  void print_arr(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

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

  void bubble_sort(int arr[], int n) {
    bool flag;
    for (int i = n - 1; i >= 0; i--) {
      flag = false;
      for (int j = 0; j < i; j++) {
        if (arr[j] > arr[j + 1]) {
          swap(arr[j], arr[j + 1]);
          flag = true;
        }
      }
    }
  }

  void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
      int key = i;
      while (key > 0 && arr[key - 1] > arr[key]) {
        swap(arr[key - 1], arr[key]);
        key--;
      }
    }
  }

  void merge_sort(int arr[], int low, int high) {
    if (low < high) {
      int mid = low + (high - low) / 2;
      merge_sort(arr, low, mid);
      merge_sort(arr, mid + 1, high);
      merge(arr, low, mid, high);
    }
  }

  void quick_sort(int arr[], int low, int high) {
    if (low < high) {
      int index = partition(arr, low, high);
      quick_sort(arr, low, index - 1);
      quick_sort(arr, index + 1, high);
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

  void count_sort(int arr[], int n) {
    int max = find_max(arr, n);
    int min = find_min(arr, n);
    int range = max - min + 1;
    int* counter_arr = new int[range]();

    for (int i = 0; i <= n - 1; i++) {
      counter_arr[arr[i]]++;
    }
    int index = 0;
    for (int i = 0; i < range; i++) {
      while (counter_arr[i] > 0) {
        arr[index++] = i;
        counter_arr[i]--;
      }
    }
  }

  void radix_sort(int arr[], int n) {
    int max = find_max(arr, n);
    for (int exp = 1; max / exp >= 1; exp = exp * 10) {
      counting_sort(arr, n, exp);
    }
  }

 private:
  void counting_sort(int arr[], int n, int exp) {
    int* counter_arr = new int[10]();
    int* output = new int[n];

    for (int i = 0; i <= n - 1; i++) {
      int digit = (arr[i] / exp) % 10;
      counter_arr[digit]++;
    }

    for (int i = 1; i < 10; i++) {
      counter_arr[i] += counter_arr[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
      int digit = (arr[i] / exp) % 10;
      output[--counter_arr[digit]] = arr[i];
    }

    for (int i = 0; i <= n - 1; i++) {
      arr[i] = output[i];
    }
    delete[] counter_arr;
    delete[] output;
  }

  int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 0; i <= n - 1; i++) {
      if (arr[i] > max) {
        max = arr[i];
      }
    }
    return max;
  }

  int find_min(int arr[], int n) {
    int min = arr[0];
    for (int i = 0; i <= n - 1; i++) {
      if (arr[i] < min) {
        min = arr[i];
      }
    }
    return min;
  }

  int partition(int arr[], int low, int high) {
    int left = low + 1;
    int right = high;
    int pivot = arr[low];
    while (true) {
      while (left <= right && arr[left] <= pivot) left++;
      while (left <= right && arr[right] > pivot) right--;
      if (left >= right) break;
      swap(arr[left], arr[right]);
    }
    swap(arr[low], arr[right]);
    return right;
  }

  void merge(int arr[], int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    int k = 0;
    int size = high - low + 1;
    int* temp = new int[size];

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

    for (int i = 0; i < size - 1; i++) {
      arr[i + low] = temp[i];
    }
    delete[] temp;
  }
};