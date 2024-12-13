#include <windows.h>  // Windows API

#include <iostream>
#include <string>

using namespace std;

// Traverse the file and sub-directories from the path provided
void traverse_directory(const char* dir_path) {
  WIN32_FIND_DATAA find_file_data;  // Use WIN32_FIND_DATAA for ANSI support
  HANDLE h_file =
      FindFirstFileA((string(dir_path) + "\\*").c_str(), &find_file_data);

  if (h_file == INVALID_HANDLE_VALUE) {
    cout << "Error: Unable to access the directory." << endl;
    return;
  }

  do {
    // Skip '.' and '..'
    if (find_file_data.cFileName[0] == '.') continue;

    // Check if it is a directory or file
    if (find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
      cout << "Directory: " << find_file_data.cFileName << endl;
      // Recursively traverse subdirectories
      traverse_directory(
          (string(dir_path) + "\\" + find_file_data.cFileName).c_str());
    } else {
      cout << "File: " << find_file_data.cFileName << endl;
    }
  } while (FindNextFileA(h_file, &find_file_data) != 0);

  // Close the handle after processing
  FindClose(h_file);
}