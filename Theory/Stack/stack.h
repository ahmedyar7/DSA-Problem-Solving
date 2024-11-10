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

    // Opening
    if (ch == '(' || ch == '[' || ch == '{') {
      st.push(ch);
    } else if (ch == ')' || ch == ']' || ch == '}') {
      if (st.empty()) return false;
      char top = st.peek();
      if ((ch == '}' && top == '{') || (ch == ']' && top == '[') ||
          (ch == ')' && top == '(')) {
        st.pop();
      } else {
        return false;
      }
    }
    i++;
  }
  return st.empty();
}