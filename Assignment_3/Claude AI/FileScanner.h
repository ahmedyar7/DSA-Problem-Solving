#include "DynamicArray.h"
#include "FileInfo.h"
// #include <algorithm>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// File Scanner Class (unchanged)
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