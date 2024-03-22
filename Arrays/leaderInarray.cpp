#include <iostream>
using namespace std;

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (array[i] <= array[j])
            {
                break;
            }
        }
        if (j == n)
        {
            cout << array[i] << endl;
        }
    }
}

int main()
{
    int array[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(array) / sizeof(array[0]);

    printArray(array, n);
    return 0;
}