#ifndef SORTER_H
#define SORTER_H

#include <functional>  // For passing comparator functions
#include <vector>

#include "File.h"

class Sorter {
 public:
  // Sorting algorithms
  static void quickSort(
      std::vector<File>& files, int low, int high,
      const std::function<bool(const File&, const File&)>& comparator);

  static void mergeSort(
      std::vector<File>& files, int left, int right,
      const std::function<bool(const File&, const File&)>& comparator);

  static void insertionSort(
      std::vector<File>& files,
      const std::function<bool(const File&, const File&)>& comparator);

  static void selectionSort(
      std::vector<File>& files,
      const std::function<bool(const File&, const File&)>& comparator);
};

#endif
