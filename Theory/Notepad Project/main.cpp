#include <conio.h>
#include <graphics.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "stack.h"

using namespace std;

struct Command {
  enum Operation { ADD, REMOVE };
  Operation op;
  string text;
};

stack<Command> commandStack;

const int MAX_TEXT_LENGTH = 5000;

// Function to display a title bar
void drawTitleBar() {
  setfillstyle(SOLID_FILL, LIGHTGRAY);  // Light gray title bar
  bar(0, 0, 1280, 40);                  // Draw the title bar
  setcolor(BLACK);                      // Black text for title
  settextstyle(3, 0, 1);                // Set text size for title
  outtextxy(10, 10, const_cast<char*>("Ahmed Yar - Notepad v1.2"));
}

// Function to display a status bar
void drawStatusBar(const string& status) {
  setfillstyle(SOLID_FILL, LIGHTGRAY);  // Light gray status bar
  bar(0, 680, 1280, 720);               // Draw status bar
  setcolor(BLACK);                      // Black text for status
  settextstyle(3, 0, 1);                // Set text style for status
  outtextxy(10, 690, const_cast<char*>(status.c_str()));
}

// Function to render text inside the editor
void renderText(const string& text, int cursorPos) {
  setfillstyle(SOLID_FILL,
               WHITE);    // Set background color to white for the text area
  bar(0, 40, 1280, 680);  // Clear the text area

  drawTitleBar();
  setcolor(BLACK);        // Black color for text
  settextstyle(1, 0, 2);  // Set text style for regular text

  int x = 10, y = 50;
  for (size_t i = 0; i < text.length(); i++) {
    if (text[i] == '\n' || x > 1260) {  // Wrap text to next line if necessary
      x = 10;
      y += 25;
    }
    if (i == cursorPos) {  // Render the cursor at the correct position
      setfillstyle(SOLID_FILL, BLACK);  // Cursor color set to black
      bar(x - 2, y, x, y + 20);         // Draw cursor
    }
    char temp[2] = {text[i], '\0'};  // Convert each character to a string
    outtextxy(x, y, temp);           // Draw character at position (x, y)
    x += 12;                         // Move x for the next character
  }

  // Ensure the cursor is visible at the end of the text if necessary
  if (cursorPos == text.length()) {
    setfillstyle(SOLID_FILL, BLACK);  // Black color for cursor
    bar(x - 2, y, x, y + 20);         // Draw cursor at the end
  }

  drawStatusBar("Press F5 to Save, F6 to Exit | Ctrl+Z to Undo");
}

// Main function
int main() {
  int width = 1280, height = 720;
  initwindow(width, height, "Notepad by Ahmed Yar");

  string text = "";
  int cursorPos = 0;
  char ch;

  while (true) {
    renderText(text, cursorPos);

    ch = getch();
    if (ch == 0 || ch == 224) ch = getch();  // Handle special keys

    switch (ch) {
      case 8:  // Backspace
        if (cursorPos > 0) {
          cursorPos--;
          Command remCommand = {Command::REMOVE, string(1, text[cursorPos])};
          commandStack.push(remCommand);
          text.erase(cursorPos, 1);
        }
        break;

      case 26:  // Ctrl+Z for Undo
        if (!commandStack.empty()) {
          Command lastCommand = commandStack.top();
          commandStack.pop();
          if (lastCommand.op == Command::ADD) {
            cursorPos--;
            text.erase(cursorPos, 1);
          } else if (lastCommand.op == Command::REMOVE) {
            text.insert(cursorPos, lastCommand.text);
            cursorPos += lastCommand.text.length();
          }
        }
        break;

      case 13:  // Enter
        text.insert(cursorPos, "\n");
        cursorPos++;
        break;

      case 27:  // ESC to exit
        closegraph();
        return 0;

      case 59: {  // F5 for Save
        ofstream file("notepad.txt");
        if (file.is_open()) {
          file << text;
          file.close();
          drawStatusBar("Text saved to notepad.txt!");
        }
        break;
      }

      case 61:  // F6 to Exit
        closegraph();
        return 0;

      default:  // Add character to text
        if (text.length() < MAX_TEXT_LENGTH) {
          text.insert(cursorPos, 1, ch);
          Command addCommand = {Command::ADD, string(1, ch)};
          commandStack.push(addCommand);
          cursorPos++;
        } else {
          drawStatusBar("Maximum text length reached!");
        }
        break;
    }
  }

  return 0;
}
