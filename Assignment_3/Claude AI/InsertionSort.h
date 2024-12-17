// #include <algorithm>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "SortingStrategy.h"
class InsertionSort : public SortStrategy {
 public:
  void sort(DynamicArray<FileInfo>& files,
            std::function<bool(const FileInfo&, const FileInfo&)> comparator)
      override {
    size_t n = files.getSize();
    for (size_t i = 1; i < n; ++i) {
      FileInfo key = files[i];
      int j = i - 1;

      // Move elements that are greater than key to one position ahead
      while (j >= 0 && comparator(key, files[j])) {
        files[j + 1] = files[j];
        --j;
      }
      files[j + 1] = key;
    }
  }

  std::string getName() const override { return "Insertion Sort"; }
};