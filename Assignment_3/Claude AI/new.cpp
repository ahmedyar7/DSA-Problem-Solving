#include <algorithm>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

// Enhanced FileInfo struct with human-readable size formatting
struct FileInfo {
  std::string path;
  std::string name;
  std::uintmax_t size;
  std::filesystem::file_time_type lastModified;

  // Constructors and utility methods
  FileInfo() : size(0) {}
  FileInfo(const std::filesystem::path& p)
      : path(p.string()),
        name(p.filename().string()),
        size(std::filesystem::file_size(p)),
        lastModified(std::filesystem::last_write_time(p)) {}

  // Function to convert bytes to a human-readable size string
  std::string getHumanReadableSize() const {
    const double kibiByte = 1024.0;
    const double megaByte = kibiByte * 1024.0;
    const double gigaByte = megaByte * 1024.0;
    const double teraByte = gigaByte * 1024.0;

    double value = static_cast<double>(size);
    const char* units[] = {"B", "KiB", "MiB", "GiB", "TiB"};
    int i = 0;
    while (value > teraByte && i < (sizeof(units) / sizeof(units[0])) - 1) {
      value /= teraByte;
      ++i;
    }
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << value;
    return ss.str() + ' ' + units[i];
  }
};

class FileScanner {
 private:
  std::vector<FileInfo> files;

 public:
  // Scan directories recursively with error handling
  void scanDirectory(const std::string& rootPath) {
    try {
      for (const auto& entry :
           std::filesystem::recursive_directory_iterator(rootPath)) {
        if (std::filesystem::is_regular_file(entry)) {
          files.emplace_back(entry.path());
        }
      }
    } catch (const std::filesystem::filesystem_error& e) {
      std::cerr << "Error scanning directory: " << e.what() << std::endl;
      //   std::cerr << "Failed to process: " << entry.path()
      //   << std::endl;  // Log the problematic path
    } catch (const std::exception& e) {
      std::cerr << "Unexpected error: " << e.what() << std::endl;
    }
  }

  // Sorting methods with performance tracking
  void sortByName() {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(
        files.begin(), files.end(),
        [](const FileInfo& a, const FileInfo& b) { return a.name < b.name; });
    reportSortPerformance("Name", start);
  }

  void sortBySize() {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(
        files.begin(), files.end(),
        [](const FileInfo& a, const FileInfo& b) { return a.size < b.size; });
    reportSortPerformance("Size", start);
  }

  void sortByDate() {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(files.begin(), files.end(),
              [](const FileInfo& a, const FileInfo& b) {
                return a.lastModified < b.lastModified;
              });
    reportSortPerformance("Date", start);
  }

  // Performance reporting with improved formatting
  void reportSortPerformance(
      const std::string& sortType,
      const std::chrono::high_resolution_clock::time_point& start) {
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now() - start);
    std::cout << "\n--- " << sortType << " Sort Performance ---" << std::endl;
    std::cout << "Time taken: " << duration.count() << " microseconds"
              << std::endl;
    std::cout << "Total files sorted: " << files.size() << std::endl;
  }

  // Display top N files with enhanced formatting
  void displayFiles(int count = 10) {
    std::cout << "\n--- File Details ---" << std::endl;
    std::cout << std::left << std::setw(50) << "File Name" << std::setw(15)
              << "Size" << std::setw(20) << "Last Modified" << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    count = std::min(count, static_cast<int>(files.size()));
    for (int i = 0; i < count; ++i) {
      auto file_time = std::chrono::time_point_cast<std::chrono::milliseconds>(
          files[i].lastModified);
      auto duration = file_time.time_since_epoch();
      auto time_t_value =
          std::chrono::duration_cast<std::chrono::seconds>(duration).count();

      std::cout << std::left << std::setw(50) << files[i].name << std::setw(15)
                << files[i].getHumanReadableSize() << std::ctime(&time_t_value)
                << std::endl;
    }
  }

  // Interactive menu
  void menu() {
    while (true) {
      std::cout << "\n--- File Sorting Menu ---" << std::endl;
      std::cout << "1. Sort by Name" << std::endl;
      std::cout << "2. Sort by Size" << std::endl;
      std::cout << "3. Sort by Date" << std::endl;
      std::cout << "4. Display Sorted Files" << std::endl;
      std::cout << "5. Exit" << std::endl;

      int choice;
      std::cout << "Enter your choice: ";
      while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number: ";
      }

      switch (choice) {
        case 1:
          sortByName();
          break;
        case 2:
          sortBySize();
          break;
        case 3:
          sortByDate();
          break;
        case 4:
          displayFiles();
          break;
        case 5:
          return;
        default:
          std::cout << "Invalid choice. Try again." << std::endl;
      }
    }
  }
};

int main() {
  FileScanner scanner;

  // Scan multiple directories (modify as needed)
  std::vector<std::string> directories = {
      "C:\\Users\\MULTITECH\\Desktop\\DSA",  // Windows example
                                             // Add more directories as needed
  };

  std::cout << "Scanning directories..." << std::endl;
  for (const auto& dir : directories) {
    try {
      scanner.scanDirectory(dir);
    } catch (const std::exception& e) {
      std::cerr << "Could not scan " << dir << ": " << e.what() << std::endl;
    }
  }

  // Start interactive menu
  scanner.menu();

  return 0;
}