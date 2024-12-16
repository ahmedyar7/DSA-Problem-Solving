#ifndef FILE_INFO_H
#define FILE_INFO_H

#include <algorithm>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

// Custom Dynamic Array (Similar to vector but manually implemented)
template <typename T>
class DynamicArray {
 private:
  T* array;
  size_t capacity;
  size_t size;

  void resize(size_t newCapacity) {
    T* newArray = new T[newCapacity];
    for (size_t i = 0; i < size; ++i) {
      newArray[i] = std::move(array[i]);
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
  }

 public:
  DynamicArray() : array(new T[1]), capacity(1), size(0) {}

  ~DynamicArray() { delete[] array; }

  void push_back(const T& element) {
    if (size == capacity) {
      resize(capacity * 2);
    }
    array[size++] = element;
  }

  T& operator[](size_t index) {
    if (index >= size) {
      throw std::out_of_range("Index out of range");
    }
    return array[index];
  }

  size_t getSize() const { return size; }

  void clear() {
    delete[] array;
    array = new T[1];
    capacity = 1;
    size = 0;
  }
};

// Enhanced File Information Class
class FileInfo {
 public:
  std::string filename;
  std::string path;
  uintmax_t size;
  std::filesystem::file_time_type lastModified;

  FileInfo() : size(0) {}

  // Comparison operators for different sorting criteria
  bool compareByName(const FileInfo& other) const {
    return filename < other.filename;
  }

  bool compareBySize(const FileInfo& other) const { return size < other.size; }

  bool compareByModifiedDate(const FileInfo& other) const {
    return lastModified < other.lastModified;
  }

  friend std::ostream& operator<<(std::ostream& os, const FileInfo& fi) {
    // Convert file_time_type to system_clock time_point
    // auto timePoint =
    // std::chrono::clock_cast<std::chrono::system_clock>(fi.lastModified);

    // Convert to time_t for easier printing
    // std::time_t time = std::chrono::system_clock::to_time_t(timePoint);

    // Use std::localtime to convert to a readable format
    // std::tm* timeInfo = std::localtime(&time);

    // Format the time
    char buffer[80];
    // std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);

    os << "Filename: " << fi.filename << ", Path: " << fi.path
       << ", Size: " << fi.size << " bytes"
       << ", Last Modified: " << buffer;

    return os;
  }
};

// Sorting Strategy Interface
class SortStrategy {
 public:
  virtual void sort(
      DynamicArray<FileInfo>& files,
      std::function<bool(const FileInfo&, const FileInfo&)> comparator) = 0;
  virtual std::string getName() const = 0;
  virtual ~SortStrategy() {}
};

// QuickSort Implementation
class QuickSort : public SortStrategy {
 public:
  void sort(DynamicArray<FileInfo>& files,
            std::function<bool(const FileInfo&, const FileInfo&)> comparator)
      override {
    quickSortHelper(files, 0, files.getSize() - 1, comparator);
  }

  std::string getName() const override { return "QuickSort"; }

 private:
  int partition(
      DynamicArray<FileInfo>& files, int low, int high,
      std::function<bool(const FileInfo&, const FileInfo&)> comparator) {
    FileInfo pivot = files[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
      if (comparator(files[j], pivot)) {
        ++i;
        std::swap(files[i], files[j]);
      }
    }
    std::swap(files[i + 1], files[high]);
    return i + 1;
  }

  void quickSortHelper(
      DynamicArray<FileInfo>& files, int low, int high,
      std::function<bool(const FileInfo&, const FileInfo&)> comparator) {
    if (low < high) {
      int pivotIndex = partition(files, low, high, comparator);
      quickSortHelper(files, low, pivotIndex - 1, comparator);
      quickSortHelper(files, pivotIndex + 1, high, comparator);
    }
  }
};

// MergeSort Implementation
class MergeSort : public SortStrategy {
 public:
  void sort(DynamicArray<FileInfo>& files,
            std::function<bool(const FileInfo&, const FileInfo&)> comparator)
      override {
    mergeSortHelper(files, 0, files.getSize() - 1, comparator);
  }

  std::string getName() const override { return "MergeSort"; }

 private:
  void merge(DynamicArray<FileInfo>& files, int left, int mid, int right,
             std::function<bool(const FileInfo&, const FileInfo&)> comparator) {
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
      std::function<bool(const FileInfo&, const FileInfo&)> comparator) {
    if (left < right) {
      int mid = left + (right - left) / 2;
      mergeSortHelper(files, left, mid, comparator);
      mergeSortHelper(files, mid + 1, right, comparator);
      merge(files, left, mid, right, comparator);
    }
  }
};

// File Scanner Class
class FileScanner {
 public:
  static DynamicArray<FileInfo> scanDirectories(
      const std::string& rootPath = "") {
    DynamicArray<FileInfo> files;

    // If no root path provided, scan all drives
    if (rootPath.empty()) {
      // Scan available drives (Windows-style, modify for cross-platform)
      for (char drive = 'C'; drive <= 'Z'; ++drive) {
        std::filesystem::path drivePath = std::string(1, drive) + ":/";

        if (std::filesystem::exists(drivePath)) {
          try {
            scanDirectory(drivePath, files);
          } catch (const std::exception& e) {
            std::cerr << "Error scanning drive " << drivePath << ": "
                      << e.what() << std::endl;
          }
        }
      }
    } else {
      // Scan specific directory
      std::filesystem::path directoryPath(rootPath);
      if (std::filesystem::exists(directoryPath)) {
        try {
          scanDirectory(directoryPath, files);
        } catch (const std::exception& e) {
          std::cerr << "Error scanning directory " << rootPath << ": "
                    << e.what() << std::endl;
        }
      }
    }

    return files;
  }

 private:
  static void scanDirectory(const std::filesystem::path& directory,
                            DynamicArray<FileInfo>& files, int depth = 0) {
    // Limit recursion depth to prevent excessive scanning
    if (depth > 5)
      return;  // Increased from 3 to 5 for more comprehensive scanning

    try {
      for (const auto& entry :
           std::filesystem::recursive_directory_iterator(directory)) {
        if (std::filesystem::is_regular_file(entry)) {
          FileInfo fileInfo;
          fileInfo.filename = entry.path().filename().string();
          fileInfo.path = entry.path().string();

          try {
            fileInfo.size = std::filesystem::file_size(entry);
            fileInfo.lastModified = std::filesystem::last_write_time(entry);
            files.push_back(fileInfo);
          } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error getting file info: " << e.what() << std::endl;
          }
        }
      }
    } catch (const std::exception& e) {
      std::cerr << "Error scanning directory " << directory << ": " << e.what()
                << std::endl;
    }
  }
};

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

    // Measure and report sorting times for each criteria
    for (const auto& criteria : sortCriteria) {
      std::cout << "\n--- Sorting by " << criteria.first << " ---\n";

      // Measure QuickSort
      double quickSortTime =
          measureSortTime(&quickSort, files, criteria.second);
      std::cout << "QuickSort Performance:\n";
      std::cout << "Time taken: " << quickSortTime << " milliseconds\n";

      // Measure MergeSort
      double mergeSortTime =
          measureSortTime(&mergeSort, files, criteria.second);
      std::cout << "MergeSort Performance:\n";
      std::cout << "Time taken: " << mergeSortTime << " milliseconds\n";
    }
  }
};

// Main Application Class
class FileManagementApp {
 public:
  void run(const std::string& path = "") {
    std::cout << "File Management and Sorting Application\n";

    // Scan files from specified path or all drives
    DynamicArray<FileInfo> files = FileScanner::scanDirectories(path);

    // Generate and display sorting performance report
    SortPerformanceTracker::generateSortReport(files);
  }
};

int main() {
  FileManagementApp app;

  // Option 1: Scan all drives
  // app.run();

  // Option 2: Scan a specific directory (uncomment and modify path)
  app.run("C:/Users/MULTITECH/Documents");

  return 0;
}

#endif  // FILE_INFO_H