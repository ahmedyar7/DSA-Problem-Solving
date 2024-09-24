// #include <bits/stdc++.h>

// using namespace std;

// void bubble_sort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j + 1];
//                 arr[j + 1] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

// int main()
// {

//     int arr[] = {12, 334, 54, 23, 54, 67, 122};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     bubble_sort(arr, n);

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
//     for (int i = 0; i < n - 1; i++)
//     {
//         int did_swap = 0;
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j + 1], arr[j]);
//                 did_swap = 1;
//             }
//         }
//         if (did_swap == 0)
//         {
//             break;
//         }
//     }
// }

// int main()
// {
//     int arr[] = {24, 18, 38, 43, 14, 40, 1, 54};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     bubble_sort(arr, n);

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
//         int did_swap = 0;

//         for (int j = 0; j < n - i - 1; j++)
//         {printNosprintNos
//             if (arr[j + 1] < arr[j])
//             {
//                 swap(arr[j + 1], arr[j]);
//                 j = 1;
//             }
//         }
//         if (did_swap == 0)
//         {
//             break;
//         }
//     }
// }

// int main()
// {
//     int arr[] = {43, 11, 33, 54, 124};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     bubble_sort(arr, n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// void bubble_sort(int arr[], int n) {
//   for (int i = 0; i <= n - 1; i++) {
//     for (int j = 0; j < n - i - 1; j++) {
//       if (arr[j] > arr[j + 1]) {
//         int temp = arr[j + 1];
//         arr[j + 1] = arr[j];
//         arr[j] = temp;
//       }
//     }
//   }
// }

// int main() {
//   int arr[] = {12, 43, 54, 12, 45, 23, 54, 55};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   bubble_sort(arr, n);
//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }
// }

// #include <bits/stdc++.h>
// using namespace std;

// void bubbleSort(int arr[], int n) {
//   if (n == 0) {
//     return;
//   }
//   for (int i = 0; i < n - 1; i++) {
//     if (arr[i] > arr[i + 1]) {
//       int temp = arr[i];
//       arr[i] = arr[i + 1];
//       arr[i + 1] = temp;
//     }
//   }
// }

// int main() {
//   int arr[] = {12, 43, 54, 12, 45, 23, 54, 55};
//   int n = sizeof(arr) / sizeof(arr[0]);

//   bubbleSort(arr, n);
//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }
// }

#include <bits/stdc++.h>
using namespace std;

void bubblesort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {
  int arr[] = {12, 43, 54, 12, 45, 23, 54, 55};
  int n = sizeof(arr) / sizeof(arr[0]);

  bubblesort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}
