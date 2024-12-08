#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

vector<int> generateRandomArray(int size) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(1, 100);

  vector<int> array(size);
  for (int& num : array) {
    num = dist(gen);
  }
  return array;
}

void measureSortTime(const vector<int>& array) {
  vector<int> temp = array;
  auto start = chrono::high_resolution_clock::now();
  sort(temp.begin(), temp.end());
  auto end = chrono::high_resolution_clock::now();

  double duration = chrono::duration<double, milli>(end - start).count();
  cout << "Time: " << duration << " ms\n";
}

void measureBestWorstCases(const std::vector<int>& array) {
  // Ascending sorted (best case for some implementations)
  std::vector<int> ascending = array;
  std::sort(ascending.begin(), ascending.end());
  std::cout << "Best Case: ";
  measureSortTime(ascending);

  // Descending sorted (worst case for some implementations)
  std::vector<int> descending = array;
  std::sort(descending.rbegin(), descending.rend());
  std::cout << "Worst Case: ";
  measureSortTime(descending);
}

int main() {
  for (int size : {100, 1000, 10000, 100000, 1000000}) {
    std::cout << "Array size " << size << ":\n";
    auto array = generateRandomArray(size);
    measureBestWorstCases(array);
  }
  return 0;
}
