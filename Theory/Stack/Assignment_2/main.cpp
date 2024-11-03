#include <iostream>

#include "notepad.cpp"
#include "notepad.h"
#include "textstack.h"

using namespace std;

int main() {
  Notepad notepad;
  int choice;
  char buffer[MAX_TEXT_SIZE];  // Buffer for input

  do {
    std::cout << "Welcome to Notepad-like Word Processor!\n";
    std::cout << "1. Add text\n";
    std::cout << "2. Delete text\n";
    std::cout << "3. Undo last action\n";
    std::cout << "4. Display current text\n";
    std::cout << "5. Exit\n";
    std::cout << "Please select an option (1-5): ";
    std::cin >> choice;

    std::cin.ignore();  // Ignore newline after choice input

    switch (choice) {
      case 1: {
        std::cout << "Enter text to add: ";
        std::cin.getline(buffer, MAX_TEXT_SIZE);
        notepad.add_text(buffer);
        break;
      }
      case 2: {
        int length;
        std::cout << "Enter number of characters to delete: ";
        std::cin >> length;
        notepad.delete_text(length);
        break;
      }
      case 3:
        notepad.undo();
        break;
      case 4:
        notepad.display();
        break;
      case 5:
        std::cout << "Exiting application.\n";
        break;
      default:
        std::cout << "Invalid option. Please try again.\n";
        break;
    }
  } while (choice != 5);

  return 0;
}
