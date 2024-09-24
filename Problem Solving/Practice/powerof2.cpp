#include <iostream>
using namespace std;

bool isPowerofTwo(int n)
{

    if (n <= 0)
    {
        return false;
    }
    while (n % 2 == 0)
    {
        n = n / 2;
    }
    return n == 1;
}

int main()
{

    int z = 2;

    bool x = isPowerofTwo(x);
    cout << x << endl;
}