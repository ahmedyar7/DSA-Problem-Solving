#ifndef SORT_PERFORMANCE_TRACKER_H
#define SORT_PERFORMANCE_TRACKER_H

#include <chrono>
#include <functional>
#include <iomanip>
#include <sstream>
#include <vector>

#include "dynamic_array.h"
#include "file_info.h"
#include "sort_strategy.h"
#include "sorting_algorithms.h"
using namespace std;

class SortPerformanceTracker {
 private:
  // Helper function to create a formatted table row
  static string createTableRow(const vector<string>& columns, int width = 20) {
    stringstream row;
    row << "| ";
    for (const auto& col : columns) {
      row << setw(width) << left << col << " | ";
    }
    row << endl;
    return row.str();
  }

  // Helper function to create a table separator
  static string createTableSeparator(int columnCount, int width = 20) {
    stringstream separator;
    separator << "+";
    for (int i = 0; i < columnCount; ++i) {
      separator << string(width + 2, '-') << "+";
    }
    separator << endl;
    return separator.str();
  }

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
    // Create output stream for beautiful formatting
    stringstream report;

    // Report Header
    report << string(80, '=') << endl;
    report << setw(40) << right << "COMPREHENSIVE SORTING PERFORMANCE REPORT"
           << endl;
    report << string(80, '=') << endl;

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

    // List of sorting algorithms
    vector<SortStrategy*> sortAlgorithms = {
        &quickSort, &mergeSort, &selectionSort, &bubbleSort, &insertionSort};

    // Report key statistics
    report << "\nTotal Files Scanned: " << files.getSize() << endl;
    report << "Sorting Algorithms: " << sortAlgorithms.size() << endl;
    report << "Sorting Criteria: " << sortCriteria.size() << endl;
    report << string(80, '-') << endl;

    // Measure and report sorting times for each criteria
    for (const auto& criteria : sortCriteria) {
      // Table Header
      report << "\nPerformance Report: Sorting by " << criteria.first << endl;
      report << createTableSeparator(4);
      report << createTableRow(
          {"Algorithm", "Time (ms)", "Speed Rank", "Complexity"});
      report << createTableSeparator(4);

      // Temporary storage for sorting times
      vector<pair<string, double>> performanceResults;

      // Measure performance for each sorting algorithm
      for (auto algorithm : sortAlgorithms) {
        double sortTime = measureSortTime(algorithm, files, criteria.second);
        performanceResults.push_back({algorithm->getName(), sortTime});
      }

      // Sort performance results by time
      sort(performanceResults.begin(), performanceResults.end(),
           [](const auto& a, const auto& b) { return a.second < b.second; });

      // Generate ranking and report
      for (size_t rank = 0; rank < performanceResults.size(); ++rank) {
        string speedRank;
        string complexity;

        // Assign speed rank and complexity based on position
        switch (rank) {
          case 0:
            speedRank = "Fastest";
            complexity = "O(n log n)";
            break;
          case 1:
            speedRank = "Fast";
            complexity = "O(n log n)";
            break;
          case 2:
            speedRank = "Average";
            complexity = "O(n^2)";
            break;
          case 3:
            speedRank = "Slow";
            complexity = "O(n^2)";
            break;
          default:
            speedRank = "Slowest";
            complexity = "O(n^2)";
            break;
        }

        report << createTableRow({performanceResults[rank].first,
                                  to_string(performanceResults[rank].second),
                                  speedRank, complexity});
      }
      report << createTableSeparator(4);
    }

    // Final report footer
    report << string(80, '=') << endl;
    report << setw(40) << right << "END OF PERFORMANCE REPORT" << endl;
    report << string(80, '=') << endl;

    // Output the report
    cout << report.str();
  }
};

#endif  // SORT_PERFORMANCE_TRACKER_H