

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  //. Remove Duplicates from an array
  void remove_duplicates() {
    int arr[] = {1, 1, 2, 2, 3, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    for (int j = 1; j < n; j++) {
      if (arr[i] != arr[j]) {
        arr[++i] = arr[j];
      }
    }
    for (int k = 0; k < i; k++) {
      cout << arr[k] << " ";
    }
  }

  // . Left Rotate Array by one number

  void left_rotate_once() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp = arr[0];
    for (int i = 1; i < n; i++) {
      arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
  }

  //. Check Sorted & Rotated

  void check_sorted_n_rotated() {
    int arr[] = {2, 3, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (arr[n + 1] < (arr[i % n])) count++;
    }
    if (count > 1)
      cout << "True";
    else
      cout << "False";
  }

  // . 2nd Largest Element

  void second_largest_element() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 7};
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
    cout << second_largest;
  }

  // . Rotate The array by k places
  void rotate_array_by_k_places() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
    reverse(arr, arr + n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
  }

  // . Move all zeros to the end
  void move_all_zeros() {
    int arr[] = {1, 0, 1, 2, 0, 3, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int j = INT_MIN;
    for (int i = 0; i < n; i++) {
      if (arr[i] == 0) {
        j = i;
        break;
      }
    }
    if (j == INT_MIN) cout << "No zero element found";

    for (int i = j + 1; i < n; i++) {
      if (arr[i] != 0) {
        swap(arr[i], arr[j]);
        j++;
      }
    }

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
  }

  // . UNION OF ARRAYS

  void union_of_arrays() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {2, 3, 4, 5, 6, 7};
    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int i = 0;
    int j = 0;
    vector<int> ans;

    while (i < n1 && j < n2) {
      if (A[i] <= B[j]) {
        if (ans.empty() || ans.back() != A[i]) {
          ans.push_back(A[i]);
        }
        i++;
      } else {
        if (ans.empty() || ans.back() != B[j]) {
          ans.push_back(B[j]);
        }
        j++;
      }
    }
    while (i < n1) {
      if (ans.empty() || ans.back() != A[i]) {
        ans.push_back(A[i]);
      }
      i++;
    }
    while (j < n2) {
      if (ans.empty() || ans.back() != B[j]) {
        ans.push_back(B[j]);
      }
      j++;
    }

    for (auto it : ans) cout << it << " ";
  }

  // . INTERSECTION OF ARRAYS

  void intersection_of_array() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {2, 3, 4, 5, 6, 7};
    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i <= n1 && j <= n2) {
      if (A[i] == B[j]) {
        ans.push_back(A[i]);
        i++;
        j++;
      } else if (A[i] < B[j]) {
        i++;
      } else {
        j++;
      }
    }
    for (auto it : ans) cout << it << " ";
  }

  int missingNumber(vector<int>& arr) {
    int n = arr.size();
    int sum = (n * (n + 1)) / 2;
    int s2 = 0;
    for (int i = 0; i < n; i++) {
      s2 += arr[i];
    }
    return (sum - s2);
  }

  int findMaxConsecutiveOnes(vector<int>& arr) {
    int counter = 0;
    int maxi = 0;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == 1) {
        counter++;
        maxi = max(maxi, counter);
      } else {
        counter = 0;
      }
    }
    return maxi;
  }

  int singleNumber_I(vector<int>& arr) {
    int n = arr.size();
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n; i++) {
      hash[arr[i]]++;
    }
    for (int i = 0; i < hash.size(); i++) {
      if (hash[i] == 1) {
        return i;
      }
    }
    return -1;
  }

  int singleNumber_II(vector<int>& arr) {
    int n = arr.size();
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

  //. Merge Sort
  void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
      if (arr[left] <= arr[right]) {
        temp.push_back(arr[left]);
        left++;
      } else {
        temp.push_back(arr[right]);
        right++;
      }
    }

    while (left <= mid) {
      temp.push_back(arr[left]);
      left++;
    }

    while (right <= high) {
      temp.push_back(arr[right]);
      right++;
    }

    for (int i = low; i <= high; i++) {
      arr[i] = temp[i - low];
    }
  }

  void mergesort(vector<int>& arr, int low, int high) {
    if (low < high) {
      int mid = (low + high) / 2;
      mergesort(arr, low, mid);
      mergesort(arr, mid + 1, high);
      merge(arr, low, mid, high);
    }
  }

  //. QUICK SORT

  int partition(vector<int>& arr, int low, int high) {
    int i = low;
    int j = high;
    int pivot = arr[low];

    while (i < j) {
      while (arr[i] <= pivot && i <= high - 1) {
        i++;
      }
      while (arr[j] > pivot && j >= low + 1) {
        j--;
      }
      if (i < j) {
        swap(arr[i], arr[j]);
      }
    }
    swap(arr[low], arr[j]);
    return j;
  }

  void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
      int index = partition(arr, low, high);
      quicksort(arr, low, index - 1);
      quicksort(arr, index + 1, high);
    }
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    solution.quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
