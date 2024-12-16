#include <algorithm>
#include <filesystem>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;

void sortFiles(const std::string& directoryPath) {
  std::vector<fs::directory_entry> files;

  // Read all files in the directory
  for (const auto& entry : fs::directory_iterator(directoryPath)) {
    if (entry.is_regular_file()) {
      files.push_back(entry);
    }
  }

  // Sort files by name
  std::sort(files.begin(), files.end(),
            [](const fs::directory_entry& a, const fs::directory_entry& b) {
              return a.path().filename().string() <
                     b.path().filename().string();
            });

  // Display sorted files
  std::cout << "Sorted files in directory: " << directoryPath << std::endl;
  for (const auto& file : files) {
    std::cout << file.path().filename().string() << std::endl;
  }
}

int main() {
  std::string directoryPath;
  std::cout << "Enter the directory path: ";
  std::cin >> directoryPath;

  try {
    sortFiles(directoryPath);
  } catch (const fs::filesystem_error& e) {
    std::cerr << "Filesystem error: " << e.what() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
