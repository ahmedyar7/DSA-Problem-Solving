#ifndef NOTEPAD_H
#define NOTEPAD_H

#include "textstack.h"

class Notepad {
 private:
  char text[MAX_TEXT_SIZE];  // array for text storage
  int cursor_position;       // Current cursor position
  TextStack command_stack;   // stack for undo command

  //. Helper function
  void copy_text(char destination[], char source[]);

 public:
  //.Constructor
  Notepad();

  //. Method calls
  void add_text(char new_text[]);
  void delete_text(int length);
  void undo();
  void display();
};

#endif