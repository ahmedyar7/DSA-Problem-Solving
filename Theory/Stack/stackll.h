#ifndef STACKLL_H
#define STACKLL_H

#include <iostream>
using namespace std;

template <class T>
class Node {
 public:
  T data;
  Node* next;
  Node(T data) {
    this->data = data;
    next = nullptr;
  }
};

template <class T>
class Stack {
 private:
  Node<T>* top;

 public:
  Stack() { top = nullptr; }

  bool empty() { return top == nullptr; }

  void push(T value) {
    Node<T>* new_node = new Node<T>(value);
    if (empty()) {
      top = new_node;
      return;
    }
    new_node->next = top;
    top = new_node;
    return;
  }

  T pop() {
    if (empty()) {
      cout << "Stack is empty\n";
      return T();
    }
    Node<T>* temp = top;
    T value = top->data;
    top = top->next;
    delete temp;
    return value;
  }

  T peek() {
    if (empty()) {
      cout << "Stack is empty\n";
      return T();
    }
    return top->data;
  }

  void display() {
    Node<T>* temp = top;
    while (temp->next != nullptr) {
      cout << "[" << temp->data << "]-> ";
      temp = temp->next;
    }
    cout << "end\n";
  }
};

#endif

bool valid_parenthesis(char arr[]) {
  int i = 0;
  Stack<char> st;

  while (arr[i] != '\0') {
    char ch = arr[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else if (ch == ')' || ch == '}' || ch == ']') {
      if (st.empty()) {
        return false;
      }
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