#include <algorithm>
#include <iostream>
using namespace std;

class Stack {
 private:
 public:
  int capacity;
  int top;
  char *arr;

  Stack(int size) {
    capacity = size;
    top = -1;
    arr = new char[capacity];
  }

  ~Stack() { delete[] arr; }

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
      cout << "Stack Overflow\n";
      return;
    }
    top++;
    arr[top] = value;
  }

  char pop() {
    if (is_empty()) {
      return '\0';
    }
    char value = arr[top];
    top--;
    return value;
  }

  char peek() {
    if (is_empty()) {
      return '\0';
    }
    return arr[top];
  }
};

bool is_operand(char ch) {
  if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') ||
      (ch >= '0' && ch <= '9'))
    return true;
  return false;
}

int precedence(char ch) {
  if (ch == '^')
    return 3;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '+' || ch == '-')
    return 1;
  return -1;
}

//. INFIX TO POSTFIX
void infix_to_postfix(string exp) {
  Stack st(exp.length());
  string ans;

  for (int i = 0; i < exp.length(); i++) {
    char ch = exp[i];
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

  cout << "Postfix Expression: " << ans << endl;
}

void reverse_str(string s) {
  for (int i = 0; i < s.length() / 2; i++) {
    char temp = s[i];
    s = s[s.length() - i - 1];
    s[i] = temp;
  }
}

//. INFIX TO PREFIX
void infix_to_prefix(string exp) {
  Stack st(exp.length());
  string ans;
  reverse_str(exp);

  // changing the parenthesis
  for (int i = 0; i < exp.length(); i++) {
    char ch = exp[i];
    if (ch == '(') {
      exp[i] = ')';
    } else if (ch == ')') {
      exp[i] = '(';
    }
  }

  for (int i = 0; i < exp.length(); i++) {
    char ch = exp[i];
    if (is_operand(ch)) {
      ans += ch;
    }

    else if (ch == '(') {
      st.push(ch);
    }

    else if (ch == ')') {
      while (!st.is_empty() && st.peek() != '(') {
        ans += st.pop();
      }
      st.pop();
    }

    else {
      while (!st.is_empty() && precedence(ch) <= precedence(st.peek())) {
        ans += st.pop();
      }
      st.push(ch);
    }
  }

  while (!st.is_empty()) {
    ans += st.pop();
  }

  reverse_str(ans);
  cout << "Prefix Expression: " << ans << endl;
}

int main() {
  string exp = "(A-B/C)*(A/K-L)";
  cout << "Infix expression: " << exp << endl;
  infix_to_prefix(exp);
  infix_to_postfix(exp);
  return 0;
}
