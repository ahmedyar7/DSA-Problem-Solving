#include <iostream>

// #include "notepad.cpp"
#include "notepad.h"  // Remove notepad.cpp include
#include "textstack.h"
using namespace std;

int main() {
  Notepad notepad;
  char input[MAX_TEXT_SIZE];
  int choice;

  do {
    cout << "\n1. Add Text\n2. Delete\n3. Move Up\n4. Move Down\n";
    cout << "5. Move Left\n6. Move Right\n7. Undo\n8. Display\n";
    cout << "9. Save\n10. Load\n11. Exit\n";
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter text: ";
        cin.ignore();
        cin.getline(input, MAX_TEXT_SIZE);
        notepad.add_text(input);
        break;
      case 2:
        notepad.delete_text();
        break;
      case 3:
        notepad.move_cursor_up();
        break;
      case 4:
        notepad.move_cursor_down();
        break;
      case 5:
        notepad.move_cursor_left();
        break;
      case 6:
        notepad.move_cursor_right();
        break;
      case 7:
        notepad.undo();
        break;
      case 8:
        notepad.display();
        break;
      case 9:
        notepad.save_to_file("output.txt");
        break;
      case 10:
        notepad.load_from_file("output.txt");
        break;
      case 11:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice!" << endl;
    }
  } while (choice != 11);

  return 0;
}