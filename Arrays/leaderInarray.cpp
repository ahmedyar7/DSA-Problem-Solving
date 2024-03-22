#include <iostream>
using namespace std;

// void printArray(int array[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int j;
//         for (j = i + 1; j < n; j++)
//         {
//             if (array[i] <= array[j])
//             {
//                 break;
//             }
//         }
//         if (j == n)
//         {
//             cout << array[i] << endl;
//         }
//     }
// }

/// SCaccing from the right

void printArray(int array[], int n)
{
    // Start from the right most side because the right most element is the leader always
    int max_from_right = array[n - 1];

    // Looping througth the right most side
    for (int i = n - 2; i >= 0; i--)
    {
        if (max_from_right < array[i])
        {
            max_from_right = array[i];
        }
    }
    cout << max_from_right << endl;
}

int main()
{
    int array[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(array) / sizeof(array[0]);

    printArray(array, n);
    return 0;
}