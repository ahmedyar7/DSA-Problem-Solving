#include <bits/stdc++.h>
using namespace std;

int reverse_number(int n)
{
    int rnum = 0;
    while (n != 0)
    {
        int last = n % 10;
        n = n / 10;

        if ((rnum > INT32_MAX / 10) || (rnum < INT32_MIN / 10))
            return 0;

        rnum = rnum * 10 * last;
    }
    return rnum;
}

bool is_palindriom(int n)
{
    int original = n;
    int rnum = 0;
    while (n != 0)
    {
        int last = n % 10;
        n = n / 10;

        if ((rnum > INT_MAX / 10) || (rnum < INT_MIN / 10))
            return 0;

        rnum = rnum * 10 + last;
    }
    if (rnum == original)
        return true;
    return false;
}

int num_digits(int n)
{
    int count = 0;
    while (n > 0)
    {
        int last = n % 10;
        n = n / 10;
        count++;
    }
    cout << count;
}

int evenlyDivides(int N)
{
    int count = 0;
    int original_N = N;
    while (N > 0)
    {
        int last = N % 10;
        N = N / 10;
        if (last != 0 && original_N % last == 0)
        {
            count++;
        }
    }
    return count;
}

bool armstrong_num(int n)
{
    int original = n;
    int sum = 0;
    while (n > 0)
    {
        int digit = n % 10;
        sum = sum + (digit * digit * digit);
        n = n / 10;
    }
    if (original == sum)
        return true;

    return false;
}

long long sumOfDivisors(int N)
{
    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += (N / i) * i;
    }
    return sum;
}

int main()
{
    // reverse_number(7789);
    // num_digits(12332);

    // cout << sumOfDivisors(4);
    cout << sumOfDivisors(4);
}
