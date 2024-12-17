#ifndef FILE_MANAGEMENT_APP_H
#define FILE_MANAGEMENT_APP_H
using namespace std;

#include "dynamic_array.h"
#include "file_info.h"
#include "file_scanner.h"
#include "sort_performance_tracker.h"
#include "sort_strategy.h"
#include "sorting_algorithms.h"
class FileManagementApp {
 private:
  SortStrategy* getSortAlgorithm() {
    cout << "\nSelect Sorting Algorithm:\n";
    cout << "1. QuickSort\n";
    cout << "2. MergeSort\n";
    cout << "3. Selection Sort\n";
    cout << "4. Bubble Sort\n";
    cout << "5. Insertion Sort\n";
    cout << "Enter your choice (1-5): ";

    int choice;
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Selected: QuickSort\n";
        return new QuickSort();
      case 2:
        cout << "Selected: MergeSort\n";
        return new MergeSort();
      case 3:
        cout << "Selected: Selection Sort\n";
        return new SelectionSort();
      case 4:
        cout << "Selected: Bubble Sort\n";
        return new BubbleSort();
      case 5:
        cout << "Selected: Insertion Sort\n";
        return new InsertionSort();
      default:
        cout << "Invalid choice. Defaulting to QuickSort.\n";
        return new QuickSort();
    }
  }

 public:
  void run(const string& path = "") {
    cout << "File Management and Sorting Application\n";

    // Scan files from specified path or all drives
    DynamicArray<FileInfo> files = FileScanner::scanDirectories(path);

    // Generate and display sorting performance report
    SortPerformanceTracker::generateSortReport(files);
  }
};

#endif