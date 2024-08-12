#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int arr[] = {12, 12, 34, 45, 53, 22, 22};
    // int n = sizeof(arr) / sizeof(arr[0]);

    // int hash[54] = {0};
    // for (int i = 0; i < n; i++)
    // {
    //     hash[arr[i]] += 1;
    // }
    // for (int i = 0; i < n; i++)
    //     cout << hash[22] << endl;

    string s = "abcdabehf";
    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }
    cout << hash['a'];
}
