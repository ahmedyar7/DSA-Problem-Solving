#ifndef SORTING_H
#define SORTING_H

#include <iostream>

#include "file.h"
using namespace std;

class Sorting {
 private:
  int compare_string(const char* string1, const char* string2) const {
    int i = 0;
    while (string1[i] != '\0' && string2[i] != '\0') {
      if (string1[i] != string2[i]) {
        return string1[i] - string2[i];
      }
      i++;
    }
    return string1[i] - string2[i];
  }
  // Helper function Quick Sort
  int partition(File* files, int left, int right,
                int (*compare)(File&, File&)) {
    File pivot = files[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
      if (compare(files[j], pivot) <= 0) {
        i++;
        swap(files[i], files[j]);
      }
    }
    swap(files[i + 1], files[right]);

    return i + 1;
  }

  // Helper function for merge sort
  void merge(File* files, int left, int mid, int right,
             int (*compare)(File&, File&)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary array for merging
    File* left_arr = new File[n1];
    File* right_arr = new File[n2];

    // Copying data into temporary array
    for (int i = 0; i < n1; i++) left_arr[i] = files[left + i];
    for (int i = 0; i < n2; i++) right_arr[i] = files[mid + 1 + i];

    // Merging back to original arrays
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
      if (compare(left_arr[i], right_arr[j]) <= 0)
        files[k++] = left_arr[i++];
      else
        files[k++] = right_arr[j++];
    }

    // Copying the remaining element back to arrays
    while (i < n1) files[k++] = left_arr[i++];
    while (j < n2) files[k++] = right_arr[j++];

    // Deallocating memory
    delete[] left_arr;
    delete[] right_arr;

    return;
  }

 public:
  // Quick Sort Implementation
  void quick_sort(File* files, int left, int right,
                  int (*compare)(File&, File&)) {
    if (left < right) {
      int partition_index = partition(files, left, right, compare);

      // Recursively sorting element on both sides
      quick_sort(files, left, partition_index - 1, compare);
      quick_sort(files, partition_index + 1, right, compare);
    }

    return;
  }

  // Merge Sort Implementation
  void merge_sort(File* files, int left, int right,
                  int (*compare)(File&, File&)) {
    if (left < right) {
      int mid = left + (right - left) / 2;

      // Recursivly divide the array
      merge_sort(files, left, mid, compare);
      merge_sort(files, mid + 1, right, compare);

      // Merge sorted half
      merge(files, left, mid, right, compare);
    }

    return;
  }

  // Insertion sort implementation
  void insertion_sort(File* files, int size, int (*compare)(File&, File&)) {
    for (int i = 1; i < size; i++) {
      File key = files[i];
      int j = i - 1;
      while (j >= 0 && compare(files[j], key) > 0) {
        files[j + 1] = files[j];
        j--;
      }
      files[j + 1] = key;
    }

    return;
  }

  // Selection sort Implemetation
  void selection_sort(File* files, int size, int (*compare)(File&, File&)) {
    for (int i = 0; i < size - 1; i++) {
      int mini = i;
      for (int j = i + 1; j < size; j++) {
        if (compare(files[j], files[mini]) < 0) mini = j;
      }
      // Swapping
      File temp = files[mini];
      files[mini] = files[i];
      files[i] = temp;
    }
    return;
  }

  // Comparision by different parameters

  // Compare by Name
  int compare_by_name(File& f1, File& f2) {
    return compare_string(f1.get_file_name(), f2.get_file_name());
  }

  // Compare by Date
  int compare_by_date(File& f1, File& f2) {
    return compare_string(f1.get_file_date(), f2.get_file_date());
  }
  // Ascending order
  int compare_by_size(File& f1, File& f2) {
    if (f1.get_file_size() < f2.get_file_size()) return -1;  // f1 small
    if (f1.get_file_size() > f2.get_file_size()) return 1;   // f1 large
    return 0;                                                // both equal
  }
};

#endif  // SORTING_H
