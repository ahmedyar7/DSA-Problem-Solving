#include <bits/stdc++.h>
using namespace std;

//.BRUTE FORCE APPROACh
/*
- Take a set Data Structure because it contain the unique and sorted elements
- Itterate over the 1st array and then place them in set
- Itterate over the 2nd array and then place them in set
- Take a union vector and itterate over the set and place the element of the set
to the union vector
- Return the union vector
*/

void union_of_sorted_array() {
  int arr1[] = {1, 2, 3, 3, 4, 5};
  int arr2[] = {1, 2, 3, 3, 8, 5, 9};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);

  set<int> st;

  for (int i = 0; i < n1; i++) st.insert(arr1[i]);
  for (int i = 0; i < n2; i++) st.insert(arr2[i]);

  vector<int> union_array;
  for (auto it : st) {
    union_array.push_back(it);
  }

  for (int i = 0; i < union_array.size(); i++) cout << union_array[i] << " ";
}

//. OPTIMAL SOLUTION
/*
- Take two pointer i & j place them at start of the sorted arrays
- Compare the elements of i and j the smaller of both of them should go to
union array
- Increment the i or j
- Compare the next element of i or j after incrementing and the previous element
of the union array
- If they are same then increment the pointer
- Else insert the element to the array
- If either of the array get exhausted
- Then compare the last union array element and the current element of the next
array
- And then place them.
*/

void union_of_sorted() {
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {1, 2, 3, 3};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);

  vector<int> union_arr;
  int i = 0;
  int j = 0;

  while (i < n1 && j < n2) {
    if (arr1[i] <= arr2[j]) {
      if (union_arr.size() == 0 || union_arr.back() != arr1[i]) {
        union_arr.push_back(arr1[i]);
      }
      i++;
    } else {
      if (union_arr.size() == 0 || union_arr.back() != arr2[j]) {
        union_arr.push_back(arr2[j]);
      }
      j++;
    }
  }

  while (i < n1) {
    if (union_arr.size() == 0 || union_arr.back() != arr1[i]) {
      union_arr.push_back(arr1[i]);
    }
    i++;
  }

  while (j < n2) {
    if (union_arr.size() == 0 || union_arr.back() != arr2[j]) {
      union_arr.push_back(arr2[j]);
    }
    j++;
  }

  for (int i = 0; i < union_arr.size(); i++) cout << union_arr[i] << " ";
}

int main() { union_of_sorted(); }