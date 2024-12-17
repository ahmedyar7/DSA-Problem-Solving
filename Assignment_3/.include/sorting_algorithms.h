#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include "sort_strategy.h"
using namespace std;

class QuickSort : public SortStrategy {
 public:
  void sort(
      DynamicArray<FileInfo>& files,
      function<bool(const FileInfo&, const FileInfo&)> comparator) override {
    quickSortHelper(files, 0, files.getSize() - 1, comparator);
  }

  string getName() const override { return "QuickSort"; }

 private:
  int partition(DynamicArray<FileInfo>& files, int low, int high,
                function<bool(const FileInfo&, const FileInfo&)> comparator) {
    FileInfo pivot = files[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
      if (comparator(files[j], pivot)) {
        ++i;
        swap(files[i], files[j]);
      }
    }
    swap(files[i + 1], files[high]);
    return i + 1;
  }

  void quickSortHelper(
      DynamicArray<FileInfo>& files, int low, int high,
      function<bool(const FileInfo&, const FileInfo&)> comparator) {
    if (low < high) {
      int pivotIndex = partition(files, low, high, comparator);
      quickSortHelper(files, low, pivotIndex - 1, comparator);
      quickSortHelper(files, pivotIndex + 1, high, comparator);
    }
  }
};

class SelectionSort : public SortStrategy {
 public:
  void sort(
      DynamicArray<FileInfo>& files,
      function<bool(const FileInfo&, const FileInfo&)> comparator) override {
    size_t n = files.getSize();
    for (size_t i = 0; i < n - 1; ++i) {
      size_t min_idx = i;
      for (size_t j = i + 1; j < n; ++j) {
        if (comparator(files[j], files[min_idx])) {
          min_idx = j;
        }
      }
      if (min_idx != i) {
        swap(files[i], files[min_idx]);
      }
    }
  }

  string getName() const override { return "Selection Sort"; }
};

class MergeSort : public SortStrategy {
 public:
  void sort(
      DynamicArray<FileInfo>& files,
      function<bool(const FileInfo&, const FileInfo&)> comparator) override {
    mergeSortHelper(files, 0, files.getSize() - 1, comparator);
  }

  string getName() const override { return "MergeSort"; }

 private:
  void merge(DynamicArray<FileInfo>& files, int left, int mid, int right,
             function<bool(const FileInfo&, const FileInfo&)> comparator) {
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
      function<bool(const FileInfo&, const FileInfo&)> comparator) {
    if (left < right) {
      int mid = left + (right - left) / 2;
      mergeSortHelper(files, left, mid, comparator);
      mergeSortHelper(files, mid + 1, right, comparator);
      merge(files, left, mid, right, comparator);
    }
  }
};

class InsertionSort : public SortStrategy {
 public:
  void sort(
      DynamicArray<FileInfo>& files,
      function<bool(const FileInfo&, const FileInfo&)> comparator) override {
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

  string getName() const override { return "Insertion Sort"; }
};

class BubbleSort : public SortStrategy {
 public:
  void sort(
      DynamicArray<FileInfo>& files,
      function<bool(const FileInfo&, const FileInfo&)> comparator) override {
    size_t n = files.getSize();
    for (size_t i = 0; i < n - 1; ++i) {
      bool swapped = false;
      for (size_t j = 0; j < n - i - 1; ++j) {
        if (comparator(files[j + 1], files[j])) {
          swap(files[j], files[j + 1]);
          swapped = true;
        }
      }
      // If no swapping occurred, array is already sorted
      if (!swapped) break;
    }
  }

  string getName() const override { return "Bubble Sort"; }
};
#endif