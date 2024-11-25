#include <conio.h>  // For getch()
#include <graphics.h>

#include <fstream>
#include <iostream>
#include <string>

#include "stack.h"

using namespace std;

struct Command {
  enum Operation { ADD, remove };
  Operation op;
  std::string text;
};
// * stack to store string

stack<Command> store;

void displayMenu() {
  cleardevice();

  setbkcolor(WHITE);
  setcolor(BLACK);
  settextstyle(10, 0, 2);  // Set Triplex font, horizontal text, medium size
  outtextxy(
      50, 50,
      const_cast<char *>(" 478817 - Hamza - Notepad - v.0.1 - (22-Nov-224)"));
  outtextxy(50, 100, const_cast<char *>("1. New Text"));
  outtextxy(50, 150, const_cast<char *>("2. Save Text"));
  outtextxy(50, 200, const_cast<char *>("3. Exit"));
  outtextxy(50, 250, const_cast<char *>("Enter your choice:"));
}

// Function to display the current texts
void displayText(const string &text) {
  cleardevice();
  setbkcolor(BLUE);       // Set background color to blue
  setcolor(WHITE);        // Set text color to white
  settextstyle(8, 0, 1);  // Smaller text style
  outtextxy(50, 50, const_cast<char *>("Current Text:"));

  int y = 100;  // Start position for text display
  for (size_t i = 0; i < text.length(); i += 10) {  // Break text into lines
    string line = text.substr(i, 50);
    outtextxy(100, y, const_cast<char *>(line.c_str()));
    y += 30;  // Move down for the next line
  }
  delay(2000);  // Allow user to read the displayed text
}

// Main function
int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, nullptr);

  string text = "";  // Text being edited
  char choice;

  while (true) {
    displayMenu();  // Show menu

    choice = getch();  // Get the user's choice

    switch (choice) {
      case '1': {  // Edit text
        cleardevice();
        outtextxy(
            50, 50,
            const_cast<char *>("Enter your text (press ENTER to finish):"));

        string buffer = "";  // Use std::string for input
        int pos = 0;         // Current position in the buffer
        char ch;

        while ((ch = getch()) != 13) {
          // Undo oprations
          if (ch == 26 && !store.empty())  // CTRL+Z and stack is not empty
          {
            Command lastCommand = store.top();
            store.pop();

            if (lastCommand.op == Command::ADD) {
              // Remove the last added character
              if (!buffer.empty()) {
                buffer.pop_back();
                pos--;  // Update cursor position
              }
            } else if (lastCommand.op == Command::remove) {
              // Re-add the last removed character
              buffer += lastCommand.text;
              pos++;  // Update cursor position
            }

            // Clear the screen area and re-render the buffer
            cleardevice();  // Clear graphics device
            outtextxy(
                50, 50,
                const_cast<char *>("Enter your text (press ENTER to finish):"));
            for (size_t i = 0; i < buffer.length(); i++) {
              char temp[2] = {buffer[i], '\0'};
              outtextxy(50 + (i * 10), 100, temp);
            }
          }

          else if (ch == 8 && pos > 0) {  // Handle backspace
            pos--;                        // Decrease position
            // * delete text
            char deletedChar =
                buffer.back();  // Get the last character that is being removed
            outtextxy(50, 50,
                      const_cast<char *>(std::string(1, deletedChar).c_str()));
            buffer.pop_back();  // Remove the last character from the string

            setfillstyle(SOLID_FILL, BLUE);
            bar(50 + (pos * 10), 100, 50 + (pos * 10) + 10,
                120);  // Clear the character's space
            // *creating cmmnd instance
            Command remv_string;
            remv_string.text = deletedChar;
            remv_string.op = Command::remove;
            store.push(remv_string);
          } else if (pos < 999 && ch != 8) {  // Append character
            buffer += ch;                     // Add the character to the string
            char temp[2] = {ch, '\0'};
            outtextxy(50 + (pos * 10), 100,
                      temp);  // Display the character at the correct position
            pos++;
            Command add_string;
            add_string.text = ch;
            add_string.op = Command::ADD;
            store.push(add_string);
          }
        }

        text = buffer;  // Update the text variable with the entered string
        break;
      }

      case '2': {  // Save text
        ofstream file("notepad.txt");
        if (file.is_open()) {
          file << text;
          file.close();
          cleardevice();
          outtextxy(50, 50, const_cast<char *>("Text saved to 'notepad.txt'"));
        } else {
          cleardevice();
          outtextxy(50, 50,
                    const_cast<char *>("Error: Could not save the text."));
        }
        delay(2000);  // Allow user to read the message
        break;
      }
      case '3': {  // Exit
        cleardevice();
        outtextxy(50, 50, const_cast<char *>("Exiting..."));
        delay(1000);
        closegraph();
        return 0;
      }
      default: {  // Invalid choice
        cleardevice();
        outtextxy(50, 50, const_cast<char *>("Invalid choice! Try again."));
        delay(500);  // Allow user to read the message
        break;
      }
    }
  }

  closegraph();
  return 0;
}