// #include <bits/stdc++.h>
// using namespace std;

// void reverse_array(int arr[], int n, int i)
// {
//     if (i >= n / 2)
//         return;
//     swap(arr[i], arr[n - i - 1]);
//     reverse_array(arr, n, i + 1);
// }

// void reverse_string(string &s, int i)
// {
//     if (i >= s.length())
//         return;

//     swap(s[i], s[s.length() - i - 1]);
//     reverse_string(s, i + 1);
// }

// bool is_palndriom(string s, int i)
// {
//     if (i >= s.length())
//         return true;
//     if (s[i] != s[s.length() - i - 1])
//         return false;
//     else
//         return true;
// }

// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 2};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     // reverse_array(arr, n, 0);

//     // for (int i = 0; i < n; i++)
//     // {
//     //     cout << arr[i] << " ";

//     // }

//     string s = "llldsm";
//     reverse_string(s, 0);
//     // bool x = is_palndriom(s, 0);
//     // cout << x << endl;
//     for (int i = 0; i < s.length(); i++)
//     {
//         cout << s[i] << " ";
//     }

#include <bits/stdc++.h>
using namespace std;
int counter = 1;
void print_till_n(int n)
{

    if (n >= counter)
    {

        cout << counter << " ";
        counter++;
        print_till_n(n);
    }
}

void reverse_array(int arr[], int n, int i)
{
    if (i >= n / 2)
    {
        return;
    }
    swap(arr[i], arr[n - i - 1]);
    reverse_array(arr, n, i + 1);
}

void reverse_string(string &str, int i)
{
    if (i >= str.length() / 2)
    {
        return;
    }
    swap(str[i], str[str.length() - i - 1]);
    reverse_string(str, i + 1);
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return factorial(n - 1) * n;
}

void print_num_reverse(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    print_num_reverse(n - 1);
}

int main()
{

    int arr[] = {1, 3, 4, 5, 6, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    // print_till_n(10);
    // reverse_array(arr, n, 0);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // string str = "racecar";
    // reverse_string(str, 0);
    // for (int i = 0; i < str.length(); i++)
    // {
    //     cout << str[i];
    // }

    cout << factorial(10);
}