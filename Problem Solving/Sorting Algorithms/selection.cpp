// #include <bits/stdc++.h>
// using namespace std;

// void selection_sort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         int min_idx = i;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[min_idx])
//             {
//                 min_idx = j;
//             }
//         }
//         int temp = arr[min_idx];
//         arr[min_idx] = arr[i];
//         arr[i] = temp;
//     }
// }
// int main()
// {
//     int arr[] = {122, 34, 54, 23, 45, 12, 3, 43};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << n << endl;

//     selection_sort(arr, n);

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// void selection_sort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         int min_idx = i;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[min_idx] > arr[j])
//             {
//                 min_idx = j;
//             }
//         }
//         int temp = arr[min_idx];
//         arr[min_idx] = arr[i];
//         arr[i] = temp;
//     }
// }

// int main()
// {
//     int arr[] = {12, 533334, 56, 23, 65, 5665};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     selection_sort(arr, n);

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// void bubble_sort(int arr[], int n)
// {
//     for (int i = 0; i <= n - 1; i++)
//     {
//         int min_index = i;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[min_index])
//             {
//                 min_index = j;
//             }
//         }
//         int temp = arr[min_index];
//         arr[min_index] = arr[i];
//         arr[i] = temp;
//     }
// }

// int main()
// {

//     int arr[] = {43, 23, 5423, 45, 23, 54};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     bubble_sort(arr, n);

//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void selection_sort(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int min_index = i;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[min_index])
//             {
//                 min_index = j;
//             }
//         }
//         int temp = arr[min_index];
//         arr[min_index] = arr[i];
//         arr[i] = temp;
//     }
// }

// int main()
// {

//     int arr[] = {43, 23, 5423, 45, 23, 54};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     selection_sort(arr, n);

//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void selectionSort(int arr[], int n) {
//   for (int i = 0; i <= n - 1; i++) {
//     int min_idx = i;
//     for (int j = i + 1; j < n; j++) {
//       if (arr[j] < arr[min_idx]) {
//         min_idx = j;
//       }
//     }
//     int temp = arr[min_idx];
//     arr[min_idx] = arr[i];
//     arr[i] = temp;
//   }
// }

// int main() {
//   int arr[] = {1, 43, 2, 44, 65, 56, 343};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   selectionSort(arr, n);

//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }
// }

#include <bits/stdc++.h>
using namespace std;

void selectionsort(int arr[], int n) {
  for (int i = 0; i <= n - 1; i++) {
    int index = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[index]) {
        index = j;
      }
    }
    swap(arr[index], arr[i]);
  }
}

int main() {
  int arr[] = {1, 43, 2, 44, 65, 56, 343};
  int n = sizeof(arr) / sizeof(arr[0]);

  selectionsort(arr, n);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}