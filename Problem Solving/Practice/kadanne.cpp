#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int array[] = {1, 2, 3, -2, 5};

    int sum = 0;
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        sum = sum + array[i];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << sum << endl;
}
