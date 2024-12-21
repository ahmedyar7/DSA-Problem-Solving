#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class SortingAlgorithms {
 public:
  void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
      int mini = i;
      for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[mini]) {
          mini = j;
        }
      }
      swap(arr[mini], arr[i]);
    }
  }

  void bubble_sort(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
        if (arr[j] > arr[j + 1]) {
          swap(arr[j], arr[j + 1]);
        }
      }
    }
  }

  void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
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
          j -= gap;
        }
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
  void generate_random_array(int arr[], int n, int min_val = 0,
                             int max_val = 100) {
    for (int i = 0; i < n; i++) {
      arr[i] = rand() % (max_val - min_val + 1) + min_val;
    }
  }

 private:
  int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
      if (arr[i] > max) max = arr[i];
    }
    return max;
  }

  int find_min(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
      if (arr[i] < min) min = arr[i];
    }
    return min;
  }

  void merge(int arr[], int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    int k = 0;
    int size = high - low + 1;
    int *tmp = new int[size];

    while (left <= mid && right <= high) {
      if (arr[left] <= arr[right]) {
        tmp[k++] = arr[left++];
      } else {
        tmp[k++] = arr[right++];
      }
    }
    while (left <= mid) tmp[k++] = arr[left++];
    while (right <= high) tmp[k++] = arr[right++];

    for (int i = 0; i < size; i++) {
      arr[low + i] = tmp[i];
    }

    delete[] tmp;
  }

  int partition(int arr[], int low, int high) {
    int left = low;
    int right = high;
    int pivot = arr[(low + high) / 2];

    while (true) {
      while (arr[left] < pivot) left++;
      while (arr[right] > pivot) right--;
      if (left >= right) {
        break;
      }
      swap(arr[left], arr[right]);
    }
    swap(arr[low], arr[right]);
    return right;
  }
};

int main() {
  srand(time(0));  // Seed for random number generation
  const int SIZE = 10;
  int arr[SIZE];

  SortingAlgorithms sorter;

  // Generate and print a random array for selection sort
  sorter.generate_random_array(arr, SIZE);
  cout << "Original array (Selection Sort): ";
  sorter.print_arr(arr, SIZE);
  sorter.selection_sort(arr, SIZE);
  sorter.print_arr(arr, SIZE);

  // Generate and print a random array for bubble sort
  sorter.generate_random_array(arr, SIZE);
  cout << "Original array (Bubble Sort): ";
  sorter.print_arr(arr, SIZE);
  sorter.bubble_sort(arr, SIZE);
  sorter.print_arr(arr, SIZE);

  // Generate and print a random array for insertion sort
  sorter.generate_random_array(arr, SIZE);
  cout << "Original array (Insertion Sort): ";
  sorter.print_arr(arr, SIZE);
  sorter.insertion_sort(arr, SIZE);
  sorter.print_arr(arr, SIZE);

  // Generate and print a random array for shell sort
  sorter.generate_random_array(arr, SIZE);
  cout << "Original array (Shell Sort): ";
  sorter.print_arr(arr, SIZE);
  sorter.shell_sort(arr, SIZE);
  sorter.print_arr(arr, SIZE);

  // Generate and print a random array for merge sort
  sorter.generate_random_array(arr, SIZE);
  cout << "Original array (Merge Sort): ";
  sorter.print_arr(arr, SIZE);
  sorter.merge_sort(arr, 0, SIZE - 1);
  sorter.print_arr(arr, SIZE);

  // Generate and print a random array for quick sort
  sorter.generate_random_array(arr, SIZE);
  cout << "Original array (Quick Sort): ";
  sorter.print_arr(arr, SIZE);
  sorter.quick_sort(arr, 0, SIZE - 1);
  sorter.print_arr(arr, SIZE);

  // Generate and print a random array for counting sort
  sorter.generate_random_array(arr, SIZE);
  cout << "Original array (Counting Sort): ";
  sorter.print_arr(arr, SIZE);
  sorter.count_sort(arr, SIZE);
  sorter.print_arr(arr, SIZE);

  return 0;
}
