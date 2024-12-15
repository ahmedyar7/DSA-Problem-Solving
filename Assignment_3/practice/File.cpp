#include "File.h"

#include <iomanip>  // For date formatting
#include <sstream>

// Constructor
File::File(const std::string& name, long size, const std::tm& date)
    : name(name), size(size), date(date) {}

// Getters
std::string File::getName() const { return name; }

long File::getSize() const { return size; }

std::tm File::getDate() const { return date; }

// Comparators for sorting
bool File::compareByName(const File& a, const File& b) {
  return a.name < b.name;
}

bool File::compareBySize(const File& a, const File& b) {
  return a.size < b.size;
}

bool File::compareByDate(const File& a, const File& b) {
  return std::mktime(const_cast<std::tm*>(&a.date)) <
         std::mktime(const_cast<std::tm*>(&b.date));
}

// Format date as string
std::string File::formatDate(const std::tm& date) {
  std::ostringstream oss;
  oss << std::put_time(&date, "%Y-%m-%d %H:%M:%S");
  return oss.str();
}
