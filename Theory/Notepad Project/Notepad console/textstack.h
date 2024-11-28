#ifndef TEXTSTACK_H
#define TEXTSTACK_H

#include <cstring>
#include <stdexcept>

#define MAX_STACK_SIZE 100
#define MAX_TEXT_SIZE 1000

class TextStack {
 private:
  char stack[MAX_STACK_SIZE][MAX_TEXT_SIZE][MAX_TEXT_SIZE];
  int top;

 public:
  TextStack() : top(-1) {}

  bool push(char text[MAX_TEXT_SIZE][MAX_TEXT_SIZE]) {
    if (top >= MAX_STACK_SIZE - 1) return false;
    top++;
    for (int i = 0; i < MAX_TEXT_SIZE; i++) {
      std::strcpy(stack[top][i], text[i]);
    }
    return true;
  }

  bool pop(char text[MAX_TEXT_SIZE][MAX_TEXT_SIZE]) {
    if (top < 0) return false;
    for (int i = 0; i < MAX_TEXT_SIZE; i++) {
      std::strcpy(text[i], stack[top][i]);
    }
    top--;
    return true;
  }

  bool is_empty() const { return top == -1; }
  bool is_full() const { return top == MAX_STACK_SIZE - 1; }
};

#endif