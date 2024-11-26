#ifndef TEXTSTACK_H
#define TEXTSTACK_H

#include <iostream>
using namespace std;

const int MAX_TEXT_SIZE = 1000;
const int MAX_STACK_SIZE = 100;

struct Command {
  enum Operation { ADD, DELETE };
  Operation op;
  char text[MAX_TEXT_SIZE];  // Array for command text;
};

class TextStack {
 private:
  // stack that will hold the commands regarding
  // the text
  Command stack[MAX_STACK_SIZE];

  int top_index;  // This will keep track of the current top position

 public:
  TextStack() { top_index = -1; }

  void push(Command cmd) {
    if (top_index == MAX_TEXT_SIZE - 1) {
      cout << "The Stack is full\n";
      return;
    } else {
      top_index++;
      stack[top_index] = cmd;
      return;
    }
  }

  bool is_empty() { return top_index == -1; }

  Command top() { return stack[top_index]; }
  void pop() {
    if (top_index >= 0) {
      top_index--;
    }
  }
};

#endif  // TEXTSTACK_H