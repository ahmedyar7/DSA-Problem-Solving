#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <class T>
class Stack {
 private:
  int size;
  int top;
  T *arr;

 public:
  Stack(int size) {
    this->size = size;
    top = -1;
    arr = new T[size];
  }
  bool full() { return top == size - 1; }
  bool empty() { return top == -1; }
  void push(T value) {
    if (full()) {
      cout << "Stack is full\n";
      return;
    }
    top++;
    arr[top] = value;
    return;
  }
  T pop() {
    if (empty()) {
      cout << "Stack is empty\n";
      return T();
    }
    T value = arr[top];
    top--;
    return value;
  }
  T peek() {
    if (empty()) {
      cout << "Stack is empty\n";
      return T();
    }
    return arr[top];
  }
};

#endif

bool valid_parenthesis(char arr[]) {
  int i = 0;
  Stack<char> st(1000);
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

void reverse_string(char arr[]) {
  int len = 0;
  while (arr[len] != '\0') {
    len++;
  }
  for (int i = 0; i < len / 2; i++) {
    char temp = arr[len - i - 1];
    arr[i] = arr[len - i - 1];
    arr[len - i - 1] = temp;
  }
}

int precedence(char ch) {
  if (ch == '+' || ch == '-') return 1;
  if (ch == '/' || ch == '*') return 2;
  if (ch == '^') return 3;
  return -1;
}

bool is_operand(char ch) {
  return ((ch >= '0' && ch <= '0') || (ch >= 'a' && ch <= 'z') ||
          (ch >= 'A' && ch <= 'Z'));
}

void infix_to_postfix(char infix[], char postfix[]) {
  Stack<char> st(100);
  int i = 0, j = 0;
  while (infix[i] != '\0') {
    char ch = infix[i];
    if (is_operand(ch)) {
      postfix[j++] = ch;
    } else if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      while (!st.empty() && st.peek() != '(') {
        postfix[j++] = st.pop();
      }
      if (!st.empty()) {
        st.pop();
      }
    } else {
      while (!st.empty() && precedence(ch) <= precedence(st.peek())) {
        postfix[j++] = st.pop();
      }
      st.push(ch);
    }
    i++;
  }
  while (!st.empty()) {
    postfix[j++] = st.pop();
  }
  postfix[j] = '\0';
}