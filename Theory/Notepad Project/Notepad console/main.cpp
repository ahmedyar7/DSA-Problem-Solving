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
    cout << "Welcome to Notepad-like Word Processor!\n";
    cout << "1. Add text\n";
    cout << "2. Delete text\n";
    cout << "3. Undo last action\n";
    cout << "4. Display current text\n";
    cout << "5. Exit\n";
    cout << "Please select an option (1-5): ";
    cin >> choice;

    cin.ignore();  // Ignore newline after choice input

    switch (choice) {
      case 1: {
        cout << "Enter text to add: ";
        cin.getline(buffer, MAX_TEXT_SIZE);
        notepad.add_text(buffer);
        break;
      }
      case 2: {
        int length;
        cout << "Enter number of characters to delete: ";
        cin >> length;
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
        cout << "Exiting application.\n";
        break;
      default:
        cout << "Invalid option. Please try again.\n";
        break;
    }
  } while (choice != 5);

  return 0;
}
