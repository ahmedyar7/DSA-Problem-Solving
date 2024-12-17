#ifndef FILE_H
#define FILE_H

#include <ctime>  // For tm structure
#include <string>

class File {
 private:
  std::string name;
  long size;     // File size in bytes
  std::tm date;  // Last modified date

 public:
  // Constructor
  File(const std::string& name, long size, const std::tm& date);

  // Getters
  std::string getName() const;
  long getSize() const;
  std::tm getDate() const;

  // Static comparators for sorting
  static bool compareByName(const File& a, const File& b);
  static bool compareBySize(const File& a, const File& b);
  static bool compareByDate(const File& a, const File& b);

  // Utility to format date as a string
  static std::string formatDate(const std::tm& date);
};

#endif
