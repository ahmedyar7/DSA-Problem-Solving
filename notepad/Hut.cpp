#include <conio.h>  // For getch()
#include <graphics.h>

#include <fstream>
#include <iostream>
#include <string>

#include "stack_implementation.cpp"
using namespace std;

struct Command {
  enum Operation { ADD, REMOVE };
  Operation op;
  string text;
};

stack<Command> undoStack;

void displayHeader() {
  setbkcolor(WHITE);
  setcolor(BLACK);
  cleardevice();

  // Display branding
  settextstyle(10, 0, 2);  // Triplex font, medium size
  outtextxy(10, 10, const_cast<char *>("Ahmed Yar Notepad"));
  line(10, 40, getmaxx() - 10, 40);  // Underline
}

void displayMenu() {
  displayHeader();
  settextstyle(8, 0, 1);  // Smaller font for menu options
  outtextxy(20, 60, const_cast<char *>("1. New Text"));
  outtextxy(20, 100, const_cast<char *>("2. Save Text"));
  outtextxy(20, 140, const_cast<char *>("3. Exit"));
  outtextxy(20, 180, const_cast<char *>("Enter your choice:"));
}

void displayText(const string &text) {
  cleardevice();
  displayHeader();
  outtextxy(10, 50, const_cast<char *>("Text Preview:"));

  int y = 80;  // Start position for text display
  for (size_t i = 0; i < text.length(); i += 50) {  // Break text into lines
    string line = text.substr(i, 50);
    outtextxy(10, y, const_cast<char *>(line.c_str()));
    y += 20;  // Move down for the next line
  }
  delay(2000);  // Allow user to read the displayed text
}

void editText(string &text) {
  cleardevice();
  displayHeader();
  outtextxy(10, 50,
            const_cast<char *>("Enter your text (Press ENTER to finish):"));

  string buffer;
  int pos = 0;
  char ch;

  while ((ch = getch()) != 13) {           // Enter key to finish
    if (ch == 26 && !undoStack.empty()) {  // Ctrl+Z for undo
      Command lastCommand = undoStack.top();
      undoStack.pop();

      if (lastCommand.op == Command::ADD) {
        if (!buffer.empty()) {
          buffer.pop_back();  // Remove last character
          pos--;
        }
      } else if (lastCommand.op == Command::REMOVE) {
        buffer += lastCommand.text;  // Re-add last removed character
        pos++;
      }

    } else if (ch == 8 && pos > 0) {  // Backspace
      pos--;
      char deletedChar = buffer.back();
      buffer.pop_back();

      Command removeCommand = {Command::REMOVE, string(1, deletedChar)};
      undoStack.push(removeCommand);

    } else if (pos < 1000 && ch != 8) {  // Add character
      buffer += ch;
      Command addCommand = {Command::ADD, string(1, ch)};
      undoStack.push(addCommand);
      pos++;
    }

    // Refresh the text area
    cleardevice();
    displayHeader();
    outtextxy(10, 50,
              const_cast<char *>("Enter your text (Press ENTER to finish):"));

    outtextxy(10, 100, const_cast<char *>(buffer.c_str()));
  }

  text = buffer;  // Update text with the final input
}

void saveText(const string &text) {
  ofstream file("notepad.txt");
  cleardevice();
  displayHeader();

  if (file.is_open()) {
    file << text;
    file.close();
    outtextxy(10, 50, const_cast<char *>("Text saved to 'notepad.txt'."));
  } else {
    outtextxy(10, 50, const_cast<char *>("Error: Could not save the text."));
  }

  delay(2000);  // Allow user to read the message
}

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, nullptr);

  string text;  // The current text
  char choice;

  while (true) {
    displayMenu();

    choice = getch();  // Get the user's choice

    switch (choice) {
      case '1': {  // New Text
        editText(text);
        break;
      }
      case '2': {  // Save Text
        saveText(text);
        break;
      }
      case '3': {  // Exit
        cleardevice();
        outtextxy(10, 50, const_cast<char *>("Exiting..."));
        delay(1000);
        closegraph();
        return 0;
      }
      default: {  // Invalid choice
        cleardevice();
        outtextxy(10, 50,
                  const_cast<char *>("Invalid choice. Please try again."));
        delay(1000);
        break;
      }
    }
  }

  closegraph();
  return 0;
}
