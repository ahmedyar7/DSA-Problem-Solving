#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <algorithm>  // For std::max
#include <iostream>

#include "file.h"

using namespace std;

class DynamicArray {
 private:
  File* files;   // Dynamic array of File objects
  int capacity;  // Capacity of the dynamic array
  int size;      // Current number of elements in the array

  // Resize function to expand the array when needed
  void resize() {
    capacity = capacity * 2;  // Double the capacity
    File* new_files = new File[capacity];

    // Copy files to new array
    for (int i = 0; i < size; i++) {
      new_files[i] = files[i];
    }

    delete[] files;     // Free old array
    files = new_files;  // Assign new array to files pointer
  }

 public:
  // Constructor
  DynamicArray(int initial_capacity = 10)
      : capacity(max(initial_capacity, 1)), size(0) {
    files = new File[capacity];  // Allocate memory for files array
  }

  // Destructor to release memory
  ~DynamicArray() { delete[] files; }

  // Add file to dynamic array (pass by const reference for efficiency)
  void push_back(const File& file) {
    if (size == capacity) resize();  // Resize if array is full
    files[size++] = file;            // Add file and increment size
  }

  // Access element at given index (const access)
  const File& operator[](int index) const { return files[index]; }

  // Get the current size (const function, as it doesn't modify the object)
  int get_size() const { return size; }

  // Optionally, you can add more utility functions like:
  // - Remove element from the array
  // - Get file at index (const)
};

#endif
