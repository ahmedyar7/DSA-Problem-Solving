#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int print2largest(vector<int>& arr) {
    int largest = arr[0];
    int second_largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] > largest) {
        second_largest = largest;
        largest = arr[i];
      }

      else if (arr[i] < largest && arr[i] > second_largest) {
        second_largest = arr[i];
      }
    }

    if (second_largest == INT_MIN) {
      return -1;
    }
    return second_largest;
  }

  bool check(vector<int>& arr) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
      if (arr[i] > arr[(i + 1) % n]) {
        count++;
      }
    }

    if (count > 1) {
      return false;
    } else {
      return true;
    }
  }

  int removeDuplicates(vector<int>& arr) {
    int n = arr.size();
    int i = 0;

    for (int j = 0; j < n; j++) {
      if (arr[j] != arr[i]) {
        arr[++i] = arr[j];
      }
    }

    return (i + 1);
  }

  void rotate(vector<int>& arr, int k) {
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
  }

  void moveZeroes(vector<int>& arr) {
    int j = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == 0) {
        j = i;
        break;
      }
    }

    for (int i = j + 1; i < arr.size(); i++) {
      if (arr[i] != 0) {
        swap(arr[i], arr[j]);
        j++;
      }
    }
  }

  int removeElement(vector<int>& arr, int val) {
    int j = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
      if (arr[i] != val) {
        arr[j++] = arr[i];
      }
    }
    return j;
  }

  vector<int> findUnion(vector<int>& A, vector<int>& B, int n1, int n2) {
    int i = 0;
    int j = 0;
    vector<int> union_arr;

    while (i < n1 && j < n2) {
      if (A[i] <= B[j]) {
        if (union_arr.empty() || union_arr.back() != A[i]) {
          union_arr.push_back(A[i]);
        }
        i++;
      }

      else {
        if (union_arr.empty() || union_arr.back() != B[j]) {
          union_arr.push_back(B[j]);
        }
        j++;
      }
    }

    while (i < n1) {
      if (union_arr.empty() || union_arr.back() != A[i]) {
        union_arr.push_back(A[i]);
      }
      i++;
    }

    while (j < n2) {
      if (union_arr.empty() || union_arr.back() != B[j]) {
        union_arr.push_back(B[j]);
      }
      j++;
    }

    for (auto it : union_arr) {
      cout << it << " ";
    }
    cout << endl;
  }

  void intersection(vector<int>& A, vector<int>& B, int n1, int n2) {
    int i = 0;
    int j = 0;
    vector<int> intersection_arr;

    while (i < n1 && j < n2) {
      if (A[i] == B[j]) {
        intersection_arr.push_back(A[i]);
        i++;
        j++;
      } else if (A[i] < B[j]) {
        i++;
      } else {
        j++;
      }
    }

    for (auto it : intersection_arr) {
      cout << it << " ";
    }

    cout << endl;
  }

  int findMaxConsecutiveOnes(vector<int>& arr) {
    int maximum_count = 0;
    int counter = 0;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == 1) {
        counter++;
        maximum_count = max(maximum_count, counter);
      } else {
        counter = 0;
      }
    }

    return maximum_count;
  }

  int singleNumber(vector<int>& arr) {
    unordered_map<int, int> hash;

    for (auto it : arr) {
      hash[it]++;
    }

    for (auto it : hash) {
      if (it.second == 1) {
        return it.first;
      }
    }

    return -1;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  Solution solution;
  while (t--) {
    int n;
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }

    cout << solution.singleNumber(A) << endl;
    // solution.removeElement(arr, val);
    // for (int i = 0; i < n; i++) {
    //   cout << arr[i] << " ";
    // }
    // cout << endl;
  }

  return 0;
}
