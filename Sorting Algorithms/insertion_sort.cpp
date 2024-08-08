// #include <bits/stdc++.h>

// using namespace std;

// void insert(int arr[], int i)
// {
//     int j = i;
//     while (j > 0 && arr[j - 1] > arr[j])
//     {
//         swap(arr[j - 1], arr[j]);
//         j--;
//     }
// }

// void insertion_sort(int arr[], int n)
// {
//     for (int i = 0; i <= n - 1; i++)
//     {
//         insert(arr, i);
//     }
// }

// int main()
// {
//     int N = 5;
//     int arr[] = {4, 1, 3, 9, 7};

//     insertion_sort(arr, N);

//     for (int i = 0; i < N; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main()
{
    int arr[] = {43, 12, 54, 66, 12, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}