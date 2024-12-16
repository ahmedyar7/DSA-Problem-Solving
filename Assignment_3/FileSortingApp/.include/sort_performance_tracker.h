#ifndef SORT_PERFORMANCE_TRACKER_H
#define SORT_PERFORMANCE_TRACKER_H

#include <chrono>
#include <functional>
#include <vector>

#include "dynamic_array.h"
#include "file_info.h"
#include "sort_strategy.h"
#include "sorting_algorithms.h"
using namespace std;

class SortPerformanceTracker {
 public:
  static double measureSortTime(
      SortStrategy* strategy, DynamicArray<FileInfo>& files,
      function<bool(const FileInfo&, const FileInfo&)> comparator) {
    // Create a copy of files to ensure fair comparison
    DynamicArray<FileInfo> filesCopy;
    for (size_t i = 0; i < files.getSize(); ++i) {
      filesCopy.push_back(files[i]);
    }

    auto start = chrono::high_resolution_clock::now();
    strategy->sort(filesCopy, comparator);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = end - start;
    return duration.count();
  }

  static void generateSortReport(DynamicArray<FileInfo>& files) {
    cout << "\n--- COMPREHENSIVE SORTING PERFORMANCE REPORT ---\n";

    // Create sorting strategies
    QuickSort quickSort;
    MergeSort mergeSort;
    SelectionSort selectionSort;
    BubbleSort bubbleSort;
    InsertionSort insertionSort;

    // Define sorting criteria
    vector<pair<string, function<bool(const FileInfo&, const FileInfo&)>>>
        sortCriteria = {
            {"Name", bind(&FileInfo::compareByName, placeholders::_1,
                          placeholders::_2)},
            {"Size", bind(&FileInfo::compareBySize, placeholders::_1,
                          placeholders::_2)},
            {"Modified Date", bind(&FileInfo::compareByModifiedDate,
                                   placeholders::_1, placeholders::_2)}};

    cout << "Total Files Scanned: " << files.getSize() << endl;

    // List of sorting algorithms
    vector<SortStrategy*> sortAlgorithms = {
        &quickSort, &mergeSort, &selectionSort, &bubbleSort, &insertionSort};

    // Measure and report sorting times for each criteria
    for (const auto& criteria : sortCriteria) {
      cout << "\n--- Sorting by " << criteria.first << " ---\n";

      // Measure performance for each sorting algorithm
      for (auto algorithm : sortAlgorithms) {
        double sortTime = measureSortTime(algorithm, files, criteria.second);
        cout << algorithm->getName() << " Performance:\n";
        cout << "Time taken: " << sortTime << " milliseconds\n";
      }
    }
  }
};
#endif  // SORT_PERFORMANCE_TRACKER_H