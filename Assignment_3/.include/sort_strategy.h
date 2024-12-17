#ifndef SORT_STRATEGY_H
#define SORT_STRATEGY_H

#include <functional>
#include <string>

#include "dynamic_array.h"
#include "file_info.h"
using namespace std;

class SortStrategy {
 public:
  virtual void sort(
      DynamicArray<FileInfo>& files,
      function<bool(const FileInfo&, const FileInfo&)> comparator) = 0;
  virtual string getName() const = 0;
  virtual ~SortStrategy() {}
};
#endif  // SORT_STRATEGY_H