#include <iostream>
using namespace std;

class Stack {
 private:
  int capacity;
  char *arr;
  int front;

 public:
  Stack(int capacity) {
    this->capacity = capacity;
    front = -1;
    arr = new char[capacity];
  }

  bool full() { return front == capacity - 1; }
  bool empty() { return front == -1; }

  void push(char value) {
    if (full()) {
      cout << "Stack is full\n";
      return;
    }
    arr[++front] = value;
  }

  char pop() {
    if (empty()) {
      cout << "Stack is empty\n";
      return '\0';
    }
    char value = arr[front--];
    return value;
  }

  char top() {
    if (empty()) {
      cout << "Stack is empty\n";
      return '\0';
    }
    return arr[front];
  }

  bool valid_parenthesis(char exp[]) {
    int i = 0;
    Stack st(100);
    while (exp[i] != '\0') {
      char ch = exp[i];
      if (ch == '(' || ch == '{' || ch == '[') {
        st.push(ch);
      } else if (ch == ')' || ch == '}' || ch == ']') {
        if (st.empty()) {
          return false;
        }
        char peek = st.top();
        if ((ch == ')' && peek == '(') || (ch == '}' && peek == '{') ||
            (ch == ']' && peek == '['))
          st.pop();
      } else {
        return false;
      }
      i++;
    }
    return st.empty();
  }

  int prece(char exp) {
    if (exp == '+' || exp == '-') return 1;
    if (exp == '/' || exp == '*') return 2;
    if (exp == '^') return 3;
    return -1;
  }

  bool is_operand(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'z' && ch <= 'z') ||
        (ch >= '0' && ch <= '9'))
      return true;
    return false;
  }

  void reverse_str(char *exp) {
    int n = 0;
    while (exp[n] != '\0') {
      n++;
    }
    for (int i = 0; i < n / 2; i++) {
      char temp = exp[i];
      exp[i] = exp[n - i - 1];
      exp[n - i - 1] = temp;
    }
    return;
  }

  void infix_to_postfix(char *infix, char *postfix) {
    int i = 0;
    int j = 0;

    Stack st(100);

    while (infix[i] != '\0') {
      char ch = infix[i];
      if (is_operand(ch)) {
        postfix[j++] = ch;
      } else if (ch == '(') {
        st.push(ch);
      } else if (ch == ')') {
        while (!st.empty() && st.top() != '(') {
          postfix[j++] = st.pop();
        }
        if (!st.empty()) {
          st.pop();
        }
      } else {
        while (!st.empty() && prece(ch) <= prece(st.top())) {
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

  void infix_to_prefix(char *infix, char *prefix) {
    reverse_str(infix);
    int i = 0;
    while (infix[i] != '\0') {
      if (infix[i] == '(') {
        infix[i] = ')';
      } else if (infix[i] == ')') {
        infix[i] = '(';
      }
      i++;
    }

    char postfix[100];
    infix_to_postfix(infix, postfix);
    reverse_str(postfix);

    int j = 0;
    while (postfix[j] != '\0') {
      infix[j] = postfix[j];
      j++;
    }

    infix[j] = '\0';
    return;
  }

  ~Stack() { delete[] arr; }
};