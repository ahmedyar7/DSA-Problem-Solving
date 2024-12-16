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
// Bubble Sort Implementation
class BubbleSort : public SortStrategy {
 public:
  void sort(DynamicArray<FileInfo>& files,
            std::function<bool(const FileInfo&, const FileInfo&)> comparator)
      override {
    size_t n = files.getSize();
    for (size_t i = 0; i < n - 1; ++i) {
      bool swapped = false;
      for (size_t j = 0; j < n - i - 1; ++j) {
        if (comparator(files[j + 1], files[j])) {
          std::swap(files[j], files[j + 1]);
          swapped = true;
        }
      }
      // If no swapping occurred, array is already sorted
      if (!swapped) break;
    }
  }

  std::string getName() const override { return "Bubble Sort"; }
};