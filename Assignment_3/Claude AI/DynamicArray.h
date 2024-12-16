#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <chrono>
#include <ctime>
#include <filesystem>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// Custom Dynamic Array (Similar to vector but manually implemented)
template <typename T>
class DynamicArray {
 private:
  T* array;
  size_t capacity;
  size_t size;

  void resize(size_t newCapacity) {
    T* newArray = new T[newCapacity];
    for (size_t i = 0; i < size; ++i) {
      newArray[i] = std::move(array[i]);
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
  }

 public:
  DynamicArray() : array(new T[1]), capacity(1), size(0) {}

  ~DynamicArray() { delete[] array; }

  void push_back(const T& element) {
    if (size == capacity) {
      resize(capacity * 2);
    }
    array[size++] = element;
  }

  T& operator[](size_t index) {
    if (index >= size) {
      throw std::out_of_range("Index out of range");
    }
    return array[index];
  }

  size_t getSize() const { return size; }

  void clear() {
    delete[] array;
    array = new T[1];
    capacity = 1;
    size = 0;
  }
};

#endif