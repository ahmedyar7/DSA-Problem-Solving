#ifndef NOTEPAD_H
#define NOTEPAD_H

#include "textstack.h"

#define MAX_TEXT_SIZE 1000

class Notepad {
 private:
  char text[MAX_TEXT_SIZE][MAX_TEXT_SIZE];
  int cursor_row, cursor_col;
  TextStack command_stack;

 public:
  Notepad();  // Keep declaration, remove implementation
  void add_text(const char* new_text);
  void delete_text();
  void move_cursor_up();
  void move_cursor_down();
  void move_cursor_left();
  void move_cursor_right();
  void display();
  void undo();
  void save_to_file(const char* filename);
  void load_from_file(const char* filename);
};

#endif