#include <bits-stdc++.h>
using namespace std;

void declearation_of_vector() {
  vector<int> v;
  v.push_back(1);
  v.emplace_back(2);

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  vector<pair<int, int>> vec;
  vec.push_back({1, 2});
  vec.emplace_back(2, 3);  // Assumes to be pairs

  // Predefining the size and values of vector:
  vector<int> v2(5, 100);  // size and values
  vector<int> v3(5);       // Size only
  vector<int> v1(5, 20);
}

void itterators_in_vectors() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
  for (auto i = v.begin(); i != v.end(); i++) {
    cout << *(i) << " ";
  }
  cout << endl;
  for (auto it : v) {
    cout << it << " ";
  }
}

void vector_operation() {  //
  // .Erase Operation
  // vector<int> vec = {10, 20, 30, 40, 50, 60, 70};  // {1, 5}
  // vec.erase(vec.begin() + 1, vec.begin() + 4);

  //. Insert Operation
  vector<int> vec(2, 100);
  vec.insert(vec.begin(), 30);          // Right at Beginning
  vec.insert(vec.begin() + 1, 2, 200);  // Index[1]
  vec.insert(vec.begin() + 2, 300);     // Index[2]

  // copy vector
  vector<int> vec_copy(2, 5);
  vec.insert(vec.begin(), vec_copy.begin(), vec_copy.end());

  for (auto it : vec) {
    cout << it << " ";
  }

  // Size of vector
  vec.size();
  // Removes last element
  vec.pop_back();

  // This will perfrom the swap function
  vec.swap(vec);

  // This will clear the vector
  vec.clear();
}

int main() {
  vector_operation();
  //
}