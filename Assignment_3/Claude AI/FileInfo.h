#ifndef FILE_INFO_H
#define FILE_INFO_H

#include <chrono>
#include <ctime>
#include <filesystem>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class FileInfo {
 public:
  std::string filename;
  std::string path;
  uintmax_t size;
  std::filesystem::file_time_type lastModified;

  FileInfo() : size(0) {}

  bool compareByName(const FileInfo& other) const {
    return filename < other.filename;
  }

  bool compareBySize(const FileInfo& other) const { return size < other.size; }

  bool compareByModifiedDate(const FileInfo& other) const {
    return lastModified < other.lastModified;
  }

  friend std::ostream& operator<<(std::ostream& os, const FileInfo& fi) {
    auto file_time = std::chrono::time_point_cast<std::chrono::milliseconds>(
        fi.lastModified);
    auto duration = file_time.time_since_epoch();
    auto time_t_value =
        std::chrono::duration_cast<std::chrono::seconds>(duration).count();

    std::tm* timeInfo = std::localtime(&time_t_value);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);

    os << "Filename: " << fi.filename << ", Path: " << fi.path
       << ", Size: " << fi.size << " bytes"
       << ", Last Modified: " << buffer;

    return os;
  }
};

#endif