#ifndef FILE_H
#define FILE_H

#include <chrono>
#include <ctime>
#include <filesystem>
#include <iostream>

using namespace std;

class File {
 private:
  // Attributes
  char file_name[100];
  int file_size;
  char file_date[100];

  // Helper function for comparing strings
  int compare_string(const char* string1, const char* string2) const {
    int i = 0;
    while (string1[i] != '\0' && string2[i] != '\0') {
      if (string1[i] != string2[i]) {
        return string1[i] - string2[i];
      }
      i++;
    }
    return string1[i] - string2[i];
  }

  // Helper function to convert time point to string format
  void time_to_string(
      std::chrono::time_point<std::chrono::system_clock> time_point) {
    std::time_t time = std::chrono::system_clock::to_time_t(time_point);
    std::tm* tm = std::localtime(&time);
    // Format the time as "YYYY-MM-DD HH:MM:SS"
    strftime(file_date, sizeof(file_date), "%Y-%m-%d %H:%M:%S", tm);
  }

 public:
  // Default Constructor
  File() {
    file_name[0] = '\0';
    file_size = 0;
    file_date[0] = '\0';
  }

  // Parameterized Constructor
  File(const char* name, int size, const char* date) {
    set_file_name(name);
    set_file_size(size);
    set_file_date(date);
  }

  // Helper function for copying strings
  void copy_string(char* destination, const char* source, int max_len) {
    int i = 0;
    while (i < max_len - 1 && source[i] != '\0') {
      destination[i] = source[i];
      i++;
    }
    destination[i] = '\0';
  }

  // Getters
  const char* get_file_name() const { return file_name; }
  int get_file_size() const { return file_size; }
  const char* get_file_date() const { return file_date; }

  // Setters
  void set_file_name(const char* name) { copy_string(file_name, name, 100); }
  void set_file_size(int size) { file_size = size; }
  void set_file_date(const char* date) { copy_string(file_date, date, 100); }

  // Static Comparison Methods
  static int compare_by_name(const File& f1, const File& f2) {
    return f1.compare_string(f1.file_name, f2.file_name);
  }

  static int compare_by_date(const File& f1, const File& f2) {
    return f1.compare_string(f1.file_date, f2.file_date);
  }

  static int compare_by_size(const File& f1, const File& f2) {
    return f1.file_size - f2.file_size;
  }

  // Display Method
  void display() const {
    cout << "File Name: " << file_name << ", File Size: " << file_size
         << ", Date Modified: " << file_date << endl;
  }

  // Method to set the file date from a timestamp (for use with read_directory)
  void set_file_date_from_timestamp(std::filesystem::file_time_type timestamp) {
    // Convert file_time_type (from filesystem) to system_clock time_point
    auto sys_time =
        std::chrono::time_point_cast<std::chrono::system_clock::duration>(
            timestamp - std::filesystem::file_time_type::clock::now() +
            std::chrono::system_clock::now());
    time_to_string(sys_time);
  }
};

#endif  // FILE_H
