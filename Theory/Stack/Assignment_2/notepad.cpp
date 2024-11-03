#include "notepad.h"

#include <iostream>
using namespace std;

//. Helper Function
void Notepad::copy_text(char destination[], char source[]) {
  int i = 0;
  while (source[i] != '\0' && i < MAX_TEXT_SIZE - 1) {
    destination[i] = source[i];
    i++;
  }
  destination[i] = '\0';
}

//. Constructor
Notepad::Notepad() {
  cursor_position = 0;  // point towards current position
  text[0] = '\0';       // Initialize an empty string
}

//. Adding the text
void Notepad::add_text(char new_text[]) {
  int new_text_length = 0;

  while (new_text[new_text_length] != '\0') {
    new_text_length++;
  }

  // Adding text to current position in the 'text'
  for (int i = 0; i < new_text_length && cursor_position < MAX_TEXT_SIZE - 1;
       i++) {
    text[cursor_position] = new_text[i];
    cursor_position++;
  }
  text[cursor_position] = '\0';  // Termination of the string

  // Saving into the stack
  Command cmd;
  cmd.op = Command::ADD;
  copy_text(cmd.text, new_text);
  command_stack.push(cmd);
}

// . Deleting the text
void Notepad::delete_text(int length) {
  if (length > cursor_position) {
    cout << "Invalid Delete length\n";
    return;
  }

  Command cmd;
  cmd.op = Command::DELETE;
  for (int i = 0; i < length; i++) {
    // cmd.text[i] will get the text that we want to delete
    cmd.text[i] = text[cursor_position - length + i];
  }
  cmd.text[length] = '\0';  // This is the delimiter operator
  command_stack.push(cmd);

  cursor_position -= length;  // adjusting the cursor position
  text[cursor_position] = '\0';
}

void Notepad::undo() {
  if (command_stack.is_empty()) {
    cout << "Nothing to undo the stack is empty\n";
    return;
  }

  Command last_command = command_stack.top();
  command_stack.pop();

  if (last_command.op == Command::ADD) {
    int len = 0;
    while (last_command.text[len] != '\0') {
      len++;
    }
    cursor_position -= len;
    text[cursor_position] = '\0';
  } else if (last_command.op == Command::DELETE) {
    int len = 0;

    while (last_command.text[len] != '\0') {
      len++;
    }
    for (int i = 0; i < len && cursor_position < MAX_TEXT_SIZE - 1; i++) {
      text[cursor_position] = last_command.text[i];
      cursor_position++;
    }
    text[cursor_position] = '\0';  // Null-Terminate
  }
}

void Notepad::display() {
  cout << text << endl;
  for (int i = 0; i < cursor_position; i++) {
    cout << " ";
  }
  cout << "^ " << endl;
}
