#include <conio.h>  // For getch()
#include <graphics.h>

#include <fstream>
#include <iostream>
#include <string>

#include "UI.cpp"

using namespace std;

// Main function
int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, nullptr);

  string text;  // The current text
  char choice;

  while (true) {
    displayMenu();

    choice = getch();  // Get user input

    switch (choice) {
      case '1': {  // Create New Text
        editText(text);
        break;
      }
      case '2': {  // Save Text
        saveText(text);
        break;
      }
      case '3': {  // Exit Program
        cleardevice();
        setcolor(BLUE);
        outtextxy(20, 100, const_cast<char *>("Exiting..."));
        delay(2000);
        closegraph();
        return 0;
      }
      default: {  // Invalid input
        cleardevice();
        setcolor(RED);
        outtextxy(20, 100, const_cast<char *>("Invalid choice. Try again."));
        delay(1000);
        break;
      }
    }
  }

  closegraph();
  return 0;
}
