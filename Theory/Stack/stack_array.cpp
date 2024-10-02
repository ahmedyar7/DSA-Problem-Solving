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

  bool is_full() {
    if (top == capacity - 1) {
      return true;
    }
    return false;
  }

  bool is_empty() {
    if (top == -1) {
      return true;
    }
    return false;
  }

  void push(char value) {
    if (is_full()) {
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
  if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
      (ch >= '0' && ch <= '9')) {
    return true;
  }
  return false;
}

void reverse_str(string s) {
  int n = s.length();
  for (int i = 0; i < n / 2; i++) {
    char temp = s[n - i - 1];
    s = s[n - i - 1];
    s[n - i - 1] = temp;
  }
}

int precedence(char ch) {
  if (ch == '+' || ch == '-')
    return 1;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '^')
    return 3;
  return -1;
}

string infix_to_postfix(string s) {
  Stack st(s.length());
  string ans;

  for (int i = 0; i < s.length(); i++) {
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

  return ans;
}

string infix_to_prefix(string s) {
  Stack st(s.length());
  string ans;

  reverse_str(s);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(')
      s[i] = ')';
    else if (s[i] == ')')
      s[i] == '(';
  }

  ans = infix_to_postfix(s);
  reverse_str(ans);

  return ans;
}

bool valid_parenthesis(string s) {
  Stack st(s.length());

  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];

    if (ch == '(' || ch == '{' || ch == '[') {
      st.push(ch);
    } else if (ch == ')' || ch == ']' || ch == '}') {
      if (st.is_empty())
        return false;

      else if (st.peek() == '(' || st.peek() == '{' || st.peek() == '[')
        st.pop();
    }
  }

  return st.is_empty();
}

int main() {
  string exp = "{{[(A-B/C)]}}*((A/K-L))";
  cout << "Infix expression: " << exp << endl;

  cout << "Infix Expression: ";
  cout << infix_to_prefix(exp);

  cout << "\nPostfix Expression: ";
  cout << infix_to_postfix(exp);

  cout << "\n Is valid " << valid_parenthesis(exp);
  return 0;
}
