#include <iostream>
using namespace std;

void function_A(int n);

void function_B(int n)
{
    if (n > 1)
    {
        cout << n << endl;
        function_A(n / 2);
    }
}

void function_A(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        function_B(n - 1);
    }
}

int main()
{
    function_A(20);
}