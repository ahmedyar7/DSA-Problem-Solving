#include "BubbleSort.h"
#include "DynamicArray.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "SortingStrategy.h"
// Sorting Performance Tracker
class SortPerformanceTracker {
 public:
  static double measureSortTime(
      SortStrategy* strategy, DynamicArray<FileInfo>& files,
      std::function<bool(const FileInfo&, const FileInfo&)> comparator) {
    // Create a copy of files to ensure fair comparison
    DynamicArray<FileInfo> filesCopy;
    for (size_t i = 0; i < files.getSize(); ++i) {
      filesCopy.push_back(files[i]);
    }

    auto start = std::chrono::high_resolution_clock::now();
    strategy->sort(filesCopy, comparator);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
  }

  static void generateSortReport(DynamicArray<FileInfo>& files) {
    std::cout << "\n--- COMPREHENSIVE SORTING PERFORMANCE REPORT ---\n";

    // Create sorting strategies
    QuickSort quickSort;
    MergeSort mergeSort;
    SelectionSort selectionSort;
    BubbleSort bubbleSort;
    InsertionSort insertionSort;

    // Define sorting criteria
    std::vector<std::pair<
        std::string, std::function<bool(const FileInfo&, const FileInfo&)>>>
        sortCriteria = {
            {"Name", std::bind(&FileInfo::compareByName, std::placeholders::_1,
                               std::placeholders::_2)},
            {"Size", std::bind(&FileInfo::compareBySize, std::placeholders::_1,
                               std::placeholders::_2)},
            {"Modified Date",
             std::bind(&FileInfo::compareByModifiedDate, std::placeholders::_1,
                       std::placeholders::_2)}};

    std::cout << "Total Files Scanned: " << files.getSize() << std::endl;

    // List of sorting algorithms
    std::vector<SortStrategy*> sortAlgorithms = {
        &quickSort, &mergeSort, &selectionSort, &bubbleSort, &insertionSort};

    // Measure and report sorting times for each criteria
    for (const auto& criteria : sortCriteria) {
      std::cout << "\n--- Sorting by " << criteria.first << " ---\n";

      // Measure performance for each sorting algorithm
      for (auto algorithm : sortAlgorithms) {
        double sortTime = measureSortTime(algorithm, files, criteria.second);
        std::cout << algorithm->getName() << " Performance:\n";
        std::cout << "Time taken: " << sortTime << " milliseconds\n";
      }
    }
  }
};
