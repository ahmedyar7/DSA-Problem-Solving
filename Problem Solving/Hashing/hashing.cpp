#include <bits/stdc++.h>
using namespace std;

void hashing_of_array() {
  int arr[] = {12, 12, 43, 34, 54, 23, 23};
  int n = sizeof(arr) / sizeof(arr[0]);
  int hash[55] = {0};
  for (int i = 0; i < n; i++) {
    hash[arr[i]]++;
  }
  for (int i = 0; i < 55; i++) {
    cout << i << " -> " << hash[i] << endl;
  }
}

void hashing_of_string() {
  string str = "abcdefabcfg";
  int hash[256] = {0};
  for (int i = 0; i < str.length(); i++) {
    hash[str[i]]++;
  }
  for (int i = 0; i < 256; i++) {
    cout << i << " -> " << hash[i] << endl;
  }
}

int main() {
  //  hashing_of_array();
  hashing_of_string();
}
