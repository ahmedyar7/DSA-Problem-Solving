#include <iostream>

#include "DynamicArray.h"
#include "File.h"
#include "Sorting.h"
#include "Utility.h"
using namespace std;

void display_menu() {
  cout << "1. Input Directory Path" << endl;
  cout << "2. Sort Files" << endl;
  cout << "3. Display Files" << endl;
  cout << "4. Exit" << endl;
}

int main() {
  DynamicArray file_array;
  Sorting sorter;
  string dir_path;
  Utility util;

  int choice;
  do {
    display_menu();
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter directory path: ";
        cin >> dir_path;
        util.traverse_directory(dir_path.c_str());
        break;
      case 2:
        int sort_choice;
        cout << "Select sorting algorithm: 1. Quick Sort 2. Merge Sort 3. "
                "Insertion Sort 4. Selection Sort"
             << endl;
        cin >> sort_choice;
        // Implement sorting based on the user's choice
        break;
      case 3:
        for (int i = 0; i < file_array.get_size(); ++i) {
          cout << file_array[i].get_file_name() << " "
               << file_array[i].get_file_size() << endl;
        }
        break;
      case 4:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice, try again." << endl;
    }
  } while (choice != 4);
  return 0;
}