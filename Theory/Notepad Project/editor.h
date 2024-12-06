// editor.h
#ifndef EDITOR_H
#define EDITOR_H

#include <fstream>
#include <string>

#include "configurations.cpp"
#include "stack.h"
#include "ui_components.h"

class Editor {
 private:
  std::string text;
  int cursorPos;
  int cursorLine;
  int cursorCol;
  UIManager& ui;
  stack<Command> commandStack;
  static const int MAX_TEXT_LENGTH = 5000;

  void updateCursorPosition() {
    cursorLine = 1;
    cursorCol = 1;
    for (int i = 0; i < cursorPos; i++) {
      if (text[i] == '\n') {
        cursorLine++;
        cursorCol = 1;
      } else {
        cursorCol++;
      }
    }
  }

 public:
  Editor(UIManager& uiManager)
      : ui(uiManager), cursorPos(0), cursorLine(1), cursorCol(1) {}

  void renderText() {
    // Don't clear the entire screen; only clear the text area if necessary
    // ui.clearTextArea(); // Comment out this line if it erases the entire
    // background

    // Draw the title bar and line numbers as needed
    ui.drawTitleBar();
    ui.drawLineNumbers(1, 100);

    int x = 50, y = 50, lineHeight = 25;
    settextstyle(8, HORIZ_DIR, 1);  // Text styling

    // Start drawing the text
    for (size_t i = 0; i < text.length(); i++) {
      // Check for newlines and handle text wrapping
      if (text[i] == '\n' || x > 1240) {
        x = 50;
        y += lineHeight;
        if (text[i] == '\n') continue;  // Skip newline character itself
      }

      char temp[2] = {text[i], '\0'};  // Convert char to string
      setcolor(Theme::TextColor());    // Set text color (ensure it's visible)
      outtextxy(x, y, temp);           // Draw text
      x += 12;                         // Move to next character position
    }

    // Draw the cursor if necessary
    ui.drawCursor(x, y, cursorPos == text.length());

    // Update the status bar
    ui.drawStatusBar("Press F5 to Save, F6 to Exit | Ctrl+Z to Undo",
                     cursorLine, cursorCol);
  }

  void handleInput(char ch) {
    switch (ch) {
      case 8:  // Backspace
        if (cursorPos > 0) {
          cursorPos--;
          Command remCommand = {Command::REMOVE,
                                std::string(1, text[cursorPos])};
          commandStack.push(remCommand);
          text.erase(cursorPos, 1);
        }
        break;

      case 26:  // Ctrl+Z
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

      default:
        if (text.length() < MAX_TEXT_LENGTH && ch >= 32 && ch <= 126) {
          text.insert(cursorPos, 1, ch);
          Command addCommand = {Command::ADD, std::string(1, ch)};
          commandStack.push(addCommand);
          cursorPos++;
        }
    }

    updateCursorPosition();  // Update cursor position after each input
  }

  void saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
      file << text;
      file.close();
      ui.drawStatusBar("File saved successfully!");
    } else {
      ui.drawStatusBar("Error saving file!");
    }
  }

  std::string getText() const { return text; }
};

#endif