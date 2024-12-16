#include <chrono>
#include <ctime>
#include <filesystem>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "SortingStrategy.h"
// Selection Sort Implementation
class SelectionSort : public SortStrategy {
 public:
  void sort(DynamicArray<FileInfo>& files,
            std::function<bool(const FileInfo&, const FileInfo&)> comparator)
      override {
    size_t n = files.getSize();
    for (size_t i = 0; i < n - 1; ++i) {
      size_t min_idx = i;
      for (size_t j = i + 1; j < n; ++j) {
        if (comparator(files[j], files[min_idx])) {
          min_idx = j;
        }
      }
      if (min_idx != i) {
        std::swap(files[i], files[min_idx]);
      }
    }
  }

  std::string getName() const override { return "Selection Sort"; }
};