#ifndef DIRECTORY_TRAVERSER_H
#define DIRECTORY_TRAVERSER_H

#include <windows.h>  // Windows API

#include <iostream>
#include <string>

#include "File.h"  // Assuming File class is already created

using namespace std;

class Utility {
 private:
  // Data structure to store files (can use DynamicArray or another suitable
  // class)
  DynamicArray files;  // Assuming DynamicArray is a class for dynamic growth

  // Helper function to copy file data into File class
  void process_file(const WIN32_FIND_DATAA& find_file_data,
                    const string& dir_path) {
    // Create a File object and set its attributes
    char file_name[100];
    char file_date[100];
    int file_size =
        find_file_data
            .nFileSizeLow;  // Example: get file size from WIN32_FIND_DATAA

    // Copy the file name and date (simplified for this example)
    strcpy(file_name, find_file_data.cFileName);
    strcpy(file_date, "2024-12-14");  // Placeholder for actual file date logic

    File file(file_name, file_size,
              file_date);   // Assuming File class constructor is defined
    files.push_back(file);  // Store the file in the dynamic array
  }

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
      const char* file_date =
          "Unknown";  // You can fill in the date if necessary

      // Create File object using C-style strings
      File file(file_name, file_size, file_date);

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

  // Additional methods for sorting and reporting can be added here
};

#endif
