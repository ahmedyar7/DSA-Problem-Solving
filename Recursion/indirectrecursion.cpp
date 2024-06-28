// #include <iostream>
// using namespace std;

// void function_A(int n);

// void function_B(int n)
// {
//     if (n > 1)
//     {
//         cout << n << endl;
//         function_A(n / 2);
//     }
// }

// void function_A(int n)
// {
//     if (n > 0)
//     {
//         cout << n << endl;
//         function_B(n - 1);
//     }
// }

// int main()
// {
//     function_A(20);
// }

#include <iostream>
using namespace std;

int funA(int n);

int funB(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        return funA(n / 2);
    }
}

int funA(int n)
{
    if (n > 1)
    {
        cout << n << endl;
        return funB(n - 1);
    }
}

int main()
{
    int x = funB(20);

    cout << x << endl;
}