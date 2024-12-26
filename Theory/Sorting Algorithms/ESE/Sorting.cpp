#include <iostream>
using namespace std;

class Sorting {
 private:
  // Swap helper function to swap two elements
  void swap(int &left, int &right) {
    int temp = left;
    left = right;
    right = temp;
  }

  void merge(int arr[], int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    int k = 0;
    int size = high - low + 1;
    int *temp = new int[size];

    while (left <= mid && right <= high) {
      if (arr[left] < mid) {
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

 public:
  // Selection Sort
  void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
      int mini = i;
      for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[mini]) mini = j;
      }
      swap(arr[i], arr[mini]);
    }
    return;
  }

  // Bubble Sort
  void bubble_sort(int arr[], int n) {
    bool flag = false;
    for (int i = n - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
        if (arr[j] > arr[j + 1]) {
          swap(arr[j], arr[j + 1]);
          flag = true;
        }
      }
      if (flag == false) break;
    }
    return;
  }

  // Insertion Sort
  void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
      int j = i;
      while (j > 0 && arr[j - 1] > arr[j]) {
        swap(arr[j - 1], arr[j]);
        j--;
      }
    }
    return;
  }

  // Shell Sort
  void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap >= 1; gap = gap / 2) {
      for (int i = 0; i < n; i++) {
        int j = i;
        while (j >= gap && arr[j - gap] > arr[j]) {
          swap(arr[j - gap], arr[j]);
          j = j - gap;
        }
      }
    }
    return -1;
  }

  void merge_sort(int arr[], int low, int high) {
    if (low < high) {
      int mid = low + (high - low) / 2;
      merge_sort(arr, low, mid);
      merge_sort(arr, mid + 1, high);
      merge(arr, low, mid, high);
    }
    return;
  }

  void quick_sort(int arr[], int low, int high) {
    if (low < high) {
      int index = partition(arr, low, high);
      quick_sort(arr, low, index - 1);
      quick_sort(arr, index + 1, high);
    }
    return;
  }

  // Print the array
  void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
    return;
  }
};

int main() {
  Sorting sorter;

  // Arrays for sorting
  int arr1[] = {64, 34, 25, 12, 22, 11, 90};
  int arr2[] = {64, 34, 25, 12, 22, 11, 90};
  int arr3[] = {64, 34, 25, 12, 22, 11, 90};
  int arr4[] = {64, 34, 25, 12, 22, 11, 90};
  int arr5[] = {64, 34, 25, 12, 22, 11, 90};
  int arr6[] = {64, 34, 25, 12, 22, 11, 90};

  int n = sizeof(arr1) / sizeof(arr1[0]);

  // Selection Sort
  cout << "Original array: ";
  sorter.print_arr(arr1, n);
  sorter.selection_sort(arr1, n);
  cout << "Selection Sorted array: ";
  sorter.print_arr(arr1, n);

  // Bubble Sort
  cout << "\nOriginal array: ";
  sorter.print_arr(arr2, n);
  sorter.bubble_sort(arr2, n);
  cout << "Bubble Sorted array: ";
  sorter.print_arr(arr2, n);

  // Insertion Sort
  cout << "\nOriginal array: ";
  sorter.print_arr(arr3, n);
  sorter.insertion_sort(arr3, n);
  cout << "Insertion Sorted array: ";
  sorter.print_arr(arr3, n);

  // Shell Sort
  cout << "\nOriginal array: ";
  sorter.print_arr(arr4, n);
  sorter.shell_sort(arr4, n);
  cout << "Shell Sorted array: ";
  sorter.print_arr(arr4, n);

  // Merge Sort
  cout << "\nOriginal array: ";
  sorter.print_arr(arr5, n);
  sorter.merge_sort(arr5, 0, n - 1);
  cout << "Merge Sorted array: ";
  sorter.print_arr(arr5, n);

  // Quick Sort
  cout << "\nOriginal array: ";
  sorter.print_arr(arr6, n);
  sorter.quick_sort(arr6, 0, n - 1);
  cout << "Quick Sorted array: ";
  sorter.print_arr(arr6, n);

  return 0;
}
