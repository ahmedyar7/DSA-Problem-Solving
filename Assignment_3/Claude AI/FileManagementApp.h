// #include <algorithm>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "BubbleSort.h"
#include "DynamicArray.h"
#include "FileInfo.h"
#include "FileScanner.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "SortPerformanceTracker.h"
#include "SortingStrategy.h"
// Main Application Class
class FileManagementApp {
 private:
  SortStrategy* getSortAlgorithm() {
    std::cout << "\nSelect Sorting Algorithm:\n";
    std::cout << "1. QuickSort\n";
    std::cout << "2. MergeSort\n";
    std::cout << "3. Selection Sort\n";
    std::cout << "4. Bubble Sort\n";
    std::cout << "5. Insertion Sort\n";
    std::cout << "Enter your choice (1-5): ";

    int choice;
    std::cin >> choice;

    switch (choice) {
      case 1:
        std::cout << "Selected: QuickSort\n";
        return new QuickSort();
      case 2:
        std::cout << "Selected: MergeSort\n";
        return new MergeSort();
      case 3:
        std::cout << "Selected: Selection Sort\n";
        return new SelectionSort();
      case 4:
        std::cout << "Selected: Bubble Sort\n";
        return new BubbleSort();
      case 5:
        std::cout << "Selected: Insertion Sort\n";
        return new InsertionSort();
      default:
        std::cout << "Invalid choice. Defaulting to QuickSort.\n";
        return new QuickSort();
    }
  }

 public:
  void run(const std::string& path = "") {
    std::cout << "File Management and Sorting Application\n";

    // Scan files from specified path or all drives
    DynamicArray<FileInfo> files = FileScanner::scanDirectories(path);

    // Generate and display sorting performance report
    SortPerformanceTracker::generateSortReport(files);
  }
};
