#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <class T>
class stack {
 private:
  T data;
  int top;
  int size;
  T *arr;

 public:
  stack(int size) {
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
      cout << "Stacks is empty\n";
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

  void display() {
    if (empty()) {
      cout << "Stack is empty\n";
      return;
    }
    for (int i = top; i >= 0; i--) {
      cout << "[" << arr[i] << "] -> ";
    }
    cout << "end\n";
  }
};

#endif

bool valid_parenthesis(char arr[]) {
  int i = 0;
  stack<char> st(100);
  while (arr[i] != '\0') {
    char ch = arr[i];
    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else if (ch == '}' || ch == ')' || ch == ']') {
      if (st.empty()) return false;
      char top = st.peek();
      if ((ch == '}' && top == '{') || (ch == ')' && top == '(') ||
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

int precedence(char ch) {
  if (ch == '+' || ch == '-') return 1;
  if (ch == '*' || ch == '/') return 2;
  if (ch == '^') return 3;
  return -1;
}

void reverse_string(char arr[]) {
  int n = 0;
  while (arr[n] != '\0') n++;

  for (int i = 0; i < n / 2; i++) {
    char temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
  }
  return;
}

bool is_operand(char ch) {
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
      (ch >= '0' && ch <= '9'))
    return true;
  return false;
}

void infix_to_postfix(char infix[], char postfix[]) {
  int i = 0;
  int j = 0;
  stack<char> st(100);

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
  postfix[j++] = '\0';
  return;
}

void infix_to_prefix(char infix[], char prefix[]) {
  reverse_string(infix);

  int i = 0;
  while (infix[i] != '\0') {
    char ch = infix[i];
    if (ch == '(') {
      infix[i] = ')';
    } else if (ch == ')') {
      infix[i] = '(';
    }
    i++;
  }

  char postfix[100];
  infix_to_postfix(infix, postfix);
  reverse_string(postfix);

  int j = 0;
  while (postfix[j] != '\0') {
    prefix[j] = postfix[j];
    j++;
  }

  prefix[j] = '\0';
  return;
}