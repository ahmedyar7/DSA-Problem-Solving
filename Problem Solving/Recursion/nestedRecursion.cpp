#include <iostream>
using namespace std;

int function(int n)
{
    if (n > 100)
    {
        return (n - 10);
    }
    else
    {
        return function(function(n + 11));
    }
}

int main()
{
    int x = function(95);
    cout << x << endl;
}