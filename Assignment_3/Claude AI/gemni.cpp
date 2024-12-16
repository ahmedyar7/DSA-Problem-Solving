#include <algorithm>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace std::filesystem;

// Custom Dynamic Array
template <typename T>
class DynamicArray {
 public:
  DynamicArray() : data(nullptr), capacity(0), size(0) {}

  ~DynamicArray() { delete data; }

  void push_back(const T& element) {
    if (size == capacity) {
      T* newData = new T[capacity * 2];
      for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
      }
      delete[] data;
      data = newData;
      capacity *= 2;
    }
    data[size++] = element;
  }

  T& operator[](size_t index) { return data[index]; }

  size_t size() const { return size; }

 private:
  T* data;
  size_t capacity;
  size_t size;
};

// FileInfo Structure
struct FileInfo {
  string filename;
  string path;
  uintmax_t size;
  time_t lastModified;

  bool operator<(const FileInfo& other) const {
    return filename < other.filename;
  }

  bool operator>(const FileInfo& other) const {
    return filename > other.filename;
  }
  bool compareByModifiedDate(const FileInfo& other) const {
    auto file_time1 =
        std::chrono::time_point_cast<std::chrono::milliseconds>(lastModified);
    auto file_time2 = std::chrono::time_point_cast<std::chrono::milliseconds>(
        other.lastModified);

    return file_time1 < file_time2;
  }
};

// Sorting Algorithms
template <typename T>
void quickSort(T arr[], int low, int high,
               bool (*compare)(const T&, const T&)) {
  if (low < high) {
    int pi = partition(arr, low, high, compare);

    quickSort(arr, low, pi - 1, compare);
    quickSort(arr, pi + 1, high, compare);
  }
}

template <typename T>
int partition(T arr[], int low, int high, bool (*compare)(const T&, const T&)) {
  T pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (compare(arr[j], pivot)) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

template <typename T>
void mergeSort(T arr[], int low, int high,
               bool (*compare)(const T&, const T&)) {
  if (low < high) {
    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid, compare);
    mergeSort(arr, mid + 1, high, compare);

    merge(arr, low, mid, high, compare);
  }
}

template <typename T>
void merge(T arr[], int left, int mid, int right,
           bool (*compare)(const T&, const T&)) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  T L[n1], R[n2];

  for (int i = 0; i < n1; i++) L[i] = arr[left + i];
  for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (compare(L[i], R[j])) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// File Scanner
void scanDirectory(const path& dirPath, DynamicArray<FileInfo>& files) {
  for (const directory_entry& entry : directory_iterator(dirPath)) {
    if (is_regular_file(entry)) {
      FileInfo fileInfo;
      fileInfo.filename = entry.path().filename().string();
      fileInfo.path = entry.path().string();
      fileInfo.size = file_size(entry);
      fileInfo.lastModified = last_write_time(entry);
      files.push_back(fileInfo);
    } else if (is_directory(entry)) {
      scanDirectory(entry.path(), files);
    }
  }
}

// Main Function
int main() {
  DynamicArray<FileInfo> files;
  scanDirectory(current_path(), files);

  cout << "Total files: " << files.size() << endl;

  int choice;
  cout << "Choose sorting criteria:\n";
  cout << "1. Name\n";
  cout << "2. Size\n";
  cout << "3. Last Modified Date\n";
  cin >> choice;

  // ... (Implementation for sorting algorithms and displaying results)

  return 0;
}