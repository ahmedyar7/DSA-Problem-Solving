#include <bits/stdc++.h>
using namespace std;

// Pairs
void explain_pair()
{
    pair<int, int> p1 = {1, 3};

    cout << p1.first << " " << p1.second << endl;

    pair<int, pair<int, int>> p = {1, {3, 4}};
    cout << p.first << " " << p.second.second << " " << p.second.first << "\n";

    pair<int, int> arr[] = {{1, 2},
                            {2, 5},
                            {5, 1}};

    cout << arr[1].second;
}

// Containers -> Vector

void explain_vector()
{
    vector<int> v;
    v.push_back(2);
    v.emplace_back(2);

    vector<pair<int, int>> vec;

    v.emplace_back(1, 2);

    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << " ";

    it = it + 2;
    cout << *(it) << " ";

    vector<int>::iterator it = v.end();
    // vector<int>::iterator it = v.rend();   // Reverse end
    //  vector<int>::iterator it = v.rbegin(); // Reverse Begin

    cout << v[0] << " " << v.at(0);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    for (auto it : v)
    {
        cout << it << " ";
    }

    // {10, 20, 12, 23}
    v.erase(v.begin() + 1);

    // {10, 20, 12, 23, 35}
    v.erase(v.begin() + 2, v.begin() + 4);
}

int main()
{

    explain_vector();
}