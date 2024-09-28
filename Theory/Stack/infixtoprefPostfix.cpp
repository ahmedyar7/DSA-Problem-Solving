#include <iostream>
#include <string>
using namespace std;

class Stack {
 public:
  int size;
  char top;
  char *s;
};

void push(Stack *st, char value) {
  if (st->top == st->size - 1) {
    cout << "Stack Overflow\n";
    return;
  }
  st->top++;
  st->s[st->top] = value;
}

char pop(Stack *st) {
  if (st->top == -1) {
    cout << "Stack Is Empty\n";
    return '_';
  }
  int value = st->s[st->top];
  st->top--;
  return value;
}

bool is_empty(Stack st) {
  if (st.top == -1) {
    return true;
  }
  return false;
}

bool is_full(Stack st) {
  if (st.top == st.size - 1) {
    return true;
  }
  return false;
}

int is_operand(char x) {
  if (x == '+' || x == '-' || x == '/' || x == '*') {
    return 0;
  }
  return 1;
}

int pre(char x) {
  if (x == '+' || x == '-')
    return 1;
  else if (x == '*' || x == '/')
    return 2;
  else
    return 3;
}

char *convert(char infix[]) {
  Stack st;
  char postfix[] = new char((infix) + 1)
}