#include <bits/stdc++.h>
using namespace std;

void map_of_array() {
  int arr[] = {23, 43, 54, 23, 54, 65, 23, 1, 2};
  int n = sizeof(arr) / sizeof(arr[0]);

  map<int, int> map;
  cout << "Ordered Map" << endl;
  for (int i = 0; i < n; i++) {
    map[arr[i]]++;
  }
  for (auto it : map) {
    cout << it.first << " -> " << it.second << endl;
  }

  cout << endl;
  cout << "Unordered Map" << endl;
  unordered_map<int, int> unordered_map;
  for (int i = 0; i < n; i++) {
    unordered_map[arr[i]]++;
  }
  for (auto it : unordered_map) {
    cout << it.first << " -> " << it.second << endl;
  }
}

void map_of_string() {
  string str = "ahmedyarisabigbigloser";
  map<char, int> ordered_map;

  cout << "Ordered Map" << endl;
  for (int i = 0; i < str.length(); i++) {
    ordered_map[str[i]]++;
  }
  for (auto it : ordered_map) {
    cout << it.first << " -> " << it.second << endl;
  }

  cout << "\nUnordered Map\n";

  unordered_map<char, int> unordered_map;
  for (int i = 0; i < str.length(); i++) {
    unordered_map[str[i]]++;
  }
  for (auto it : unordered_map) {
    cout << it.first << " -> " << it.second << endl;
  }
}

int main() {
  // map_of_array();
  map_of_string();
}