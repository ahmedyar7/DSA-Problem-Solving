#ifndef UTILITY_H
#define UTILITY_H

#include <experimental/filesystem>  // Use experimental filesystem
#include <string>
#include <vector>

#include "File.h"

namespace fs = std::experimental::filesystem;  // Use experimental namespace

class Utility {
 public:
  // Scans a directory and retrieves file information
  static std::vector<File> readFiles(const std::string& path);

  // Converts a filesystem time to a tm structure
  static std::tm parseDate(const fs::file_time_type& ftime);
};

#endif
