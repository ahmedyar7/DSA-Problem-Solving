/*
 The File class encapsulates attributes of a file, including its name, size,
 and date.
 It provides methods to initialize, retrieve, and modify these
 attributes.
 Comparison functions are implemented to allow sorting files by
 name, size, or date.
*/

#ifndef FILE_H
#define FILE_H
#include <iostream>
using namespace std;

class File {
 private:
  // Attributes:
  char file_name[100];
  int file_size;
  char file_date[100];

  // Helper Function for Copying string
  void copy_string(char* destination, char* source, int max_len) {
    int i = 0;
    while (i < max_len - 1 && source[i] != '\0') {
      destination[i] = source[i];
      i++;
    }
    destination[i] = '\0';
  }

  // Helper Function for Comparing String
  int compare_string(char* string1, char* string2) {
    int i = 0;
    while (string1[i] != '\0' && string2[i] != '\0') {
      if (string1[1] != string2[i]) {
        return string1[i] - string2[i];
      }
      i++;
    }
    return string1[i] - string2[i];
  }

 public:
  // Default  Constructor
  File() {
    file_name[0] = '\0';
    file_size = 0;
    file_date[0] = '\0';
  }

  // Parameterized Constructor
  File(char* name, int size, char* date) {
    copy_string(file_name, name, 100);
    file_size = size;
    copy_string(file_date, date, 100);
  }

  // Setters
  void set_file_name(char* name) { copy_string(file_name, name, 100); }
  void set_file_size(int size) { file_size = size; }
  void set_file_date(char* date) { copy_string(file_date, date, 100); }

  // Getters
  char* get_file_name() { return file_name; }
  char* get_file_date() { return file_date; }
  int get_file_size() { return file_size; }

  // Utility Comparisons method
  static int compare_by_name(File& f1, File& f2) {
    return f1.compare_string(f1.file_name, f2.file_name);
  }

  static int compare_by_date(File& f1, File& f2) {
    return f1.compare_string(f1.file_date, f2.file_date);
  }

  static int compare_by_size(File& f1, File& f2) {
    return f1.file_size - f2.file_size;
  }

  void display() {
    cout << "File Name: " << file_name << ", File Size: " << file_size
         << ", Date Modified: " << file_date << endl;
  }
};

#endif

// Why did we use static
/*
    1. Do not require an instance of the class:
    2. These functions compare two File objects directly.

    They do not depend on the specific instance of the File class on which they
   are called. Belong to the class, not an object static methods are associated
   with the class itself rather than with any individual object of the class.
   You can call them using the class name (File::compareByName) instead of
   needing an object.
*/