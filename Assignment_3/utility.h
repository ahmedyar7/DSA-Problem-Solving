#ifndef UTILITY_H
#define UTILITY_H

#include <windows.h>

#include <chrono>
#include <ctime>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>

#include "DynamicArray.h"
#include "file.h"

namespace fs = std::filesystem;
using namespace std;

class Utility {
 private:
  // Data structure to store files (can use DynamicArray or another suitable
  // class)
  DynamicArray files;  // Assuming DynamicArray is a class for dynamic growth

 public:
  // Constructor
  Utility() {}

  // Method to start directory traversal
  void traverse_directory(const char* dir_path) {
    WIN32_FIND_DATAA find_file_data;
    HANDLE h_file =
        FindFirstFileA((string(dir_path) + "\\*").c_str(), &find_file_data);

    if (h_file == INVALID_HANDLE_VALUE) {
      cout << "Error: Unable to access the directory." << endl;
      return;
    }

    // Define the dynamic array to store files
    DynamicArray dynamic_array;

    do {
      if (find_file_data.cFileName[0] == '.') continue;

      // Get file name and size
      const char* file_name = find_file_data.cFileName;
      long file_size =
          find_file_data.nFileSizeLow;  // File size can be accessed directly
                                        // from WIN32_FIND_DATA

      // Create File object using C-style strings
      File file(file_name, file_size, "Unknown");  // Placeholder for file date

      // Add the file to the DynamicArray
      dynamic_array.push_back(file);

    } while (FindNextFileA(h_file, &find_file_data) != 0);

    FindClose(h_file);
  }

  // Method to display all files collected
  void display_files() {
    for (int i = 0; i < files.get_size(); i++) {
      files[i].display();
    }
  }

  // Method to read the directory and populate DynamicArray with file info
  void read_directory(const std::string& path, DynamicArray& files) {
    for (const auto& entry : fs::directory_iterator(path)) {
      if (fs::is_regular_file(entry.status())) {
        // Get the file name and size
        std::string file_name = entry.path().filename().string();
        uintmax_t file_size = entry.file_size();

        // Get the last write time (file_time_type)
        auto ftime = fs::last_write_time(entry);

        // Convert file_time_type to system_clock::time_point
        auto sctp =
            std::chrono::time_point_cast<std::chrono::system_clock::duration>(
                ftime - std::filesystem::file_time_type::clock::now() +
                std::chrono::system_clock::now());

        // Convert system_clock time_point to std::time_t
        std::time_t cftime = std::chrono::system_clock::to_time_t(sctp);

        // Convert std::time_t to string
        std::tm* ptm = std::localtime(&cftime);
        std::stringstream ss;
        ss << std::put_time(ptm, "%Y-%m-%d %H:%M:%S");
        std::string file_date = ss.str();

        // Create a File object and set its attributes
        File file(file_name.c_str(), file_size, file_date);

        // Add the file to the DynamicArray
        files.push_back(file);
      }
    }
  }
};

#endif  // UTILITY_H
