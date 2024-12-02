// editor.h
#ifndef EDITOR_H
#define EDITOR_H

#include <fstream>
#include <string>

#include "configurations.cpp"  // Ensure the Command definition is included
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
    ui.clearTextArea();
    ui.drawTitleBar();
    ui.drawLineNumbers(1, 100);

    int x = 50, y = 50, lineHeight = 25;
    settextstyle(8, HORIZ_DIR, 1);  // Consistent text styling

    for (size_t i = 0; i < text.length(); i++) {
      if (text[i] == '\n' || x > 1240) {
        x = 50;
        y += lineHeight;
        if (text[i] == '\n') continue;
      }

      char temp[2] = {text[i], '\0'};
      setcolor(Theme::TextColor());
      outtextxy(x, y, temp);
      x += 12;
    }

    ui.drawCursor(x, y, cursorPos == text.length());
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
    updateCursorPosition();
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