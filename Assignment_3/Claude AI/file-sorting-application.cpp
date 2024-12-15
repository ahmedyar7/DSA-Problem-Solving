#ifndef FILE_INFO_H
#define FILE_INFO_H

#include <algorithm>
#include <chrono>
#include <filesystem>
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
};

// File Information Class
class FileInfo {
 public:
  std::string filename;
  std::string path;
  uintmax_t size;
  std::filesystem::file_time_type lastModified;

  FileInfo() : size(0) {}

  // Comparison operators for sorting
  bool operator<(const FileInfo& other) const {
    return filename < other.filename;
  }

  friend std::ostream& operator<<(std::ostream& os, const FileInfo& fi) {
    os << "Filename: " << fi.filename << ", Path: " << fi.path
       << ", Size: " << fi.size << " bytes";
    return os;
  }
};

// Sorting Strategy Interface
class SortStrategy {
 public:
  virtual void sort(DynamicArray<FileInfo>& files) = 0;
  virtual std::string getName() const = 0;
  virtual ~SortStrategy() {}
};

// Concrete Sorting Strategies
class QuickSort : public SortStrategy {
 public:
  void sort(DynamicArray<FileInfo>& files) override {
    quickSortHelper(files, 0, files.getSize() - 1);
  }

  std::string getName() const override { return "QuickSort"; }

 private:
  int partition(DynamicArray<FileInfo>& files, int low, int high) {
    FileInfo pivot = files[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
      if (files[j].filename < pivot.filename) {
        ++i;
        std::swap(files[i], files[j]);
      }
    }
    std::swap(files[i + 1], files[high]);
    return i + 1;
  }

  void quickSortHelper(DynamicArray<FileInfo>& files, int low, int high) {
    if (low < high) {
      int pivotIndex = partition(files, low, high);
      quickSortHelper(files, low, pivotIndex - 1);
      quickSortHelper(files, pivotIndex + 1, high);
    }
  }
};

class MergeSort : public SortStrategy {
 public:
  void sort(DynamicArray<FileInfo>& files) override {
    mergeSortHelper(files, 0, files.getSize() - 1);
  }

  std::string getName() const override { return "MergeSort"; }

 private:
  void merge(DynamicArray<FileInfo>& files, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    DynamicArray<FileInfo> leftArray;
    DynamicArray<FileInfo> rightArray;

    for (int i = 0; i < n1; ++i) leftArray.push_back(files[left + i]);
    for (int j = 0; j < n2; ++j) rightArray.push_back(files[mid + 1 + j]);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
      if (leftArray[i].filename <= rightArray[j].filename)
        files[k++] = leftArray[i++];
      else
        files[k++] = rightArray[j++];
    }

    while (i < n1) files[k++] = leftArray[i++];
    while (j < n2) files[k++] = rightArray[j++];
  }

  void mergeSortHelper(DynamicArray<FileInfo>& files, int left, int right) {
    if (left < right) {
      int mid = left + (right - left) / 2;
      mergeSortHelper(files, left, mid);
      mergeSortHelper(files, mid + 1, right);
      merge(files, left, mid, right);
    }
  }
};

// File Scanner Class
class FileScanner {
 public:
  static DynamicArray<FileInfo> scanDrives() {
    DynamicArray<FileInfo> files;

    // Scan available drives (Windows-style, modify for cross-platform)
    for (char drive = 'C'; drive <= 'Z'; ++drive) {
      std::filesystem::path drivePath = std::string(1, drive) + ":/";

      if (std::filesystem::exists(drivePath)) {
        try {
          scanDirectory(drivePath, files);
        } catch (const std::exception& e) {
          std::cerr << "Error scanning drive " << drivePath << ": " << e.what()
                    << std::endl;
        }
      }
    }

    return files;
  }

 private:
  static void scanDirectory(const std::filesystem::path& directory,
                            DynamicArray<FileInfo>& files, int depth = 0) {
    // Limit recursion depth to prevent excessive scanning
    if (depth > 3) return;

    try {
      for (const auto& entry :
           std::filesystem::recursive_directory_iterator(directory)) {
        if (std::filesystem::is_regular_file(entry)) {
          FileInfo fileInfo;
          fileInfo.filename = entry.path().filename().string();
          fileInfo.path = entry.path().string();
          fileInfo.size = std::filesystem::file_size(entry);
          fileInfo.lastModified = std::filesystem::last_write_time(entry);

          files.push_back(fileInfo);
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
  static double measureSortTime(SortStrategy* strategy,
                                DynamicArray<FileInfo>& files) {
    auto start = std::chrono::high_resolution_clock::now();
    strategy->sort(files);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
  }

  static void generateSortReport(DynamicArray<FileInfo>& files) {
    std::cout << "\n--- SORTING PERFORMANCE REPORT ---\n";

    // Create sorting strategies
    QuickSort quickSort;
    MergeSort mergeSort;

    // Clone original files for each sort to ensure fair comparison
    DynamicArray<FileInfo> quickSortFiles, mergeSortFiles;
    for (size_t i = 0; i < files.getSize(); ++i) {
      quickSortFiles.push_back(files[i]);
      mergeSortFiles.push_back(files[i]);
    }

    // Measure and report sorting times
    double quickSortTime = measureSortTime(&quickSort, quickSortFiles);
    double mergeSortTime = measureSortTime(&mergeSort, mergeSortFiles);

    std::cout << "Total Files Scanned: " << files.getSize() << std::endl;
    std::cout << "\nQuickSort Performance:\n";
    std::cout << "Time taken: " << quickSortTime << " milliseconds\n";

    std::cout << "\nMergeSort Performance:\n";
    std::cout << "Time taken: " << mergeSortTime << " milliseconds\n";
  }
};

// Main Application Class
class FileManagementApp {
 public:
  void run() {
    std::cout << "File Management and Sorting Application\n";

    // Scan files from drives
    DynamicArray<FileInfo> files = FileScanner::scanDrives();

    // Generate and display sorting performance report
    SortPerformanceTracker::generateSortReport(files);
  }
};

int main() {
  FileManagementApp app;
  app.run();
  return 0;
}

#endif  // FILE_INFO_H
