#include "notepad.h"

#include <cstring>
#include <fstream>
#include <iostream>

#include "textstack.h"
using namespace std;

Notepad::Notepad() : cursor_row(0), cursor_col(0) {
  for (int i = 0; i < MAX_TEXT_SIZE; i++) {
    text[i][0] = '\0';
  }
}

void Notepad::add_text(const char* new_text) {
  command_stack.push(text);  // Save current state for undo
  int i = 0;
  while (new_text[i] != '\0' && cursor_col < MAX_TEXT_SIZE - 1) {
    text[cursor_row][cursor_col++] = new_text[i++];
  }
  text[cursor_row][cursor_col] = '\0';
}

void Notepad::delete_text() {
  command_stack.push(text);  // Save current state for undo
  if (cursor_col > 0) {
    cursor_col--;
    text[cursor_row][cursor_col] = '\0';
  }
}

void Notepad::move_cursor_up() {
  if (cursor_row > 0) {
    cursor_row--;
    cursor_col = strlen(text[cursor_row]);
  }
}

void Notepad::move_cursor_down() {
  if (cursor_row < MAX_TEXT_SIZE - 1 && text[cursor_row + 1][0] != '\0') {
    cursor_row++;
    cursor_col = strlen(text[cursor_row]);
  }
}

void Notepad::move_cursor_left() {
  if (cursor_col > 0) {
    cursor_col--;
  } else if (cursor_row > 0) {
    move_cursor_up();
    cursor_col = strlen(text[cursor_row]);
  }
}

void Notepad::move_cursor_right() {
  // Ensure cursor_col is within the bounds of the current line's length
  if (cursor_col < strlen(text[cursor_row])) {
    cursor_col++;  // Move cursor right within the current row
  }
  // Check if we are at the end of the current row and if the next row is not
  // empty
  else if (cursor_row < MAX_TEXT_SIZE - 1 && text[cursor_row + 1][0] != '\0') {
    move_cursor_down();  // Move down to the next row
    cursor_col = 0;      // Reset cursor to the beginning of the new row
  }
}

void Notepad::display() {
  system("clear");  // Use "cls" for Windows
  for (int i = 0; i <= cursor_row; i++) {
    cout << text[i] << endl;
  }
  for (int i = 0; i < cursor_col; i++) cout << " ";
  cout << "^" << endl;  // Cursor position indicator
}

void Notepad::undo() {
  if (!command_stack.pop(text)) {
    cout << "Nothing to undo!" << endl;
  } else {
    cursor_row = 0;
    cursor_col = strlen(text[cursor_row]);
    while (cursor_row < MAX_TEXT_SIZE - 1 && text[cursor_row + 1][0] != '\0') {
      cursor_row++;
    }
    cursor_col = strlen(text[cursor_row]);
  }
}

void Notepad::save_to_file(const char* filename) {
  ofstream file(filename);
  if (file) {
    for (int i = 0; i < MAX_TEXT_SIZE && text[i][0] != '\0'; i++) {
      file << text[i] << endl;
    }
  }
  file.close();
}

void Notepad::load_from_file(const char* filename) {
  ifstream file(filename);
  if (file) {
    cursor_row = 0;
    while (file.getline(text[cursor_row], MAX_TEXT_SIZE)) {
      cursor_row++;
    }
    cursor_col = strlen(text[cursor_row - 1]);
  }
  file.close();
}
