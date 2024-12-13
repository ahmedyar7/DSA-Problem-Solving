#ifndef SORTING_H
#define SORTING_H

#include <iostream>

#include "file.h"
using namespace std;

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
}

// Selection sort Implemetation
void selection_sort(File* files, int size, int (*compare)(File&, File&)) {
  for (int i = 0; i < size - 1; i++) {
    int mini = i;
    for (int j = i + 1; j < size; i++) {
      if (compare(files[j], files[mini]) < 0) mini = j;
    }
    // Swapping
    File temp = files[mini];
    files[mini] = files[i];
    files[i] = temp;
  }
}

// Merge sort implementation

// Quick sort implementation

#endif  // SORTING_H
