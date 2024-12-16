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

// [Previous DynamicArray implementation remains the same]
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
// [Previous FileInfo class remains the same, but add a method to print details]
class FileInfo {
 public:
  // ... [previous implementations]
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
    auto timePoint =
        std::chrono::clock_cast<std::chrono::system_clock>(fi.lastModified);

    // Convert to time_t for easier printing
    std::time_t time = std::chrono::system_clock::to_time_t(timePoint);

    // Use std::localtime to convert to a readable format
    std::tm* timeInfo = std::localtime(&time);

    // Format the time
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);

    os << "Filename: " << fi.filename << ", Path: " << fi.path
       << ", Size: " << fi.size << " bytes"
       << ", Last Modified: " << buffer;

    return os;
  }

  void printDetails() const {
    std::cout << "Filename: " << filename << "\nPath: " << path
              << "\nSize: " << size << " bytes"
              << "\nLast Modified: ";

    // Convert file time to readable format
    auto timePoint =
        std::chrono::clock_cast<std::chrono::system_clock>(lastModified);
    std::time_t time = std::chrono::system_clock::to_time_t(timePoint);
    std::tm* timeInfo = std::localtime(&time);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
    std::cout << buffer << "\n\n";
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

// [QuickSort and MergeSort implementations remain the same]

// File Scanner Class
class FileScanner {
 public:
  static DynamicArray<FileInfo> scanDirectories(
      const std::string& rootPath = "") {
    DynamicArray<FileInfo> files;

    if (rootPath.empty()) {
      // Scan available drives
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
    if (depth > 5) return;

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

// Sorting and Display Utility
class SortingUtility {
 public:
  static void sortAndDisplayFiles(DynamicArray<FileInfo>& files) {
    // User sorting criteria selection
    int choice = getUserSortingChoice();

    // Select sorting algorithm
    int algorithmChoice = getAlgorithmChoice();

    // Create sorting strategies
    QuickSort quickSort;
    MergeSort mergeSort;
    SortStrategy* selectedAlgorithm =
        (algorithmChoice == 1) ? static_cast<SortStrategy*>(&quickSort)
                               : static_cast<SortStrategy*>(&mergeSort);

    // Select comparator based on user choice
    std::function<bool(const FileInfo&, const FileInfo&)> comparator;
    std::string criteriaName;

    switch (choice) {
      case 1:  // Sort by Name
        comparator = std::bind(&FileInfo::compareByName, std::placeholders::_1,
                               std::placeholders::_2);
        criteriaName = "Name";
        break;
      case 2:  // Sort by Size
        comparator = std::bind(&FileInfo::compareBySize, std::placeholders::_1,
                               std::placeholders::_2);
        criteriaName = "Size";
        break;
      case 3:  // Sort by Modified Date
        comparator = std::bind(&FileInfo::compareByModifiedDate,
                               std::placeholders::_1, std::placeholders::_2);
        criteriaName = "Modified Date";
        break;
      default:
        std::cout << "Invalid choice. Defaulting to Name sorting.\n";
        comparator = std::bind(&FileInfo::compareByName, std::placeholders::_1,
                               std::placeholders::_2);
        criteriaName = "Name";
    }

    // Measure and perform sorting
    auto start = std::chrono::high_resolution_clock::now();
    selectedAlgorithm->sort(files, comparator);
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate sorting time
    std::chrono::duration<double, std::milli> duration = end - start;

    // Display sorting results
    std::cout << "\n--- Sorting Results ---\n";
    std::cout << "Sorted by: " << criteriaName << "\n";
    std::cout << "Algorithm used: " << selectedAlgorithm->getName() << "\n";
    std::cout << "Sorting time: " << duration.count() << " milliseconds\n\n";

    // Prompt user for display options
    int displayChoice = getDisplayChoice();

    // Display files based on user choice
    switch (displayChoice) {
      case 1:  // Display filenames only
        displayFilenamesOnly(files);
        break;
      case 2:  // Display full details
        displayFullDetails(files);
        break;
      default:
        std::cout << "Invalid choice. No display selected.\n";
    }
  }

 private:
  static int getUserSortingChoice() {
    int choice;
    std::cout << "\n--- Select Sorting Criteria ---\n";
    std::cout << "1. Sort by Name\n";
    std::cout << "2. Sort by Size\n";
    std::cout << "3. Sort by Modified Date\n";
    std::cout << "Enter your choice (1-3): ";

    while (!(std::cin >> choice) || choice < 1 || choice > 3) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a number between 1 and 3: ";
    }
    return choice;
  }

  static int getAlgorithmChoice() {
    int choice;
    std::cout << "\n--- Select Sorting Algorithm ---\n";
    std::cout << "1. QuickSort\n";
    std::cout << "2. MergeSort\n";
    std::cout << "Enter your choice (1-2): ";

    while (!(std::cin >> choice) || choice < 1 || choice > 2) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter 1 or 2: ";
    }
    return choice;
  }

  static int getDisplayChoice() {
    int choice;
    std::cout << "\n--- Select Display Option ---\n";
    std::cout << "1. Display Filenames Only\n";
    std::cout << "2. Display Full File Details\n";
    std::cout << "Enter your choice (1-2): ";

    while (!(std::cin >> choice) || choice < 1 || choice > 2) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter 1 or 2: ";
    }
    return choice;
  }

  static void displayFilenamesOnly(const DynamicArray<FileInfo>& files) {
    std::cout << "\n--- Sorted Filenames ---\n";
    for (size_t i = 0; i < files.getSize(); ++i) {
      std::cout << files[i].filename << "\n";
    }
    std::cout << "\nTotal files: " << files.getSize() << std::endl;
  }

  static void displayFullDetails(const DynamicArray<FileInfo>& files) {
    std::cout << "\n--- Sorted File Details ---\n";
    for (size_t i = 0; i < files.getSize(); ++i) {
      std::cout << "File " << (i + 1) << ":\n";
      files[i].printDetails();
    }
    std::cout << "Total files: " << files.getSize() << std::endl;
  }
};

// Main Application Class
void run(const std::string& path = "") {
  std::cout << "File Management and Sorting Application\n";

  // Scan files from specified path or all drives
  DynamicArray<FileInfo> files = FileScanner::scanDirectories(path);

  // Check if any files were found
  if (files.getSize() == 0) {
    std::cout << "No files found. Exiting.\n";
    return;
  }

  // Display total number of files found
  std::cout << "Total files scanned: " << files.getSize() << std::endl;

  // Enter main application loop
  while (true) {
    std::cout << "\n--- Main Menu ---\n";
    std::cout << "1. Sort and Display Files\n";
    std::cout << "2. Rescan Directories\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice (1-3): ";

    int menuChoice;
    while (!(std::cin >> menuChoice) || menuChoice < 1 || menuChoice > 3) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a number between 1 and 3: ";
    }

    switch (menuChoice) {
      case 1:
        // Sort and display files
        SortingUtility::sortAndDisplayFiles(files);
        break;
      case 2:
        // Rescan directories
        files.clear();
        files = FileScanner::scanDirectories(path);
        if (files.getSize() == 0) {
          std::cout << "No files found during rescan.\n";
        } else {
          std::cout << "Rescanned. Total files: " << files.getSize()
                    << std::endl;
        }
        break;
      case 3:
        // Exit the application
        std::cout << "Exiting File Management Application. Goodbye!\n";
        return;
    }
  }
}

int main() {
  FileManagementApp app;

  // Option 1: Scan all drives
  app.run();

  // Option 2: Scan a specific directory (uncomment and modify path)
  // app.run("C:/Users/YourUsername/Documents");

  return 0;
}

#endif  // FILE_INFO_H