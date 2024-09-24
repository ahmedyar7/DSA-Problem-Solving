// #include <bits/stdc++.h>
// using namespace std;

// void merge(int arr[], int low, int mid, int high) {
//   vector<int> temp(high - low +
//                    1);  // Use std::vector instead of a static array
//   int left = low;
//   int right = mid + 1;
//   int k = 0;

//   while (left <= mid && right <= high) {
//     if (arr[left] <= arr[right]) {
//       temp[k++] = arr[left++];
//     } else {
//       temp[k++] = arr[right++];
//     }
//   }

//   while (left <= mid) {
//     temp[k++] = arr[left++];
//   }

//   while (right <= high) {
//     temp[k++] = arr[right++];
//   }

//   for (int i = 0; i < k; i++) {
//     arr[low + i] = temp[i];
//   }
// }

// void merge_sort(int arr[], int low, int high) {
//   if (low < high) {
//     int mid = (low + high) / 2;

//     merge_sort(arr, low, mid);
//     merge_sort(arr, mid + 1, high);

//     merge(arr, low, mid, high);
//   }
// }

// int main() {
//   int arr[] = {38, 27, 43, 3, 9, 82, 10};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   cout << "Original array: ";
//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }
//   cout << endl;

//   merge_sort(arr, 0, n - 1);

//   cout << "Sorted array: ";
//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }
//   cout << endl;

//   return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void merge(int arr[], int low, int mid, int high) {
//   vector<int> temp(high - low + 1);
//   int left = low;
//   int right = mid + 1;
//   int k = 0;

//   while (left <= mid && right <= high) {
//     if (arr[left] <= arr[right]) {
//       temp[k++] = arr[left++];
//     } else {
//       temp[k++] = arr[right++];
//     }
//   }

//   while (left <= mid) {
//     temp[k++] = arr[left++];
//   }

//   while (right <= high) {
//     temp[k++] = arr[right++];
//   }

//   for (int i = 0; i < k; i++) {
//     arr[low + i] = temp[i];
//   }
// }

// void merge_sort(int arr[], int low, int high) {
//   if (low < high) {
//     int mid = (low + high) / 2;
//     merge_sort(arr, low, mid);
//     merge_sort(arr, mid + 1, high);
//     merge(arr, low, mid, high);
//   }
// }

// int main() {
//   int arr[] = {13, 34, 12, 4, 45, 34, 65, 23, 1};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   merge_sort(arr, 0, n - 1);

//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;

// void merge(int arr[], int low, int mid, int high) {
//   vector<int> temp(high - low + 1);
//   int left = low;
//   int right = mid + 1;
//   int k = 0;

//   while (left <= mid && right <= high) {
//     if (arr[left] <= arr[right]) {
//       temp[k++] = arr[left++];
//     } else {
//       temp[k++] = arr[right++];
//     }
//   }

//   while (left <= mid) {
//     temp[k++] = arr[left++];
//   }

//   while (right <= high) {
//     temp[k++] = arr[right++];
//   }

//   for (int i = 0; i < k; i++) {
//     arr[low + i] = temp[i];
//   }
// }

// void merge_sort(int arr[], int low, int high) {
//   if (low < high) {
//     int mid = (low + high) / 2;

//     merge_sort(arr, low, mid);

//     merge_sort(arr, mid + 1, high);

//     merge(arr, low, mid, high);
//   }
// }

// int main() {
//   int arr[] = {13, 34, 12, 4, 45, 34, 65, 23, 1};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   merge_sort(arr, 0, n - 1);

//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;

// void merge(vector<int>& arr, int low, int mid, int high) {
//   vector<int> temp;
//   int left = low;
//   int right = mid + 1;

//   while (left <= mid && right <= high) {
//     if (arr[left] <= arr[right]) {
//       temp.push_back(arr[left]);
//       left++;
//     } else {
//       temp.push_back(arr[right]);
//       right++;
//     }
//   }

//   while (left <= mid) {
//     temp.push_back(arr[left]);
//     left++;
//   }

//   while (right <= high) {
//     temp.push_back(arr[right]);
//     right++;
//   }

//   for (int i = low; i < high; i++) {
//     arr[i] = temp[i - low];
//   }
// }

// void mergeSort(vector<int>& arr, int low, int high) {
//   if (low < high) {
//     int mid = (low + high) / 2;
//     mergeSort(arr, low, mid);
//     mergeSort(arr, mid + 1, high);
//     merge(arr, low, mid, high);
//   }
// }

// int main() {
//   vector<int> arr = {12, 34, 54, 13, 4, 5, 32, 54, 55, 22};
//   int n = arr.size();

//   mergeSort(arr, 0, n - 1);
//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;

// void merge(int arr[], int low, int mid, int high) {
//   vector<int> temp;
//   int left = low;
//   int right = mid + 1;

//   while (left <= mid && right <= high) {
//     if (arr[left] <= arr[right]) {
//       temp.push_back(arr[left]);
//       left++;
//     } else {
//       temp.push_back(arr[right]);
//       right++;
//     }
//   }

//   while (left <= mid) {
//     temp.push_back(arr[left]);
//     left++;
//   }
//   while (right <= high) {
//     temp.push_back(arr[right]);
//     right++;
//   }

//   for (int i = low; i <= high; i++) {
//     arr[i] = temp[i - low];
//   }
// }

// void mergeSort(int arr[], int low, int high) {
//   if (low < high) {
//     int mid = (high + low) / 2;
//     mergeSort(arr, low, mid);
//     mergeSort(arr, mid + 1, high);
//     merge(arr, low, mid, high);
//   }
// }

// int main() {
//   int arr[] = {23, 12, 54, 6, 3, 22, 4, 234};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   mergeSort(arr, 0, n - 1);

//   for (int i = 0; i < n; i++) cout << arr[i] << " ";
// }

// #include <bits/stdc++.h>
// using namespace std;

// void merge(int arr[], int low, int mid, int high) {
//   int left = low;
//   int right = mid + 1;
//   vector<int> temp;
//   while (left <= mid && right <= high) {
//     if (arr[left] <= arr[right]) {
//       temp.push_back(arr[left]);
//       left++;
//     } else {
//       temp.push_back(arr[right]);
//       right++;
//     }
//   }
//   while (left <= mid) {
//     temp.push_back(arr[left]);
//     left++;
//   }
//   while (right <= high) {
//     temp.push_back(arr[right]);
//     right++;
//   }
//   for (int i = low; i <= high; i++) {
//     arr[i] = temp[i - low];
//   }
// }

// void mergesort(int arr[], int low, int high) {
//   if (low < high) {
//     int mid = (low + high) / 2;
//     mergesort(arr, low, mid);
//     mergesort(arr, mid + 1, high);
//     merge(arr, low, mid, high);
//   }
// }

// int main() {
//   int arr[] = {23, 12, 54, 6, 3, 22, 4, 234};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   mergesort(arr, 0, n - 1);

//   for (int i = 0; i < n; i++) cout << arr[i] << " ";
// }

// #include <bits/stdc++.h>
// using namespace std;

// void merge(int arr[], int low, int mid, int high) {
//   int left = low;
//   int right = mid + 1;
//   vector<int> temp;
//   while (left <= mid && right <= high) {
//     if (arr[left] <= arr[right]) {
//       temp.push_back(arr[left]);
//       left++;
//     } else {
//       temp.push_back(arr[right]);
//       right++;
//     }
//   }
//   while (left <= mid) {
//     temp.push_back(arr[left]);
//     left++;
//   }
//   while (right <= high) {
//     temp.push_back(arr[right]);
//     right++;
//   }
//   for (int i = low; i <= high; i++) arr[i] = temp[i - low];
// }

// void mergesort(int arr[], int low, int high) {
//   if (low < high) {
//     int mid = (low + high) / 2;
//     mergesort(arr, low, mid);
//     mergesort(arr, mid + 1, high);
//     merge(arr, low, mid, high);
//   }
// }

// int main() {
//   int arr[] = {23, 12, 54, 6, 3, 22, 4, 234};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   mergesort(arr, 0, n - 1);

//   for (int i = 0; i < n; i++) cout << arr[i] << " ";
// }

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  vector<int> temp;
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }
  for (int i = low; i <= high; i++) arr[i] = temp[i - low];
}

void mergesort(int arr[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

int main() {
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergesort(arr, 0, n - 1);

  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}