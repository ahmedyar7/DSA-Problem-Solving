#ifndef STACK_H
#define STACK_H

#include <iostream >
using namespace std;

class Stack {
 private:
  int size;
  int top;
  int *arr;

 public:
  Stack(int size) {
    this->size = size;
    top = -1;
    arr = new int[size];
  }

  bool empty() { return top == -1; }

  bool full() { return top == size - 1; }

  void push(int value) {
    if (full()) {
      cout << "Stack is full\n";
      return;
    }
    top++;
    arr[top] = value;
    return;
  }

  int pop() {
    if (empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    int value = arr[top];
    top--;
    return value;
  }

  int peek() {
    if (empty()) {
      cout << "Stack is empty\n";
      return -1;
    }
    return arr[top];
  }

  bool valid_parenthesis(char arr[]) {
    int len = 0;
    while (arr[len] != '\0') {
      len++;
    }

    Stack st(len);

    int i = 0;
    while (arr[i] != '\0') {
      char ch = arr[i];

      if (ch == '(' || ch == '{' || ch == '[') {
        st.push(ch);
      } else if (ch == ')' || ch == '}' || ch == ']') {
        if (st.empty()) return false;

        char top = st.peek();
        if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
            (ch == ']' && top == '[')) {
          st.pop();
        } else {
          return false;
        }
      }
      i++;
    }

    return st.empty();
  }
};

#endif