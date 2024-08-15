#include <bits/stdc++.h>
using namespace std;

void brute_force_approach() {
  vector<int> arr = {12, 4, 34, 54, 23, 5, 3, 44};
  int n = arr.size();
  sort(arr.begin(), arr.end());  // NlogN
  int largest = arr[n - 1];

  int second_largest = INT_MIN;

  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] != largest) {
      second_largest = arr[i];
      break;
    }
  }
  cout << largest << endl;
  cout << second_largest << endl;
}

void better_approach() {
  int arr[] = {12, 4, 34, 54, 23, 5, 3, 44};
  int n = sizeof(arr) / sizeof(arr[0]);

  int largest = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }

  int second_largest = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (arr[i] != largest) {
      second_largest = arr[i];
    }
  }

  cout << largest << endl;
  cout << second_largest << endl;
}

void optimal_approach() {
  int arr[] = {28004, 23544, 32504, 29493, 17013,
               17850, 18952, 12089, 5126,  10353};
  int n = sizeof(arr) / sizeof(arr[0]);
  int largest = arr[0];
  int second_largest = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (arr[i] > largest) {
      second_largest = largest;
      largest = arr[i];
    } else if (arr[i] < largest && arr[i] > second_largest) {
      second_largest = arr[i];
    }
  }

  cout << largest << endl;
  cout << second_largest << endl;
}

int main() { optimal_approach(); }

// .----------- GEEK FOR GEEKS SOLUTION --------------------//

class Solution {
 public:
  // Function returns the second
  // largest elements
  int print2largest(vector<int> &arr) {
    int largest = arr[0];
    int second_largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] > largest) {
        second_largest = largest;
        largest = arr[i];
      } else if (arr[i] < largest && arr[i] > second_largest) {
        second_largest = arr[i];
      }
    }

    if (second_largest == INT_MIN) return -1;
    return second_largest;
  }
};