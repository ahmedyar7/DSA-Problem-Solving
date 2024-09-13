#include <iostream>
using namespace std;

class DynamicArray {
 private:
  int size;
  int **arr;

 public:
  DynamicArray(int size) {
    arr = new int *[size];
    for (int i = 0; i < size; i++) {
      arr[i] = new int(0);
    }
  }

  ~DynamicArray() {
    for (int i = 0; i < size; i++) {
      delete arr[i];
    }
    delete[] arr;
  }

  void set_value(int index, int value) {
    if (index >= 0 && index < size) {
      *arr[index] = value;
    }
  }

  int get_value(int index) {
    if (index >= 0 && index < size) {
      return *arr[index];
    }
  }

  void print_array() {
    for (int i = 0; i < size; i++) {
      cout << *arr[i] << " ";
    }
    cout << "\n";
  }
};