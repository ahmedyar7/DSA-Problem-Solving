#ifndef FILE_H
#define FILE_H

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
};

#endif
