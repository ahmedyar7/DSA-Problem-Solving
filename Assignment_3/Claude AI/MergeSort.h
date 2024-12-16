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
// MergeSort Implementation (unchanged)
class MergeSort : public SortStrategy {
 public:
  void sort(DynamicArray<FileInfo>& files,
            std::function<bool(const FileInfo&, const FileInfo&)> comparator)
      override {
    mergeSortHelper(files, 0, files.getSize() - 1, comparator);
  }

  std::string getName() const override { return "MergeSort"; }

 private:
  void merge(DynamicArray<FileInfo>& files, int left, int mid, int right,
             std::function<bool(const FileInfo&, const FileInfo&)> comparator) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    DynamicArray<FileInfo> leftArray;
    DynamicArray<FileInfo> rightArray;

    for (int i = 0; i < n1; ++i) leftArray.push_back(files[left + i]);
    for (int j = 0; j < n2; ++j) rightArray.push_back(files[mid + 1 + j]);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
      if (comparator(leftArray[i], rightArray[j]) ||
          (!comparator(rightArray[j], leftArray[i])))
        files[k++] = leftArray[i++];
      else
        files[k++] = rightArray[j++];
    }

    while (i < n1) files[k++] = leftArray[i++];
    while (j < n2) files[k++] = rightArray[j++];
  }

  void mergeSortHelper(
      DynamicArray<FileInfo>& files, int left, int right,
      std::function<bool(const FileInfo&, const FileInfo&)> comparator) {
    if (left < right) {
      int mid = left + (right - left) / 2;
      mergeSortHelper(files, left, mid, comparator);
      mergeSortHelper(files, mid + 1, right, comparator);
      merge(files, left, mid, right, comparator);
    }
  }
};