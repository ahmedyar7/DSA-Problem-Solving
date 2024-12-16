#ifndef FILE_SCANNER_H
#define FILE_SCANNER_H

#include <filesystem>
#include <string>

#include "dynamic_array.h"
#include "file_info.h"
using namespace std;

class FileScanner {
 public:
  static DynamicArray<FileInfo> scanDirectories(const string& rootPath = "") {
    DynamicArray<FileInfo> files;

    // If no root path provided, scan all drives
    if (rootPath.empty()) {
      // Scan available drives (Windows-style, modify for cross-platform)
      for (char drive = 'C'; drive <= 'Z'; ++drive) {
        filesystem::path drivePath = string(1, drive) + ":/";

        if (filesystem::exists(drivePath)) {
          try {
            scanDirectory(drivePath, files);
          } catch (const exception& e) {
            cerr << "Error scanning drive " << drivePath << ": " << e.what()
                 << endl;
          }
        }
      }
    } else {
      // Scan specific directory
      filesystem::path directoryPath(rootPath);
      if (filesystem::exists(directoryPath)) {
        try {
          scanDirectory(directoryPath, files);
        } catch (const exception& e) {
          cerr << "Error scanning directory " << rootPath << ": " << e.what()
               << endl;
        }
      }
    }

    return files;
  }

 private:
  static void scanDirectory(const filesystem::path& directory,
                            DynamicArray<FileInfo>& files, int depth = 0) {
    // Limit recursion depth to prevent excessive scanning
    if (depth > 5)
      return;  // Increased from 3 to 5 for more comprehensive scanning

    try {
      for (const auto& entry :
           filesystem::recursive_directory_iterator(directory)) {
        if (filesystem::is_regular_file(entry)) {
          FileInfo fileInfo;
          fileInfo.filename = entry.path().filename().string();
          fileInfo.path = entry.path().string();

          try {
            fileInfo.size = filesystem::file_size(entry);
            fileInfo.lastModified = filesystem::last_write_time(entry);
            files.push_back(fileInfo);
          } catch (const filesystem::filesystem_error& e) {
            cerr << "Error getting file info: " << e.what() << endl;
          }
        }
      }
    } catch (const exception& e) {
      cerr << "Error scanning directory " << directory << ": " << e.what()
           << endl;
    }
  }
};

#endif
