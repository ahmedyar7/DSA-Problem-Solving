#include <iostream>
using namespace std;

bool isPowerofTwo(int n)
{

    if (n == 0)
        return true;
    for (int i = 0; i < n; i++)
    {
        if ((n * (n * n)) % 2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{

    int z = 3;
    bool x = isPowerofTwo(x);
    cout << x << endl;
}