#ifndef FILE_INFO_H
#define FILE_INFO_H

#include <chrono>
#include <filesystem>
#include <iostream>
#include <string>
using namespace std;
class FileInfo {
 public:
  string filename;
  string path;
  uintmax_t size;
  filesystem::file_time_type lastModified;

  FileInfo() : size(0) {}

  bool compareByName(const FileInfo& other) const {
    return filename < other.filename;
  }

  bool compareBySize(const FileInfo& other) const { return size < other.size; }

  bool compareByModifiedDate(const FileInfo& other) const {
    return lastModified < other.lastModified;
  }

  friend ostream& operator<<(ostream& os, const FileInfo& fi) {
    auto file_time =
        chrono::time_point_cast<chrono::milliseconds>(fi.lastModified);
    auto duration = file_time.time_since_epoch();
    auto time_t_value =
        chrono::duration_cast<chrono::seconds>(duration).count();

    tm* timeInfo = localtime(&time_t_value);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);

    os << "Filename: " << fi.filename << ", Path: " << fi.path
       << ", Size: " << fi.size << " bytes"
       << ", Last Modified: " << buffer;

    return os;
  }
};
#endif