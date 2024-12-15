#include <iostream>

#include "DynamicArray.h"
#include "file.h"
#include "sorting.h"
#include "utility.h"  // Make sure this header includes the read_directory function

int main() {
  Utility util;
  DynamicArray files;  // To hold files from the directory
  std::string directory =
      "path_to_your_directory";  // Specify the directory you want to read

  // Step 1: Read the directory and populate the files array
  util.read_directory(directory, files);

  // Step 2: Check if the files are populated correctly (optional debug)
  for (int i = 0; i < files.get_size(); i++) {
    files[i].display();
  }

  // Step 3: Proceed to sorting based on user input
  Sorting sorter;
  int choice;
  std::cout << "Choose sorting criteria:\n1. By Name\n2. By Date\n3. By Size\n";
  std::cin >> choice;

  // Sorting based on the selected criteria
  switch (choice) {
    case 1:
      sorter.quick_sort(files, 0, files.get_size() - 1, File::compare_by_name);
      break;
    case 2:
      sorter.quick_sort(files, 0, files.get_size() - 1, File::compare_by_date);
      break;
    case 3:
      sorter.quick_sort(files, 0, files.get_size() - 1, File::compare_by_size);
      break;
    default:
      std::cout << "Invalid choice.\n";
      break;
  }

  // Step 4: Display sorted files
  for (int i = 0; i < files.get_size(); i++) {
    files[i].display();  // Accessing File by value
  }

  return 0;
}
