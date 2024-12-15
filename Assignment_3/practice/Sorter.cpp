#include "Sorter.h"

#include <algorithm>  // For swap
#include <chrono>     // For timing

// Quick Sort
int partition(std::vector<File>& files, int low, int high,
              const std::function<bool(const File&, const File&)>& comparator) {
  File pivot = files[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (comparator(files[j], pivot)) {
      i++;
      std::swap(files[i], files[j]);
    }
  }
  std::swap(files[i + 1], files[high]);
  return i + 1;
}

void Sorter::quickSort(
    std::vector<File>& files, int low, int high,
    const std::function<bool(const File&, const File&)>& comparator) {
  if (low < high) {
    int pi = partition(files, low, high, comparator);
    quickSort(files, low, pi - 1, comparator);
    quickSort(files, pi + 1, high, comparator);
  }
}

// Merge Sort
void merge(std::vector<File>& files, int left, int mid, int right,
           const std::function<bool(const File&, const File&)>& comparator) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<File> leftFiles(files.begin() + left, files.begin() + mid + 1);
  std::vector<File> rightFiles(files.begin() + mid + 1,
                               files.begin() + right + 1);

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (comparator(leftFiles[i], rightFiles[j])) {
      files[k++] = leftFiles[i++];
    } else {
      files[k++] = rightFiles[j++];
    }
  }

  while (i < n1) {
    files[k++] = leftFiles[i++];
  }

  while (j < n2) {
    files[k++] = rightFiles[j++];
  }
}

void Sorter::mergeSort(
    std::vector<File>& files, int left, int right,
    const std::function<bool(const File&, const File&)>& comparator) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(files, left, mid, comparator);
    mergeSort(files, mid + 1, right, comparator);
    merge(files, left, mid, right, comparator);
  }
}

// Insertion Sort
void Sorter::insertionSort(
    std::vector<File>& files,
    const std::function<bool(const File&, const File&)>& comparator) {
  for (size_t i = 1; i < files.size(); i++) {
    File key = files[i];
    int j = i - 1;
    while (j >= 0 && comparator(key, files[j])) {
      files[j + 1] = files[j];
      j--;
    }
    files[j + 1] = key;
  }
}

// Selection Sort
void Sorter::selectionSort(
    std::vector<File>& files,
    const std::function<bool(const File&, const File&)>& comparator) {
  for (size_t i = 0; i < files.size() - 1; i++) {
    size_t minIndex = i;
    for (size_t j = i + 1; j < files.size(); j++) {
      if (comparator(files[j], files[minIndex])) {
        minIndex = j;
      }
    }
    std::swap(files[i], files[minIndex]);
  }
}
