#include "Utility.h"

#include <chrono>
#include <ctime>
#include <experimental/filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;  // Use experimental namespace

// Reads files from a directory recursively
std::vector<File> Utility::readFiles(const std::string& path) {
  std::vector<File> files;
  try {
    for (const auto& entry : fs::recursive_directory_iterator(path)) {
      if (fs::is_regular_file(entry)) {
        std::string name = entry.path().filename().string();
        long size = fs::file_size(entry);
        std::tm date = parseDate(fs::last_write_time(entry));
        files.emplace_back(name, size, date);
      }
    }
  } catch (const fs::filesystem_error& e) {
    std::cerr << "Error reading directory: " << e.what() << std::endl;
  }
  return files;
}

// Converts file_time_type to std::tm
std::tm Utility::parseDate(const fs::file_time_type& ftime) {
  auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
      ftime - fs::file_time_type::clock::now() +
      std::chrono::system_clock::now());
  std::time_t time = std::chrono::system_clock::to_time_t(sctp);
  return *std::localtime(&time);
}
