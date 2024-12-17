#include <chrono>
#include <iostream>
#include <string>
#include <vector>

#include "File.h"
#include "Sorter.h"
#include "Utility.h"

void displayMenu() {
  std::cout << "Sorting Application Menu:\n";
  std::cout << "1. Sort by Name\n";
  std::cout << "2. Sort by Size\n";
  std::cout << "3. Sort by Date\n";
  std::cout << "Enter your choice: ";
}

void displayAlgorithmMenu() {
  std::cout << "Choose Sorting Algorithm:\n";
  std::cout << "1. Quick Sort\n";
  std::cout << "2. Merge Sort\n";
  std::cout << "3. Insertion Sort\n";
  std::cout << "4. Selection Sort\n";
  std::cout << "Enter your choice: ";
}

int main() {
  std::string path;
  std::cout << "Enter the path to scan files: ";
  std::cin >> path;

  // Step 1: Read files
  std::vector<File> files = Utility::readFiles(path);
  if (files.empty()) {
    std::cerr << "No files found in the specified path." << std::endl;
    return 1;
  }
  std::cout << "Total files read: " << files.size() << "\n";

  // Step 2: Choose attribute to sort by
  displayMenu();
  int attributeChoice;
  std::cin >> attributeChoice;

  std::function<bool(const File&, const File&)> comparator;
  switch (attributeChoice) {
    case 1:
      comparator = File::compareByName;
      break;
    case 2:
      comparator = File::compareBySize;
      break;
    case 3:
      comparator = File::compareByDate;
      break;
    default:
      std::cerr << "Invalid choice!" << std::endl;
      return 1;
  }

  // Step 3: Choose sorting algorithm
  displayAlgorithmMenu();
  int algorithmChoice;
  std::cin >> algorithmChoice;

  auto start = std::chrono::high_resolution_clock::now();
  switch (algorithmChoice) {
    case 1:
      Sorter::quickSort(files, 0, files.size() - 1, comparator);
      break;
    case 2:
      Sorter::mergeSort(files, 0, files.size() - 1, comparator);
      break;
    case 3:
      Sorter::insertionSort(files, comparator);
      break;
    case 4:
      Sorter::selectionSort(files, comparator);
      break;
    default:
      std::cerr << "Invalid choice!" << std::endl;
      return 1;
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsed = end - start;

  // Step 4: Display sorted results
  std::cout << "Files sorted successfully in " << elapsed.count() << " ms.\n";
  for (const auto& file : files) {
    std::cout << "Name: " << file.getName() << ", Size: " << file.getSize()
              << ", Date: " << File::formatDate(file.getDate()) << "\n";
  }

  return 0;
}
