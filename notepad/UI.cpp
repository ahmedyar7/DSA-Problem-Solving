#include <conio.h>  // For getch()
#include <graphics.h>

#include <fstream>
#include <iostream>
#include <string>

#include "stack.cpp"
#include "stack.h"
using namespace std;

struct Command {
  enum Operation { ADD, REMOVE };
  Operation op;
  string text;
};

stack<Command> undoStack;

// Function to display the header with gradient effect
void displayHeader() {
  setbkcolor(LIGHTCYAN);  // Light cyan background
  setcolor(BLUE);         // Blue text color
  cleardevice();

  settextstyle(10, 0, 3);  // Triplex font, larger size for branding
  outtextxy(10, 10, const_cast<char *>("Welcome Notepad!"));

  setcolor(GREEN);                   // Green underline
  line(10, 50, getmaxx() - 10, 50);  // Underline
}

// Function to display the main menu
void displayMenu() {
  displayHeader();
  settextstyle(8, 0, 2);  // Medium font for menu options
  setcolor(BLACK);

  outtextxy(40, 70, const_cast<char *>("Select an option below:"));
  settextstyle(7, 0, 2);  // Different font for menu items
  outtextxy(60, 120, const_cast<char *>("1. Create New Text"));
  outtextxy(60, 160, const_cast<char *>("2. Save Current Text"));
  outtextxy(60, 200, const_cast<char *>("3. Exit Program"));
  settextstyle(8, 0, 1);  // Footer instruction
  outtextxy(60, 260, const_cast<char *>("Use numbers (1-3) to select."));
}

// Function to display text with improved formatting
void displayText(const string &text) {
  cleardevice();
  displayHeader();
  outtextxy(20, 60, const_cast<char *>("Current Text:"));

  int y = 100;            // Start position for text display
  settextstyle(3, 0, 1);  // Smaller font for text
  setcolor(BLACK);

  for (size_t i = 0; i < text.length();
       i += 40) {  // Display in chunks of 40 characters
    string line = text.substr(i, 40);
    outtextxy(20, y, const_cast<char *>(line.c_str()));
    y += 20;  // Move down for the next line
  }

  delay(3000);  // Pause for user to view the text
}

// Function to edit text
void editText(string &text) {
  cleardevice();
  displayHeader();
  setcolor(DARKGRAY);
  outtextxy(10, 70,
            const_cast<char *>("Editing Mode: Type below (Enter to finish)"));

  string buffer;
  int pos = 0;
  char ch;

  while ((ch = getch()) != 13) {           // Enter key to finish editing
    if (ch == 26 && !undoStack.empty()) {  // Ctrl+Z for undo
      Command lastCommand = undoStack.top();
      undoStack.pop();

      if (lastCommand.op == Command::ADD) {
        if (!buffer.empty()) {
          buffer.pop_back();
          pos--;
        }
      } else if (lastCommand.op == Command::REMOVE) {
        buffer += lastCommand.text;
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

    // Refresh the editor display
    cleardevice();
    displayHeader();
    setcolor(BLACK);
    outtextxy(10, 70,
              const_cast<char *>("Editing Mode: Type below (Enter to finish)"));
    outtextxy(20, 100, const_cast<char *>(buffer.c_str()));
  }

  text = buffer;
}

// Function to save text to a file
void saveText(const string &text) {
  ofstream file("notes.txt");
  cleardevice();
  displayHeader();

  if (file.is_open()) {
    file << text;
    file.close();
    setcolor(DARKGRAY);
    outtextxy(10, 60,
              const_cast<char *>("Text successfully saved to 'notes.txt'."));
  } else {
    setcolor(RED);
    outtextxy(10, 60, const_cast<char *>("Error: Could not save text."));
  }

  delay(2000);  // Pause for user to read the message
}