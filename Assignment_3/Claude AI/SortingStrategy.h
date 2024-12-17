
#include <chrono>
#include <ctime>
#include <filesystem>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "DynamicArray.h"
#include "FileInfo.h"

// Sorting Strategy Interface
class SortStrategy {
 public:
  virtual void sort(
      DynamicArray<FileInfo>& files,
      std::function<bool(const FileInfo&, const FileInfo&)> comparator) = 0;
  virtual std::string getName() const = 0;
  virtual ~SortStrategy() {}
};
