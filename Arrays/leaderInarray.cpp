// BRUTE FORCE APPROACH
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> ans;
    bool is_greater = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                is_greater = false;
                break;
            }
        }
        if (is_greater == true)
        {
            ans.push_back(arr[i]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}