#include <bits/stdc++.h>
using namespace std;

int count_digits(int n)
{
    int count = 0;
    while (n > 0)
    {
        int last = n % 10;
        n = n / 10;
        count++;
    }
    return count;
}

int reverse_a_number(int n)
{
    int rnum = 0;
    while (n != 0)
    {
        int last = n % 10;
        n = n / 10;
        if ((rnum < INT_MIN / 10) || (rnum > INT_MAX / 10))
            return 0;
        rnum = rnum * 10 + last;
    }
    return rnum;
}

bool check_palindriom(int n)
{
    int original = n;
    int rnum = 0;
    while (n != 0)
    {
        int last = n % 10;
        n = n / 10;
        if ((rnum < INT_MIN / 10) || (rnum > INT_MAX / 10))
            return 0;
        rnum = rnum * 10 + last;
    }
    if (original == rnum)
        return true;
    else
        return false;
}

bool is_armstrong(int n)
{
    int original = n;
    int sum = 0;
    while (n > 0)
    {
        int last = n % 10;
        sum = sum + (last * last * last);
        n = n / 10;
    }
    if (sum == original)
        return true;
    else
        return false;
}

int sumofdivisor(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum = sum + (n / i) * i;
    return sum;
}

int main()
{

    // cout << count_digits(123);
    // cout << reverse_a_number(123);

    // cout << check_palindriom(122);

    // cout << is_armstrong(371);
    cout << sumofdivisor(4);
}