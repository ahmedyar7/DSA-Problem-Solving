#include "SortingStrategy.h"
// #include <algorithm>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// QuickSort Implementation (unchanged)
class QuickSort : public SortStrategy {
 public:
  void sort(DynamicArray<FileInfo>& files,
            std::function<bool(const FileInfo&, const FileInfo&)> comparator)
      override {
    quickSortHelper(files, 0, files.getSize() - 1, comparator);
  }

  std::string getName() const override { return "QuickSort"; }

 private:
  int partition(
      DynamicArray<FileInfo>& files, int low, int high,
      std::function<bool(const FileInfo&, const FileInfo&)> comparator) {
    FileInfo pivot = files[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
      if (comparator(files[j], pivot)) {
        ++i;
        std::swap(files[i], files[j]);
      }
    }
    std::swap(files[i + 1], files[high]);
    return i + 1;
  }

  void quickSortHelper(
      DynamicArray<FileInfo>& files, int low, int high,
      std::function<bool(const FileInfo&, const FileInfo&)> comparator) {
    if (low < high) {
      int pivotIndex = partition(files, low, high, comparator);
      quickSortHelper(files, low, pivotIndex - 1, comparator);
      quickSortHelper(files, pivotIndex + 1, high, comparator);
    }
  }
};