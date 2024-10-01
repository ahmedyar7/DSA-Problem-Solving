#include <algorithm>
#include <iostream>
using namespace std;

class Stack {
 private:
 public:
  int capacity;
  int top;
  char* arr;

  Stack(int size) {
    capacity = size;
    top = -1;
    arr = new char[capacity];
  }
  ~Stack() { delete[] arr; }

  // Methods
  bool is_empty() {
    if (top == -1) return true;
    return false;
  }

  bool is_full() {
    if (top == capacity - 1) return true;
    return false;
  }

  void push(char value) {
    if (is_full()) {
      cout << "Stackover flow\n";
      return;
    }
    top++;
    arr[top] = value;
  }

  char pop() {
    if (is_empty()) {
      cout << "Stackunderflow\n";
      return '\0';
    }
    return arr[top--];
  }

  char peek() {
    if (is_empty()) {
      return '\0';
    }
    return arr[top];
  }
};

int precedence(char ch) {
  if (ch == '+' || ch == '-')
    return 1;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '^')
    return 3;
  return -1;
}

bool is_operand(char ch) {
  if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') ||
      (ch >= '0' && ch <= '9')) {
    return true;
  }
  return false;
}

void infix_to_postfix(char* s) {
  int len = 0;
  int i = 0;
  while (s[i] != '\0') {
    len++;
    i++;
  }
  Stack st(len);
  string ans;

  for (int i = 0; i < len; i++) {
    char ch = s[i];
    if (is_operand(ch)) {
      ans += ch;
    } else if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      while (!st.is_empty() && st.peek() != '(') {
        ans += st.pop();
      }
      st.pop();

    } else {
      while (!st.is_empty() && precedence(ch) <= precedence(st.peek())) {
        ans += st.pop();
      }
      st.push(ch);
    }
  }
  while (!st.is_empty()) {
    ans += st.pop();
  }
  reverse(ans.begin(), ans.end());

  cout << ans;
}
int main() {
  char* exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infix_to_postfix(exp);
  return 0;
}
