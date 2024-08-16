// #include <bits/stdc++.h>
// using namespace std;

// int sort(int arr[], int low, int high) {
//   int pivot = low;
//   int i = low;
//   int j = high;

//   while (i < j) {
//     while (arr[i] <= arr[pivot] && i <= high - 1) {
//       i++;
//     }
//     while (arr[j] > arr[pivot] && j >= low + 1) {
//       j--;
//     }
//     if (i < j) {
//       swap(arr[i], arr[j]);
//     } else {
//       break;
//     }
//   }
//   swap(arr[low], arr[j]);
//   return j;
// }

// void quick_sort(int arr[], int low, int high) {
//   if (low < high) {
//     int partition_index = sort(arr, low, high);
//     quick_sort(arr, low, partition_index - 1);
//     quick_sort(arr, partition_index + 1, high);
//   }
// }

// int main() {
//   int arr[] = {4, 6, 5, 7, 9, 1, 3};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   quick_sort(arr, 0, n - 1);

//   for (int i = 0; i < n; i++) cout << arr[i] << " ";
// }

// #include <bits/stdc++.h>
// using namespace std;
// int partition(int arr[], int low, int high);
// void quickSort(int arr[], int low, int high) {
//   if (low < high) {
//     int index = partition(arr, low, high);
//     quickSort(arr, low, index - 1);
//     quickSort(arr, index + 1, high);
//   }
// }

// int partition(int arr[], int low, int high) {
//   int pivot = low;
//   int i = low;
//   int j = high;

//   while (i < j) {
//     while (arr[i] <= arr[pivot] && i <= high - 1) {
//       i++;
//     }
//     while (arr[j] > arr[pivot] && j >= low + 1) {
//       j--;
//     }
//     if (i < j) {
//       swap(arr[i], arr[j]);
//     } else {
//       break;
//     }
//   }
//   swap(arr[low], arr[j]);
//   return j;
// }

// int main() {
//   int arr[] = {4, 1, 3, 9, 7};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   quickSort(arr, 0, n - 1);

//   for (int i = 0; i < n; i++) cout << arr[i] << " ";
// }

// #include <bits/stdc++.h>
// using namespace std;

// int partition(int arr[], int low, int high) {
//   int pivot = arr[low];
//   int j = high;
//   int i = low;
//   while (i < j) {
//     while (arr[i] <= pivot && i <= high - 1) i++;
//     while (arr[j] > pivot && j >= low + 1) j--;
//     if (i < j)
//       swap(arr[i], arr[j]);
//     else
//       break;
//   }
//   swap(arr[low], arr[j]);
//   return j;
// }

// void quickSort(int arr[], int low, int high) {
//   if (low < high) {
//     int index = partition(arr, low, high);
//     quickSort(arr, low, index - 1);
//     quickSort(arr, index + 1, high);
//   }
// }

// int main() {
//   int arr[] = {4, 1, 3, 9, 7};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   quickSort(arr, 0, n - 1);

//   for (int i = 0; i < n; i++) cout << arr[i] << " ";
// }

// #include <bits/stdc++.h>
// using namespace std;

// int partition(int arr[], int low, int high) {
//   int pivot = arr[low];
//   int j = high;
//   int i = low;

//   while (i < j) {
//     while (arr[i] <= pivot && i <= high - 1) i++;
//     while (arr[j] > pivot && j >= low + 1) j--;
//     if (i < j)
//       swap(arr[i], arr[j]);
//     else
//       break;
//   }
//   swap(arr[low], arr[j]);
//   return j;
// }

// void quicksort(int arr[], int low, int high) {
//   if (low < high) {
//     int index = partition(arr, low, high);
//     quicksort(arr, low, index - 1);
//     quicksort(arr, index + 1, high);
//   }
// }

// int main() {
//   int arr[] = {23, 12, 1, 54, 55, 11, 44, 343};
//   int n = sizeof(arr) / sizeof(arr[0]);
//   quicksort(arr, 0, n - 1);
//   for (int i = 0; i < n; i++) cout << arr[i] << " ";
// }

// #include <bits/stdc++.h>
// using namespace std;

// int partition(int arr[], int low, int high) {
//   int pivot = arr[low];
//   int i = low;
//   int j = high;
//   while (i < j) {
//     while (arr[i] <= pivot && i <= high - 1) i++;
//     while (arr[j] > pivot && j >= low + 1) j--;
//     if (i < j)
//       swap(arr[i], arr[j]);
//     else
//       break;
//   }
//   swap(arr[low], arr[j]);
//   return j;
// }

// void quicksort(int arr[], int low, int high) {
//   if (low < high) {
//     int index = partition(arr, low, high);
//     quicksort(arr, low, index - 1);
//     quicksort(arr, index + 1, high);
//   }
// }

// int main() {
//   int arr[] = {23, 12, 1, 54, 55, 11, 44, 343};
//   int n = sizeof(arr) / sizeof(arr[0]);
//   quicksort(arr, 0, n - 1);
//   for (int i = 0; i < n; i++) cout << arr[i] << " ";
// }

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
  int i = low;
  int j = high;
  int pivot = arr[low];

  while (i < j) {
    while (arr[i] <= pivot && i <= high - 1) i++;
    while (arr[j] >= pivot && j > low + 1) j--;
    if (i < j)
      swap(arr[i], arr[j]);
    else
      break;
  }
  swap(arr[low], arr[j]);
  return j;
}

void quicksort(int arr[], int low, int high) {
  if (low < high) {
    int index = partition(arr, low, high);
    quicksort(arr, low, index - 1);
    quicksort(arr, index + 1, high);
  }
}

int main() {
  int arr[] = {23, 12, 1, 54, 55, 11, 44, 343};
  int n = sizeof(arr) / sizeof(arr[0]);
  quicksort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}